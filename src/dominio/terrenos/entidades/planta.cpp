#include "./planta.hpp"

namespace Terrenos::Entidades
{

Planta::Planta(unsigned char phIdeal,
               unsigned char indiceDeNitrogenio,
               unsigned char indiceDeFosforo,
               unsigned char indiceDePotassio,
               unsigned char indiceDeRetencaoDeAgua,
               bool aceitaVento)
{
    this->phIdeal = phIdeal;
    this->indiceDeNitrogenio = indiceDeNitrogenio;
    this->indiceDeFosforo = indiceDeFosforo;
    this->indiceDePotassio = indiceDePotassio;
    this->indiceDeRetencaoDeAgua = indiceDeRetencaoDeAgua;
    this->aceitaVento = aceitaVento;
}

unsigned char Planta::obtenhaPhIdeal() const
{
    return this->phIdeal;
}

unsigned char Planta::obtenhaIndiceDeNitrogenio() const
{
    return this->indiceDeNitrogenio;
}

unsigned char Planta::obtenhaIndiceDeFosforo() const
{
    return this->indiceDeFosforo;
}

unsigned char Planta::obtenhaIndiceDePotassio() const
{
    return this->indiceDePotassio;
}

unsigned char Planta::obtenhaIndiceDeRetencaoDeAgua() const
{
    return this->indiceDeRetencaoDeAgua;
}

bool Planta::obtenhaAceitaVento() const
{
    return this->aceitaVento;
}

Terrenos::Enums::Clima Planta::obtenhaClima() const
{
    return this->clima;
}

void Planta::coloquePhIdeal(unsigned char phIdeal)
{
    this->phIdeal = phIdeal;
}

void Planta::coloqueIndiceDeNitrogenio(unsigned char indiceDeNitrogenio)
{
    this->indiceDeNitrogenio = indiceDeNitrogenio;
}

void Planta::coloqueIndiceDeFosforo(unsigned char indiceDeFosforo)
{
    this->indiceDeFosforo = indiceDeFosforo;
}

void Planta::coloqueIndiceDePotassio(unsigned char indiceDePotassio)
{
    this->indiceDePotassio = indiceDePotassio;
}

void Planta::coloqueIndiceDeRetencaoDeAgua(unsigned char indiceDeRetencaoDeAgua)
{
    this->indiceDeRetencaoDeAgua = indiceDeRetencaoDeAgua;
}

void Planta::coloqueAceitaVento(bool aceitaVento)
{
    this->aceitaVento = aceitaVento;
}

void Planta::coloqueClima(Terrenos::Enums::Clima clima)
{
    this->clima = clima;
}

} // namespace Terrenos::Entidades
