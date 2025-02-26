#pragma once

#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/terrenos/entidades/planta.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace Daos::EmMemoria::Globais
{

extern std::shared_ptr<std::mutex> plantasDbMutex;
extern std::shared_ptr<
    std::vector<std::shared_ptr<Terrenos::Entidades::Planta>>>
    plantasDb;

extern std::shared_ptr<std::mutex> usuariosDbMutex;
extern std::shared_ptr<
    std::vector<std::shared_ptr<Identidade::Entidades::Usuario>>>
    usuariosDb;

void popular();

} // namespace Daos::EmMemoria::Globais
