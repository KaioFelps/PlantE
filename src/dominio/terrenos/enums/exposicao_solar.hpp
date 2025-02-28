#pragma once

#include <iostream>

namespace Terrenos::Enums
{

enum class ExposicaoSolar
{
    SOL_PLENO,
    MEIA_SOMBRA,
    SOMBRA
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice,
                                const ExposicaoSolar& exposicaosolar)
{
    switch (exposicaosolar)
    {
    case ExposicaoSolar::SOL_PLENO:
        IODevice << "Sol pleno";
        break;
    case ExposicaoSolar::MEIA_SOMBRA:
        IODevice << "Meia sombra";
        break;
    case ExposicaoSolar::SOMBRA:
        IODevice << "Sombra";
        break;
    }

    return IODevice;
}

} // namespace Terrenos::Enums
