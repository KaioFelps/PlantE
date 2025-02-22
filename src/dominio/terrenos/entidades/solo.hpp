#pragma once

namespace Terrenos::Entidades
{

class Solo
{
  private:
    // o tipo é unsigned char porque esses valores vão de 0 a 100
    double acidez;
    unsigned char indiceDeMinerais;
    unsigned char indiceDesalinidade;
    unsigned char indiceDeArgila;
    unsigned char indiceDeAreia;
    unsigned char indiceDeSilite;
    double cargaEletrica;

  public:
    Solo(double acidez,
         unsigned char indiceDeMinerais,
         unsigned char indiceDesalinidade,
         unsigned char indiceDeArgila,
         unsigned char indiceDeAreia,
         unsigned char indiceDeSilite,
         double cargaEletrica);

    double obtenhaAcidez() const;
    unsigned char obtenhaIndiceDeMinerais() const;
    unsigned char obtenhaIndiceDesalinidade() const;
    unsigned char obtenhaIndiceDeArgila() const;
    unsigned char obtenhaIndiceDeAreia() const;
    unsigned char obtenhaIndiceDeSilite() const;
    double obtenhaCargaEletrica() const;
};

} // namespace Terrenos::Entidades
