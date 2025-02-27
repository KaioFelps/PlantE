#include "plantas_dao_em_memoria.hpp"
#include "globais.hpp"
#include <algorithm>
#include <mutex>

using Terrenos::Dao::PlantasDao;
using Terrenos::Entidades::Planta;
using Terrenos::Entidades::Solo;

namespace Daos::EmMemoria
{

std::vector<std::shared_ptr<Planta>>
PlantasDaoEmMemoria::encontrePlantasCorrespondentes(const Solo& solo)
{
    std::lock_guard<std::mutex> lock(*Globais::plantasDbMutex);

    std::vector<std::shared_ptr<Planta>> plantasCompativeis;

    std::copy_if(
        Globais::plantasDb->begin(),
        Globais::plantasDb->end(),
        std::back_insert_iterator(plantasCompativeis),
        [ &solo ](const std::shared_ptr<Planta>& planta)
        { return PlantasDaoEmMemoria::plantaEhCompativel(*planta, solo); });

    return plantasCompativeis;
}

std::optional<std::shared_ptr<Planta>>
PlantasDaoEmMemoria::encontre(const std::string& idPlanta)
{
    std::lock_guard<std::mutex> lock(*Globais::plantasDbMutex);

    auto plantasIterator =
        std::find_if(Globais::plantasDb->begin(),
                     Globais::plantasDb->end(),
                     [ &idPlanta ](const std::shared_ptr<Planta>& planta)
                     { return planta->obtenhaId() == idPlanta; });

    bool plantaFoiEncontrada = plantasIterator != Globais::plantasDb->end();

    if (plantaFoiEncontrada)
    {
        return *plantasIterator;
    }

    return std::nullopt;
}

bool PlantasDaoEmMemoria::plantaEhCompativel(const Planta& planta,
                                             const Solo& solo)
{
    // 1. Verifica compatibilidade do pH (dentro de um intervalo de ±0.5)
    const float INTERVALO_MINIMO_DE_COMPATIBILIDADE = 0.5;
    const int INDICE_MINIMO_DE_RETENCAO_DE_AGUA = 10;
    const int CARGA_ELETRICA_SUPORTADA = 50;

    if (std::abs(solo.obtenhaAcidez() - planta.obtenhaPhIdeal()) >
        INTERVALO_MINIMO_DE_COMPATIBILIDADE)
    {
        return false;
    }

    // 2. Verifica se o solo tem minerais suficientes para a planta
    if (solo.obtenhaIndiceDeMinerais() < planta.obtenhaIndiceDeNitrogenio() ||
        solo.obtenhaIndiceDeMinerais() < planta.obtenhaIndiceDeFosforo() ||
        solo.obtenhaIndiceDeMinerais() < planta.obtenhaIndiceDePotassio())
    {
        return false;
    }

    // 3. Avaliação da retenção de água (argila, areia e silte influenciam
    // nisso)
    unsigned char retencaoReal =
        (solo.obtenhaIndiceDeArgila() * 2 + solo.obtenhaIndiceDeSilte()) / 3;

    if (std::abs(retencaoReal - planta.obtenhaIndiceDeRetencaoDeAgua()) >
        INDICE_MINIMO_DE_RETENCAO_DE_AGUA)
    {
        return false;
    }

    // 4. Verifica se a planta suporta vento (se necessário)
    if (!planta.obtenhaAceitaVento() &&
        solo.obtenhaCargaEletrica() > CARGA_ELETRICA_SUPORTADA)
    {
        return false;
    }

    // 5. Verifica compatibilidade de clima e exposição solar
    // (Aqui assumimos que solo e planta precisam do mesmo clima e
    // exposição)
    //
    // precisaria ter acesso ao terreno, porém, por falta de tempo, será
    // ignorado

    return true;
}

} // namespace Daos::EmMemoria
