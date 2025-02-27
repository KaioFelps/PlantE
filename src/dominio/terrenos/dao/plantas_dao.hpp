#pragma once

#include "dominio/terrenos/entidades/planta.hpp"
#include "dominio/terrenos/entidades/solo.hpp"
#include <memory>
#include <optional>
#include <vector>

namespace Terrenos::Dao
{

class PlantasDao
{
  public:
    virtual std::vector<std::shared_ptr<Entidades::Planta>>
    encontrePlantasCorrespondentes(const Entidades::Solo& solo) = 0;

    virtual std::optional<std::shared_ptr<Entidades::Planta>>
    encontre(const std::string& idPlanta) = 0;
};

} // namespace Terrenos::Dao
