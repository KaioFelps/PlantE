#pragma once

#include "dominio/terrenos/entidades/terreno.hpp"

#include <memory>
#include <optional>
#include <vector>

namespace Terrenos::Dao
{

class TerrenoDao
{
  public:
    virtual std::optional<std::shared_ptr<Entidades::Terreno>>
    encontre(const std::string& idPlanta) = 0;
};

} // namespace Terrenos::Dao

