#pragma once

#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include <memory>
#include <optional>
#include <vector>

namespace Terrenos::Dao
{

class TerrenosDao
{
  public:
    virtual std::optional<std::shared_ptr<Entidades::Terreno>>
    encontre(const std::string& idTerreno) const = 0;

    virtual std::shared_ptr<Entidades::Solo>
    crieSolo(const std::string& idTerreno,
             double acidez,
             unsigned int índiceDeMinerais,
             unsigned int índiceDeSalinidade,
             unsigned int índiceDeArgila,
             unsigned int índiceDeSilte,
             double cargaElétrica) = 0;

    virtual void salve(Entidades::Terreno terreno) = 0;

    virtual std::vector<std::shared_ptr<Entidades::Terreno>>
    listeTodosDoUsuario(Identidade::Entidades::Usuario usuario) const = 0;
};

} // namespace Terrenos::Dao
