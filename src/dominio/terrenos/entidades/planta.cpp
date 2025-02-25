#include "./planta.hpp"
#include "util/id.hpp"

namespace Terrenos::Entidades
{

Planta::Planta(unsigned char phIdeal_,
               unsigned char indiceDeNitrogenio_,
               unsigned char indiceDeFosforo_,
               unsigned char indiceDePotassio_,
               unsigned char indiceDeRetencaoDeAgua_,
               bool aceitaVento_,
               Terrenos::Enums::Clima clima_,
               Terrenos::Enums::ExposicaoSolar exposicaoSolar_)
    : id(Utils::GeradorDeId::gerarUUID()), phIdeal(phIdeal_),
      indiceDeNitrogenio(indiceDeNitrogenio_),
      indiceDeFosforo(indiceDeFosforo_), indiceDePotassio(indiceDePotassio_),
      indiceDeRetencaoDeAgua(indiceDeRetencaoDeAgua_),
      aceitaVento(aceitaVento_), clima(clima_), exposicaoSolar(exposicaoSolar_)
{
}

const std::string& Planta::obtenhaId() const
{
    return this->id;
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

void Planta::coloqueExposicaoSolar(
    Terrenos::Enums::ExposicaoSolar exposicaoSolar)
{
    this->exposicaoSolar = exposicaoSolar;
}

} // namespace Terrenos::Entidades
