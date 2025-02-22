#pragma once

#include <iostream>

namespace Terrenos::Enums
{

enum class Clima
{
    TROPICAL,
    TEMPERADO,
    ARIDO,
    EQUATORIAL,
    SEMI_ARIDO,
    SUBTROPICAL,
    MEDITERRANEO,
    POLAR,
    MONTANHA
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice, const Clima& clima)
{
    switch (clima)
    {
    case Clima::TROPICAL:
        IODevice << "Tropical";
        break;
    case Clima::TEMPERADO:
        IODevice << "Temperado";
        break;
    case Clima::ARIDO:
        IODevice << "Árido";
        break;
    case Clima::EQUATORIAL:
        IODevice << "Equatorial";
        break;
    case Clima::SEMI_ARIDO:
        IODevice << "Semi árido";
        break;
    case Clima::MEDITERRANEO:
        IODevice << "Semiárido";
        break;
    case Clima::POLAR:
        IODevice << "Polar";
        break;
    case Clima::MONTANHA:
        IODevice << "Montanha";
        break;
    }

    return IODevice;
}

} // namespace Terrenos::Enums
