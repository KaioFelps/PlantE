#pragma once

#include "dominio/terrenos/enums/clima.hpp"
#include "dominio/terrenos/enums/exposicao_solar.hpp"

namespace Terrenos::Entidades
{

class Planta
{
  private:
    std::string id;
    unsigned char phIdeal;
    unsigned char indiceDeNitrogenio;
    unsigned char indiceDeFosforo;
    unsigned char indiceDePotassio;
    unsigned char indiceDeRetencaoDeAgua;
    bool aceitaVento;
    // talvez, futuramente, seja interessante aceitar um vetor de climas aceitos
    Terrenos::Enums::Clima clima;
    Terrenos::Enums::ExposicaoSolar exposicaoSolar;

  public:
    Planta(unsigned char phIdeal,
           unsigned char indiceDeNitrogenio,
           unsigned char indiceDeFosforo,
           unsigned char indiceDePotassio,
           unsigned char indiceDeRetencaoDeAgua,
           bool aceitaVento,
           Terrenos::Enums::Clima clima,
           Terrenos::Enums::ExposicaoSolar exposicaoSolar);

    const std::string& obtenhaId() const;
    unsigned char obtenhaPhIdeal() const;
    unsigned char obtenhaIndiceDeNitrogenio() const;
    unsigned char obtenhaIndiceDeFosforo() const;
    unsigned char obtenhaIndiceDePotassio() const;
    unsigned char obtenhaIndiceDeRetencaoDeAgua() const;
    bool obtenhaAceitaVento() const;
    Terrenos::Enums::Clima obtenhaClima() const;
    Terrenos::Enums::ExposicaoSolar obtenhaExposicaoSolar() const;

    void coloquePhIdeal(unsigned char phIdeal);
    void coloqueIndiceDeNitrogenio(unsigned char indiceDeNitrogenio);
    void coloqueIndiceDeFosforo(unsigned char indiceDeFosforo);
    void coloqueIndiceDePotassio(unsigned char indiceDePotassio);
    void coloqueIndiceDeRetencaoDeAgua(unsigned char indiceDeRetencaoDeAgua);
    void coloqueAceitaVento(bool aceitaVento);
    void coloqueClima(Terrenos::Enums::Clima clima);
    void coloqueExposicaoSolar(Terrenos::Enums::ExposicaoSolar exposicaoSolar);
};

} // namespace Terrenos::Entidades
