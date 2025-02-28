#include "gerente_de_denuncias.hpp"
#include "dominio/identidade/dao/usuarios_dao.hpp"
#include "dominio/moderacao/dao/denuncias_dao.hpp"
#include <algorithm>
#include <stdexcept>

namespace Moderacao::Gerentes
{

GerenteDeDenuncias::GerenteDeDenuncias(Roteador::Contexto& contexto_)
    : contexto(contexto_)
{
}

std::vector<Moderacao::Entidades::Denuncia>
GerenteDeDenuncias::listeDenuncias() const
{
    using Moderacao::Dao::DenunciasDao;
    using Moderacao::Entidades::Denuncia;

    auto denunciasDao = this->contexto.obtenha<DenunciasDao>();
    auto denuncias = denunciasDao->liste();
    std::vector<Denuncia> denunciasCopiadas;

    return denunciasCopiadas;
}

std::optional<Moderacao::Entidades::Denuncia>
GerenteDeDenuncias::obtenhaDenuncia(std::string& idDenuncia) const
{
    using Moderacao::Dao::DenunciasDao;
    using Moderacao::Entidades::Denuncia;

    auto denunciasDao = this->contexto.obtenha<DenunciasDao>();
    auto denuncia = denunciasDao->encontre(idDenuncia);

    if (!denuncia)
    {
        return std::nullopt;
    }

    return *denuncia;
}

void GerenteDeDenuncias::denuncie(std::string idRelator,
                                  std::string idDenunciavel,
                                  Moderacao::Enums::TipoDoDenunciavel tipo,
                                  Moderacao::Enums::MotivoDaDenuncia motivo,
                                  std::optional<std::string> detalhes)
{
    using Moderacao::Dao::DenunciasDao;
    using Moderacao::Entidades::Denuncia;

    auto denunciasDao = this->contexto.obtenha<DenunciasDao>();
}

void GerenteDeDenuncias::marqueComoInvestigando(const std::string& idModerador,
                                                const std::string& idDenuncia)
{
    using Identidade::Dao::UsuariosDao;
    using Identidade::Entidades::Usuario;
    using Moderacao::Dao::DenunciasDao;
    using Moderacao::Entidades::Denuncia;
    using Moderacao::Enums::EstadoDaDenuncia;

    auto denunciasDao = this->contexto.obtenha<DenunciasDao>();
    auto denunciaEncontrada = denunciasDao->encontre(idDenuncia);

    if (!denunciaEncontrada)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar a denúncia o com id \"" + idDenuncia +
            "\".");

        return;
    }

    auto usuariosDao = this->contexto.obtenha<UsuariosDao>();
    auto moderadorEncontrado = usuariosDao->encontre(idModerador);

    if (!moderadorEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar o moderador com id \"" + idModerador +
            "\".");

        return;
    }

    auto moderador = std::dynamic_pointer_cast<Usuario>(*moderadorEncontrado);
    auto denuncia = *denunciaEncontrada;

    denuncia.coloqueModeradorInvestigador(std::move(moderador));
    denuncia.coloqueEstado(EstadoDaDenuncia::ANALISE);

    denunciasDao->salve(std::move(denuncia));
}

void GerenteDeDenuncias::marqueComoResolvida(const std::string& idModerador,
                                             const std::string& idDenuncia)
{
    using Identidade::Dao::UsuariosDao;
    using Identidade::Entidades::Usuario;
    using Moderacao::Dao::DenunciasDao;
    using Moderacao::Entidades::Denuncia;
    using Moderacao::Enums::EstadoDaDenuncia;

    auto denunciasDao = this->contexto.obtenha<DenunciasDao>();
    auto denunciaEncontrado = denunciasDao->encontre(idDenuncia);

    if (!denunciaEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar a denúncia o com id \"" + idDenuncia +
            "\".");

        return;
    }

    auto usuariosDao = this->contexto.obtenha<UsuariosDao>();
    auto moderadorEncontrado = usuariosDao->encontre(idModerador);

    if (!moderadorEncontrado)
    {
        throw std::invalid_argument(
            "Não foi possível encontrar o moderador com id \"" + idModerador +
            "\".");

        return;
    }

    auto moderador = std::dynamic_pointer_cast<Usuario>(*moderadorEncontrado);

    auto denuncia = *denunciaEncontrado;
    denuncia.coloqueEstado(EstadoDaDenuncia::RESOLVIDO);
    denuncia.coloqueModeradorResolutor(moderador);

    denunciasDao->salve(std::move(denuncia));
}

} // namespace Moderacao::Gerentes
