#include "gerente_de_terrenos.hpp"
#include "dominio/identidade/dao/usuarios_dao.hpp"
#include "dominio/terrenos/dao/plantacoes_dao.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"
#include "dominio/terrenos/dao/terrenos_dao.hpp"
#include "dominio/terrenos/dvo/terrenos_dvo.hpp"
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
    const auto& solo = terreno.obtenhaSolo();

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
                                          unsigned char indiceDeMinerais,
                                          unsigned char indiceDeSalinidade,
                                          unsigned char indiceDeArgila,
                                          unsigned char indiceDeSilte,
                                          unsigned char cargaEletrica)
{
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Dvo::TerrenosDvo;
    using Terrenos::Entidades::Solo;
    using Terrenos::Entidades::Terreno;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();

    auto solo = terrenosDao->crieSolo(acidez,
                                      indiceDeMinerais,
                                      indiceDeSalinidade,
                                      indiceDeArgila,
                                      indiceDeSilte,
                                      indiceDeArgila,
                                      cargaEletrica);

    TerrenosDvo::valideSolo(*solo); // deixa o erro "borbulhar"

    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);

    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    auto terreno = std::make_shared<Terreno>(*terrenoEncontrado);
    terreno->atualizeSolo(std::move(solo));
    terrenosDao->salve(terreno);
}

void GerenteDeTerrenos::finalizePlantacao(const std::string& idTerreno)
{
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Entidades::Terreno;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();
    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);

    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    // Embora seja uma nova instância de `Terreno`, contém uma referência para a
    // `Plantacao` real, fazendo com que as alterações sejam, de fato,
    // realizadas na instância de `Plantacao` armazenada na memória
    auto terreno = std::make_shared<Terreno>(*terrenoEncontrado);
    terreno->finalizePlantacaoAtiva();
    terrenosDao->salve(terreno);
}

void GerenteDeTerrenos::desistaDaPlantacao(const std::string& idTerreno)
{
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Entidades::Terreno;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();
    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);

    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    // Embora seja uma nova instância de `Terreno`, contém uma referência para a
    // `Plantacao` real, fazendo com que as alterações sejam, de fato,
    // realizadas na instância de `Plantacao` armazenada na memória
    auto terreno = std::make_shared<Terreno>(*terrenoEncontrado);
    terreno->desistaDaPlantacaoAtiva();
    terrenosDao->salve(terreno);
}

void GerenteDeTerrenos::adicionePlantacao(const std::string& idTerreno,
                                          const std::string& idPlanta)
{
    using Terrenos::Dao::PlantacoesDao;
    using Terrenos::Dao::PlantasDao;
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Entidades::Terreno;

    auto plantasDao = this->contexto->obtenha<PlantasDao>();
    auto plantacoesDao = this->contexto->obtenha<PlantacoesDao>();
    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();

    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);
    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    auto plantaEncontrada = plantasDao->encontre(idPlanta);
    if (!plantaEncontrada)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar uma planta com id\"" + idPlanta +
            "\".");
    }

    auto planta = *plantaEncontrada;
    auto terreno = std::make_shared<Terreno>(*terrenoEncontrado);

    auto plantacao = plantacoesDao->crie(planta, terreno);

    terreno->finalizePlantacaoAtiva();
    terrenosDao->salve(terreno);
}

std::optional<Entidades::Plantacao>
GerenteDeTerrenos::obtenhaPlantacao(const std::string& idTerreno) const
{
    using Terrenos::Dao::TerrenosDao;
    using Terrenos::Entidades::Terreno;

    auto terrenosDao = this->contexto->obtenha<TerrenosDao>();

    auto terrenoEncontrado = terrenosDao->encontre(idTerreno);
    if (!terrenoEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar um terreno com id \"" + idTerreno +
            "\".");
    }

    auto terreno = *terrenoEncontrado;
    auto plantacaoAtiva = terreno.obtenhaPlantacaoAtiva();

    if (!plantacaoAtiva)
    {
        return std::nullopt;
    }

    return **plantacaoAtiva;
}

} // namespace Terrenos::Gerentes
