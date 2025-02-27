#include "gerente_de_terrenos.hpp"
#include "dominio/identidade/dao/usuarios_dao.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"
#include "dominio/terrenos/dao/terrenos_dao.hpp"
#include <algorithm>
#include <stdexcept>

namespace Terrenos::Gerentes
{

GerenteDeTerrenos::GerenteDeTerrenos(
    std::shared_ptr<Roteador::Contexto> contexto_)
    : contexto(std::move(contexto_))
{
}

std::vector<Entidades::Planta>
GerenteDeTerrenos::obtenhaSugestoes(const std::string& idTerreno) const
{
    using Terrenos::Dao::PlantasDao;
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Entidades::Planta;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();
    auto plantasDao = this->contexto->obtenha<PlantasDao>();

    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);

    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    auto terreno = *terrenoEncontrado;
    const auto& solo = terreno->obtenhaSolo();

    if (!solo.has_value())
    {
        throw std::invalid_argument("O terreno deve ter informações do seu "
                                    "solo registrado para prosseguir.");
    }

    auto plantas = plantasDao->encontrePlantasCorrespondentes(**solo);
    return plantas;
}

std::vector<Entidades::Terreno>
GerenteDeTerrenos::listeTerrenos(const std::string& idUsuario) const
{
    using Identidade::Dao::UsuariosDao;
    using Identidade::Entidades::Usuario;
    using Terrenos::Dao::TerrenosDao;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();
    auto usuariosDao = this->contexto->obtenha<UsuariosDao>();

    auto usuarioEncontrado = usuariosDao->encontre(idUsuario);

    if (!usuarioEncontrado)
    {
        throw std::invalid_argument("Nâo existe um usuário com id \"" +
                                    idUsuario + "\".");
    }

    auto usuario = std::dynamic_pointer_cast<Usuario>(*usuarioEncontrado);
    auto terrenos = terrenosDao->listeTodosDoUsuario(*usuario);

    return terrenos;
}

void GerenteDeTerrenos::recebaDadosDoSolo(std::string idTerreno,
                                          float acidez,
                                          unsigned char índiceDeMinerais,
                                          unsigned char índiceDeSalinidade,
                                          unsigned char índiceDeArgila,
                                          unsigned char índiceDeSilte,
                                          unsigned char cargaElétrica)
{
}

} // namespace Terrenos::Gerentes
