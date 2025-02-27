#include "globais.hpp"
#include "infra/dao/em_memoria/semeadores/plantas.hpp"

using Identidade::Entidades::Usuario;
using Moderacao::Entidades::Denuncia;
using Terrenos::Entidades::Planta;

namespace Daos::EmMemoria::Globais
{

std::shared_ptr<std::mutex> plantasDbMutex = std::make_shared<std::mutex>();

DbEmMemoria<Planta> plantasDb = instanciarArmazenamento<Planta>();

std::shared_ptr<std::mutex> usuariosDbMutex = std::make_shared<std::mutex>();
DbEmMemoria<Usuario> usuariosDb = instanciarArmazenamento<Usuario>();

std::shared_ptr<std::mutex> denunciasDbMutex = std::make_shared<std::mutex>();
DbEmMemoria<Denuncia> denunciasDb = instanciarArmazenamento<Denuncia>();

void popular()
{
    std::scoped_lock lock(*plantasDbMutex);

    Daos::EmMemoria::Semeadores::preenchaPlantas(*plantasDb);
}

} // namespace Daos::EmMemoria::Globais
