#include "dominio/terrenos/entidades/planta.hpp"
#include "roteador.hpp"

namespace Terrenos::Gerentes
{

class GerenteDePlantacoes
{
  private:
    std::shared_ptr<Roteador::Contexto> contexto;

  public:
    std::vector<Entidades::Planta> listePlantas() const;
};

} // namespace Terrenos::Gerentes
