#include "./terreno.hpp"

namespace Terrenos::Entidades
{

Terreno::Terreno(unsigned int largura_, unsigned int comprimento_)
    : largura(largura_), comprimento(comprimento_)
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

void Terreno::atualizeSolo(std::unique_ptr<Solo> solo)
{
    this->solo = std::move(solo);
}

} // namespace Terrenos::Entidades
