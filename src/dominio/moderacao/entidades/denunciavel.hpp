#pragma once

#include <string>

namespace Moderacao::Entidades
{

class Denunciavel
{
  protected:
    std::string id;
    Enums::TipoDoDenunciavel tipo;

  public:
    virtual const std::string& obtenhaId() const = 0;
    virtual Enums::TipoDoDenunciavel obtenhaTipo() const = 0;

    virtual ~Denunciavel() = default;
};

} // namespace Moderacao::Entidades
