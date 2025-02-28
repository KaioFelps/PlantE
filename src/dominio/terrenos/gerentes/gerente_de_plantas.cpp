#include "gerente_de_plantas.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"

namespace Terrenos::Gerentes
{

std::vector<Entidades::Planta> GerenteDePlantacoes::listePlantas() const
{
    using Dao::PlantasDao;
    using Entidades::Planta;

    auto plantasDao = this->contexto->obtenha<PlantasDao>();
    auto plantas = plantasDao->liste();

    return plantas;
}

} // namespace Terrenos::Gerentes
