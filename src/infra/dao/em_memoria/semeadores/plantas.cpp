#include "plantas.hpp"
#include <memory>

using Terrenos::Entidades::Planta;

namespace Daos::EmMemoria::Semeadores
{

void preenchaPlantas(std::vector<std::shared_ptr<Planta>>& plantas)
{
    // NOLINTBEGIN
    plantas.emplace_back(
        std::make_shared<Planta>(6,
                                 50,
                                 40,
                                 30,
                                 35,
                                 true,
                                 Terrenos::Enums::Clima::TROPICAL,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(7,
                                 60,
                                 50,
                                 40,
                                 45,
                                 false,
                                 Terrenos::Enums::Clima::TEMPERADO,
                                 Terrenos::Enums::ExposicaoSolar::MEIA_SOMBRA));
    plantas.emplace_back(
        std::make_shared<Planta>(5,
                                 40,
                                 30,
                                 20,
                                 25,
                                 true,
                                 Terrenos::Enums::Clima::ARIDO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(6,
                                 55,
                                 45,
                                 35,
                                 40,
                                 false,
                                 Terrenos::Enums::Clima::MEDITERRANEO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(7,
                                 65,
                                 55,
                                 45,
                                 50,
                                 true,
                                 Terrenos::Enums::Clima::TROPICAL,
                                 Terrenos::Enums::ExposicaoSolar::MEIA_SOMBRA));
    plantas.emplace_back(
        std::make_shared<Planta>(5,
                                 35,
                                 25,
                                 15,
                                 20,
                                 false,
                                 Terrenos::Enums::Clima::TEMPERADO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(6,
                                 70,
                                 60,
                                 50,
                                 55,
                                 true,
                                 Terrenos::Enums::Clima::ARIDO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(7,
                                 75,
                                 65,
                                 55,
                                 60,
                                 false,
                                 Terrenos::Enums::Clima::MEDITERRANEO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    plantas.emplace_back(
        std::make_shared<Planta>(5,
                                 45,
                                 35,
                                 25,
                                 30,
                                 true,
                                 Terrenos::Enums::Clima::TROPICAL,
                                 Terrenos::Enums::ExposicaoSolar::MEIA_SOMBRA));
    plantas.emplace_back(
        std::make_shared<Planta>(6,
                                 80,
                                 70,
                                 60,
                                 65,
                                 false,
                                 Terrenos::Enums::Clima::TEMPERADO,
                                 Terrenos::Enums::ExposicaoSolar::SOL_PLENO));
    // NOLINTEND
}

} // namespace Daos::EmMemoria::Semeadores
