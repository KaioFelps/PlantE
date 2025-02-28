#pragma once

#include "dominio/terrenos/entidades/plantacao.hpp"
#include <optional>

namespace Terrenos::Dao
{

class PlantacoesDao
{
  public:
    virtual std::optional<Entidades::Plantacao>
    encontre(const std::string& idPlantacao) = 0;

    virtual std::shared_ptr<Entidades::Plantacao>
    crie(std::shared_ptr<Entidades::Planta> planta,
         std::shared_ptr<Entidades::Terreno> terreno) = 0;

    virtual void salve(Entidades::Plantacao plantacao) = 0;
};

} // namespace Terrenos::Dao
