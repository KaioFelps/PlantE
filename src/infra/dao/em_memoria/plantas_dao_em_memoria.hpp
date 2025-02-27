#pragma once

#include "dominio/terrenos/dao/plantas_dao.hpp"

namespace Daos::EmMemoria
{

class PlantasDaoEmMemoria : public Terrenos::Dao::PlantasDao
{
  public:
    std::vector<std::shared_ptr<Terrenos::Entidades::Planta>>
    encontrePlantasCorrespondentes(Terrenos::Entidades::Solo& solo) final;

    std::optional<std::shared_ptr<Terrenos::Entidades::Planta>>
    encontre(const std::string& idPlanta) final;

  private:
    static bool plantaEhCompativel(const Terrenos::Entidades::Planta& planta,
                                   const Terrenos::Entidades::Solo& solo);
};

} // namespace Daos::EmMemoria
