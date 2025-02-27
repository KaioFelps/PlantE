#include "dominio/terrenos/entidades/planta.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include "roteador.hpp"
#include <vector>

namespace Terrenos::Gerentes
{

class GerenteDeTerrenos
{
  private:
    std::shared_ptr<Roteador::Contexto> contexto;

  public:
    GerenteDeTerrenos(std::shared_ptr<Roteador::Contexto> contexto);

    std::vector<Entidades::Planta>
    obtenhaSugestoes(const std::string& idTerreno) const;

    std::vector<Entidades::Terreno>
    listeTerrenos(const std::string& idUsuario) const;

    void recebaDadosDoSolo(std::string idTerreno,
                           float acidez,
                           unsigned char índiceDeMinerais,
                           unsigned char índiceDeSalinidade,
                           unsigned char índiceDeArgila,
                           unsigned char índiceDeSilte,
                           unsigned char cargaElétrica);
};

} // namespace Terrenos::Gerentes
