#include "./solo.hpp"

namespace Terrenos::Entidades
{

Solo::Solo(double acidez_,
           unsigned char indiceDeMinerais_,
           unsigned char indiceDeSalinidade_,
           unsigned char indiceDeArgila_,
           unsigned char indiceDeAreia_,
           unsigned char indiceDeSilte_,
           double cargaEletrica_)
    : acidez(acidez_), indiceDeMinerais(indiceDeMinerais_),
      indiceDeSalinidade(indiceDeSalinidade_), indiceDeArgila(indiceDeArgila_),
      indiceDeAreia(indiceDeAreia_), indiceDeSilte(indiceDeSilte_),
      cargaEletrica(cargaEletrica_)
{
}

double Solo::obtenhaAcidez() const
{
    return this->acidez;
}

unsigned char Solo::obtenhaIndiceDeMinerais() const
{
    return this->indiceDeMinerais;
}

unsigned char Solo::obtenhaIndiceDeSalinidade() const
{
    return this->indiceDeSalinidade;
}

unsigned char Solo::obtenhaIndiceDeArgila() const
{
    return this->indiceDeArgila;
}

unsigned char Solo::obtenhaIndiceDeAreia() const
{
    return this->indiceDeAreia;
}

unsigned char Solo::obtenhaIndiceDeSilte() const
{
    return this->indiceDeSilte;
}

double Solo::obtenhaCargaEletrica() const
{
    return this->cargaEletrica;
}

} // namespace Terrenos::Entidades
