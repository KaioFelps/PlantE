#pragma once

#include "dominio/terrenos/dao/plantacoes_dao.hpp"

namespace Daos::EmMemoria
{
class PlantacoesDaoEmMemoria : Terrenos::Dao::PlantacoesDao
{
  public:
    std::optional<Terrenos::Entidades::Plantacao>
    encontre(const std::string& idPlantacao) final;

    std::shared_ptr<Terrenos::Entidades::Plantacao>
    crie(std::shared_ptr<Terrenos::Entidades::Planta> planta,
         std::shared_ptr<Terrenos::Entidades::Terreno> terreno) final;

    void salve(Terrenos::Entidades::Plantacao plantacao) final;
};

} // namespace Daos::EmMemoria
