#include "./terreno.hpp"

namespace Terrenos::Entidades
{

Terreno::Terreno(unsigned int largura, unsigned int comprimento)
{
    this->largura = largura;
    this->comprimento = comprimento;
    this->solo = nullopt;
}

Terreno::~Terreno()
{
    if (this->solo.has_value())
    {
        delete this->solo.value();
    }
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

optional<Solo*> Terreno::obtenhaSolo() const
{
    return this->solo;
}

void Terreno::atualizeSolo(Solo* solo)
{
    this->solo = make_optional(solo);
}

} // namespace Terrenos::Entidades
