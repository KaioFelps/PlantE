#include "./terreno.hpp"

namespace Terrenos::Entidades
{

Terreno::Terreno(unsigned int largura_,
                 unsigned int comprimento_,
                 Terrenos::Enums::ExposicaoSolar exposicaoSolar_,
                 Terrenos::Enums::Clima clima_)
    : largura(largura_), comprimento(comprimento_),
      exposicaoSolar(exposicaoSolar_), clima(clima_)
{
}

unsigned int Terreno::obtenhaLargura() const
{
    return this->largura;
}

unsigned int Terreno::obtenhaComprimento() const
{
    return this->comprimento;
}

unsigned int Terreno::obtenhaTamanho() const
{
    return this->largura * this->comprimento;
}

const std::optional<std::unique_ptr<Solo>>* Terreno::obtenhaSolo() const
{
    return &this->solo;
}

Terrenos::Enums::ExposicaoSolar Terreno::obtenhaExposicaoSolar() const
{
    return this->exposicaoSolar;
}

Terrenos::Enums::Clima Terreno::obtenhaClima() const
{
    return this->clima;
}

void Terreno::atualizeSolo(std::unique_ptr<Solo> solo)
{
    this->solo = std::move(solo);
}

void Terreno::coloqueExposicaoSolar(
    Terrenos::Enums::ExposicaoSolar exposicaoSolar)
{
    this->exposicaoSolar = exposicaoSolar;
}

void Terreno::coloqueClima(Terrenos::Enums::Clima clima)
{
    this->clima = clima;
}

} // namespace Terrenos::Entidades
