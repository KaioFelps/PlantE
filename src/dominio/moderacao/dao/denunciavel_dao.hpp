#pragma once

#include "dominio/moderacao/entidades/denunciavel.hpp"
#include <memory>
#include <optional>

namespace Moderacao::Dao
{

class DenunciavelDao
{
  public:
    virtual std::optional<std::shared_ptr<Entidades::Denunciavel>>
    encontre(const std::string&) = 0;
};

} // namespace Moderacao::Dao
