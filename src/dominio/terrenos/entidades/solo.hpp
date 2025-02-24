#pragma once

namespace Terrenos::Entidades
{

class Solo
{
  private:
    // o tipo é unsigned char porque esses valores vão de 0 a 100
    unsigned char acidez;
    unsigned char indiceDeMinerais;
    unsigned char indiceDeSalinidade;
    unsigned char indiceDeArgila;
    unsigned char indiceDeAreia;
    unsigned char indiceDeSilite;
    unsigned char cargaEletrica;

  public:
    Solo(unsigned char acidez,
         unsigned char indiceDeMinerais,
         unsigned char indiceDeSalinidade,
         unsigned char indiceDeArgila,
         unsigned char indiceDeAreia,
         unsigned char indiceDeSilite,
         unsigned char cargaEletrica);

    unsigned char obtenhaAcidez() const;
    unsigned char obtenhaIndiceDeMinerais() const;
    unsigned char obtenhaIndiceDeSalinidade() const;
    unsigned char obtenhaIndiceDeArgila() const;
    unsigned char obtenhaIndiceDeAreia() const;
    unsigned char obtenhaIndiceDeSilite() const;
    unsigned char obtenhaCargaEletrica() const;
};

} // namespace Terrenos::Entidades
