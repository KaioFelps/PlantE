#include "./solo.hpp"

namespace Terrenos::Entidades
{

Solo::Solo(unsigned char acidez_,
           unsigned char indiceDeMinerais_,
           unsigned char indiceDesalinidade_,
           unsigned char indiceDeArgila_,
           unsigned char indiceDeAreia_,
           unsigned char indiceDeSilite_,
           unsigned char cargaEletrica_)
    : acidez(acidez_), indiceDeMinerais(indiceDeMinerais_),
      indiceDesalinidade(indiceDesalinidade_), indiceDeArgila(indiceDeArgila_),
      indiceDeAreia(indiceDeAreia_), indiceDeSilite(indiceDeSilite_),
      cargaEletrica(cargaEletrica_)
{
}

unsigned char Solo::obtenhaAcidez() const
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

unsigned char Solo::obtenhaCargaEletrica() const
{
    return this->cargaEletrica;
}

} // namespace Terrenos::Entidades
