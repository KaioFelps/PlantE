#pragma once

#include "dominio/terrenos/entidades/planta.hpp"
#include <memory>
#include <vector>

namespace Daos::EmMemoria::Semeadores
{

void preenchaPlantas(
    std::vector<std::shared_ptr<Terrenos::Entidades::Planta>>& plantas);
}
