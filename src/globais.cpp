#include "globais.hpp"
#include "infra/dao/em_memoria/semeadores/plantas.hpp"

using Identidade::Entidades::Usuario;
using Terrenos::Entidades::Planta;

namespace Daos::EmMemoria::Globais
{

std::shared_ptr<std::mutex> plantasDbMutex = std::make_shared<std::mutex>();

std::shared_ptr<std::vector<std::shared_ptr<Terrenos::Entidades::Planta>>>
    plantasDb = std::make_shared<std::vector<std::shared_ptr<Planta>>>();

std::shared_ptr<std::mutex> usuariosDbMutex = std::make_shared<std::mutex>();
std::shared_ptr<std::vector<std::shared_ptr<Identidade::Entidades::Usuario>>>
    usuariosDb = std::make_shared<std::vector<std::shared_ptr<Usuario>>>();

void popular()
{
    std::scoped_lock lock(*plantasDbMutex);

    Daos::EmMemoria::Semeadores::preenchaPlantas(*plantasDb);
}

} // namespace Daos::EmMemoria::Globais
