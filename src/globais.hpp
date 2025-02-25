#pragma once

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

void popular();

} // namespace Daos::EmMemoria::Globais
