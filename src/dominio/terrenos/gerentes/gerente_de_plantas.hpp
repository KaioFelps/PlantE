#include "dominio/terrenos/entidades/planta.hpp"
#include "roteador.hpp"

namespace Terrenos::Gerentes
{

class GerenteDePlantacoes
{
  private:
    Roteador::Contexto& contexto;

  public:
    GerenteDePlantacoes(Roteador::Contexto& contexto);
    std::vector<Entidades::Planta> listePlantas() const;
};

} // namespace Terrenos::Gerentes
