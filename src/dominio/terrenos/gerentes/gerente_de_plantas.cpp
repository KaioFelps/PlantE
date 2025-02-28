#include "gerente_de_plantas.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"

namespace Terrenos::Gerentes
{

GerenteDePlantacoes::GerenteDePlantacoes(Roteador::Contexto& contexto_)
    : contexto(contexto_)
{
}

std::vector<Entidades::Planta> GerenteDePlantacoes::listePlantas() const
{
    using Dao::PlantasDao;
    using Entidades::Planta;

    auto plantasDao = this->contexto.obtenha<PlantasDao>();
    auto plantas = plantasDao->liste();

    return plantas;
}

} // namespace Terrenos::Gerentes
