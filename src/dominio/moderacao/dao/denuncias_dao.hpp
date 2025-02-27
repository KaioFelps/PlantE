#pragma once

#include "dominio/moderacao/entidades/denuncia.hpp"
#include <vector>

namespace Moderacao::Dao
{

class DenunciasDao
{
  public:
    virtual std::vector<std::shared_ptr<Entidades::Denuncia>> liste() const = 0;

    virtual std::shared_ptr<Entidades::Denuncia>
    crie(Enums::MotivoDaDenuncia motivo,
         std::optional<std::string> detalhes,
         std::shared_ptr<Identidade::Entidades::Usuario> relator,
         std::shared_ptr<Moderacao::Entidades::Denunciavel> denunciavel) = 0;

    virtual void salve(Entidades::Denuncia denuncia) = 0;

    virtual std::optional<std::shared_ptr<Entidades::Denuncia>>
    encontre(const std::string& idDenuncia) const = 0;
};

} // namespace Moderacao::Dao
