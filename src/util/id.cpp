#include "id.hpp"
#include <boost/uuid.hpp>

namespace Utils::GeradorDeId
{

std::string gerarUUID()
{
    boost::uuids::random_generator uuGeradorDeId;
    std::string strUuid = boost::uuids::to_string(uuGeradorDeId());
    return strUuid;
}

} // namespace Utils::GeradorDeId
