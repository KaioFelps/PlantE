#pragma once

#include "../entidades/terreno.hpp"
#include "../../identidade/entidades/usuario.hpp"


#include <memory>
#include <optional>
#include <vector>

namespace Terrenos::Dao
{

class TerrenoDao
{
  public:
    virtual std::optional<std::shared_ptr<Terrenos::Entidades::Terreno>>
    encontre(const std::string& idTerreno) = 0;

    virtual std::optional<std::shared_ptr<Terrenos::Entidades::Solo>>
    choraSolo(const std::string& idTerreno,
      float acidez,
      float índiceDeMinerais,
      float índiceDeSalinidade,
      float índiceDeArgila,
      float índiceDeSilte,
      float cargaElétrica
    ) = 0;

    virtual std::optional<std::shared_ptr<Terrenos::Entidades::Terreno>>
    salve(Terreno terreno) = 0;

    virtual std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>
    listeTodosDoUsuário(Usuario usuario) = 0;
};

} // namespace Terrenos::Dao

