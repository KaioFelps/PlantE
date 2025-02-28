#include "dominio/terrenos/gerentes/gerente_de_terrenos.hpp"
#include "roteador.hpp"

namespace Terrenos::CasosDeUso
{

class InserirResultadoDeAnaliseDeSolo
{
  private:
    Gerentes::GerenteDeTerrenos gerenteDeTerrenos;

  public:
    InserirResultadoDeAnaliseDeSolo(
        Gerentes::GerenteDeTerrenos gerenteDeTerrenos);
    void executar(const std::string& idUsuario);
};

} // namespace Terrenos::CasosDeUso
