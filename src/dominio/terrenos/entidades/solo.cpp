#include "./solo.hpp"

namespace Terrenos::Entidades
{

Solo::Solo(unsigned char acidez,
           unsigned char indiceDeMinerais,
           unsigned char indiceDesalinidade,
           unsigned char indiceDeArgila,
           unsigned char indiceDeAreia,
           unsigned char indiceDeSilite,
           unsigned char cargaEletrica)
{
    this->acidez = acidez;
    this->indiceDeMinerais = indiceDeMinerais;
    this->indiceDeSalinidade = indiceDesalinidade;
    this->indiceDeArgila = indiceDeArgila;
    this->indiceDeAreia = indiceDeAreia;
    this->indiceDeSilite = indiceDeSilite;
    this->cargaEletrica = cargaEletrica;
}

unsigned char Solo::obtenhaAcidez() const
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

unsigned char Solo::obtenhaIndiceDeSilite() const
{
    return this->indiceDeSilite;
}

unsigned char Solo::obtenhaCargaEletrica() const
{
    return this->cargaEletrica;
}

} // namespace Terrenos::Entidades
