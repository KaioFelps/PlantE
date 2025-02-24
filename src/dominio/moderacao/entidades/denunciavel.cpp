#include "denunciavel.hpp"
#include <boost/uuid.hpp>

namespace Moderacao::Entidades
{

Denunciavel::Denunciavel(Enums::TipoDoDenunciavel tipo_) : tipo(tipo_)
{
    boost::uuids::random_generator uuidGenerator;
    std::string strUuid = boost::uuids::to_string(uuidGenerator());
    this->id = std::move(strUuid);
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
