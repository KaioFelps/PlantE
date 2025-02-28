#include "terrenos_dao_em_memoria.hpp"
#include "globais.hpp"
#include <algorithm>

namespace Daos::EmMemoria
{

std::optional<Terrenos::Entidades::Terreno>
TerrenosDaoEmMemoria::encontre(const std::string& idTerreno) const
{
    using Globais::terrenosDb;
    using Globais::terrenosDbMutex;
    using Terrenos::Entidades::Terreno;

    std::lock_guard<std::mutex> lock(*terrenosDbMutex);

    auto terrenoEncontrado =
        std::find_if(terrenosDb->begin(),
                     terrenosDb->end(),
                     [ &idTerreno ](const std::shared_ptr<Terreno>& terreno)
                     { return terreno->obtenhaId() == idTerreno; });

    bool terrenoExiste = terrenoEncontrado != terrenosDb->end();
    if (!terrenoExiste)
    {
        return std::nullopt;
    }

    return **terrenoEncontrado;
}

std::unique_ptr<Terrenos::Entidades::Solo>
TerrenosDaoEmMemoria::crieSolo(double acidez,
                               unsigned int indiceDeMinerais,
                               unsigned int indiceDeSalinidade,
                               unsigned int indiceDeArgila,
                               unsigned int indiceDeSilte,
                               unsigned int indiceDeAreia,
                               double cargaEletrica)
{
    using Terrenos::Entidades::Solo;
    auto solo = std::make_unique<Solo>(acidez,
                                       indiceDeMinerais,
                                       indiceDeSalinidade,
                                       indiceDeArgila,
                                       indiceDeAreia,
                                       indiceDeSilte,
                                       cargaEletrica);

    return solo;
}

void TerrenosDaoEmMemoria::salve(
    std::shared_ptr<Terrenos::Entidades::Terreno> terreno)
{
    using Globais::terrenosDb;
    using Globais::terrenosDbMutex;
    using Terrenos::Entidades::Terreno;

    auto idTerreno = terreno->obtenhaId();
    std::lock_guard<std::mutex> lock(*terrenosDbMutex);

    auto terrenoEncontrado =
        std::find_if(terrenosDb->begin(),
                     terrenosDb->end(),
                     [ &idTerreno ](const std::shared_ptr<Terreno>& terreno_)
                     { return terreno_->obtenhaId() == idTerreno; });

    bool terrenoExiste = terrenoEncontrado != terrenosDb->end();

    if (terrenoExiste)
    {
        (*terrenoEncontrado) = terreno;
        return;
    }

    terrenosDb->push_back(terreno);
}

std::vector<Terrenos::Entidades::Terreno>
TerrenosDaoEmMemoria::listeTodosDoUsuario(
    const Identidade::Entidades::Usuario& usuario) const
{
    using Globais::terrenosDb;
    using Globais::terrenosDbMutex;
    using Identidade::Entidades::Usuario;
    using Terrenos::Entidades::Terreno;

    auto terrenosDoUsuario = std::vector<Terreno>();
    auto idUsuario = usuario.obtenhaId();
    std::lock_guard<std::mutex> lock(*terrenosDbMutex);

    std::for_each(
        terrenosDb->begin(),
        terrenosDb->end(),
        [ &idUsuario,
          &terrenosDoUsuario ](const std::shared_ptr<Terreno>& terreno)
        {
            if (terreno->obtenhaProprietario()->obtenhaId() == idUsuario)
            {
                terrenosDoUsuario.push_back(*terreno);
            }
        });

    return terrenosDoUsuario;
}

} // namespace Daos::EmMemoria
