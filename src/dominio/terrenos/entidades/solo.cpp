#include "./solo.hpp"

namespace Terrenos::Entidades
{

Solo::Solo(double acidez_,
           unsigned char indiceDeMinerais_,
           unsigned char indiceDesalinidade_,
           unsigned char indiceDeArgila_,
           unsigned char indiceDeAreia_,
           unsigned char indiceDeSilite_,
           double cargaEletrica_)
    : acidez(acidez_), indiceDeMinerais(indiceDeMinerais_),
      indiceDesalinidade(indiceDesalinidade_), indiceDeArgila(indiceDeArgila_),
      indiceDeAreia(indiceDeAreia_), indiceDeSilite(indiceDeSilite_),
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

unsigned char Solo::obtenhaIndiceDesalinidade() const
{
    return this->indiceDesalinidade;
}

unsigned char Solo::obtenhaIndiceDeArgila() const
{
    return this->indiceDeArgila;
}

unsigned char Solo::obtenhaIndiceDeAreia() const
{
    return this->indiceDeAreia;
}

unsigned char Solo::obtenhaIndiceDeSilite() const
{
    return this->indiceDeSilite;
}

double Solo::obtenhaCargaEletrica() const
{
    return this->cargaEletrica;
}

} // namespace Terrenos::Entidades
