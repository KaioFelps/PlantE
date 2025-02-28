#pragma once

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
                           unsigned char indiceDeMinerais,
                           unsigned char indiceDeSalinidade,
                           unsigned char indiceDeArgila,
                           unsigned char indiceDeSilte,
                           unsigned char cargaEletrica);

    void finalizePlantacao(const std::string& idTerreno);

    void desistaDaPlantacao(const std::string& idTerreno);

    void adicionePlantacao(const std::string& idTerreno,
                           const std::string& idPlanta);

    std::optional<Entidades::Plantacao>
    obtenhaPlantacao(const std::string& idTerreno) const;
};

} // namespace Terrenos::Gerentes
