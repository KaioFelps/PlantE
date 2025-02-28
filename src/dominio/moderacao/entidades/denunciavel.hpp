#pragma once

#include "dominio/moderacao/enum/tipo_do_denunciavel.hpp"
#include <string>

namespace Moderacao::Entidades
{

class Denunciavel
{
  protected:
    std::string id;
    Enums::TipoDoDenunciavel tipo;

    Denunciavel(Enums::TipoDoDenunciavel tipo);

  public:
    const std::string& obtenhaId() const;
    Enums::TipoDoDenunciavel obtenhaTipo() const;

    virtual ~Denunciavel() = default;
};

} // namespace Moderacao::Entidades
