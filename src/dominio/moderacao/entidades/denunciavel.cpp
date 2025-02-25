#include "denunciavel.hpp"
#include "util/id.hpp"

namespace Moderacao::Entidades
{

Denunciavel::Denunciavel(Enums::TipoDoDenunciavel tipo_)
    : id(Utils::GeradorDeId::gerarUUID()), tipo(tipo_)
{
}

const std::string& Denunciavel::obtenhaId() const
{
    return this->id;
}

Moderacao::Enums::TipoDoDenunciavel Denunciavel::obtenhaTipo() const
{
    return this->tipo;
}

} // namespace Moderacao::Entidades
