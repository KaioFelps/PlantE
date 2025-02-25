#include "globais.hpp"
#include "infra/dao/em_memoria/semeadores/plantas.hpp"

using Terrenos::Entidades::Planta;

namespace Daos::EmMemoria::Globais
{

std::shared_ptr<std::mutex> plantasDbMutex = std::make_shared<std::mutex>();

std::shared_ptr<std::vector<std::shared_ptr<Terrenos::Entidades::Planta>>>
    plantasDb = std::make_shared<std::vector<std::shared_ptr<Planta>>>();

void popular()
{
    std::scoped_lock lock(*plantasDbMutex);

    Daos::EmMemoria::Semeadores::preenchaPlantas(*plantasDb);
}

} // namespace Daos::EmMemoria::Globais
