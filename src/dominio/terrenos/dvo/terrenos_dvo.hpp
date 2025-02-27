#include "dominio/terrenos/entidades/solo.hpp"
#include <memory>

namespace Terrenos::Dvo
{

class TerrenosDvo
{
  public:
    static void
    valideSolo(std::shared_ptr<const Entidades::Solo>& solo) noexcept(false);
};

} // namespace Terrenos::Dvo
