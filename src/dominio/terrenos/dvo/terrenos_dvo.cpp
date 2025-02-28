#include "terrenos_dvo.hpp"
#include <stdexcept>

namespace Terrenos::Dvo
{

void TerrenosDvo::valideSolo(const Entidades::Solo& solo) noexcept(false)
{
    const unsigned char LIMITE_DO_INTERVALO = 100;

    if (solo.obtenhaAcidez() < 0)
    {
        throw std::invalid_argument("A acidez do solo não pode ser negativa.");
    }

    if (solo.obtenhaIndiceDeAreia() > LIMITE_DO_INTERVALO ||
        solo.obtenhaIndiceDeArgila() > LIMITE_DO_INTERVALO ||
        solo.obtenhaIndiceDeMinerais() > LIMITE_DO_INTERVALO ||
        solo.obtenhaIndiceDeSalinidade() > LIMITE_DO_INTERVALO ||
        solo.obtenhaIndiceDeSilte() > LIMITE_DO_INTERVALO)
    {
        throw std::range_error("Os índices devem estar entre 0 e 100.");
    }

    if (solo.obtenhaCargaEletrica() < 0)
    {
        throw std::invalid_argument("A carga elétrica não pode ser negativa.");
    }
}

} // namespace Terrenos::Dvo
