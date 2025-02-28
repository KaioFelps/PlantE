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
    virtual std::optional<Entidades::Terreno>
    encontre(const std::string& idTerreno) const = 0;

    virtual std::unique_ptr<Entidades::Solo>
    crieSolo(double acidez,
             unsigned int indiceDeMinerais,
             unsigned int indiceDeSalinidade,
             unsigned int indiceDeArgila,
             unsigned int indiceDeSilte,
             unsigned int indiceDeAreia,
             double cargaEletrica) = 0;

    virtual void salve(std::shared_ptr<Entidades::Terreno> terreno) = 0;

    virtual std::vector<Entidades::Terreno> listeTodosDoUsuario(
        const Identidade::Entidades::Usuario& usuario) const = 0;
};

} // namespace Terrenos::Dao
