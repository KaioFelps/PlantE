#pragma once

namespace Terrenos::Entidades
{

class Solo
{
  private:
    // o tipo é unsigned char porque esses valores vão de 0 a 100
    double acidez;
    unsigned char indiceDeMinerais;
    unsigned char indiceDeSalinidade;
    unsigned char indiceDeArgila;
    unsigned char indiceDeAreia;
    unsigned char indiceDeSilte;
    double cargaEletrica;

  public:
    Solo(double acidez,
         unsigned char indiceDeMinerais,
         unsigned char indiceDeSalinidade,
         unsigned char indiceDeArgila,
         unsigned char indiceDeAreia,
         unsigned char indiceDeSilte,
         double cargaEletrica);

    double obtenhaAcidez() const;
    unsigned char obtenhaIndiceDeMinerais() const;
    unsigned char obtenhaIndiceDeSalinidade() const;
    unsigned char obtenhaIndiceDeArgila() const;
    unsigned char obtenhaIndiceDeAreia() const;
    unsigned char obtenhaIndiceDeSilte() const;
    double obtenhaCargaEletrica() const;
};

} // namespace Terrenos::Entidades
