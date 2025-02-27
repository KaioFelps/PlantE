#include "plantacoes_dao_em_memoria.hpp"
#include "globais.hpp"
#include <algorithm>

namespace Daos::EmMemoria
{

std::optional<Terrenos::Entidades::Plantacao>
PlantacoesDaoEmMemoria::encontre(const std::string& idPlantacao)
{
    using Globais::plantacoesDb;
    using Globais::plantacoesDbMutex;
    using Terrenos::Entidades::Plantacao;

    std::lock_guard<std::mutex> lock(*plantacoesDbMutex);

    auto plantacaoEncontrada = std::find_if(
        plantacoesDb->begin(),
        plantacoesDb->end(),
        [ &idPlantacao ](const std::shared_ptr<Plantacao>& plantacao)
        { return plantacao->obtenhaId() == idPlantacao; });

    bool plantacaoExiste = plantacaoEncontrada != plantacoesDb->end();

    if (plantacaoExiste)
    {
        return **plantacaoEncontrada;
    }

    return std::nullopt;
}

std::shared_ptr<Terrenos::Entidades::Plantacao> PlantacoesDaoEmMemoria::crie(
    std::shared_ptr<Terrenos::Entidades::Planta> planta,
    std::shared_ptr<Terrenos::Entidades::Terreno> terreno)
{
    using Globais::plantacoesDb;
    using Globais::plantacoesDbMutex;
    using Terrenos::Entidades::Plantacao;

    auto plantacao = std::make_shared<Plantacao>(planta, terreno);

    std::lock_guard<std::mutex> lock(*plantacoesDbMutex);
    plantacoesDb->push_back(plantacao);

    return plantacao;
}

void PlantacoesDaoEmMemoria::salve(Terrenos::Entidades::Plantacao plantacao)
{
    using Globais::plantacoesDb;
    using Globais::plantacoesDbMutex;
    using Terrenos::Entidades::Plantacao;

    std::lock_guard<std::mutex> lock(*plantacoesDbMutex);
    auto idPlantacao = plantacao.obtenhaId();

    auto plantacaoEncontrada = std::find_if(
        plantacoesDb->begin(),
        plantacoesDb->end(),
        [ &idPlantacao ](const std::shared_ptr<Plantacao>& plantacao_)
        { return plantacao_->obtenhaId() == idPlantacao; });

    bool plantacaoExiste = plantacaoEncontrada != plantacoesDb->end();
    if (plantacaoExiste)
    {
        (*plantacaoEncontrada) = std::make_shared<Plantacao>(plantacao);

        return;
    }

    plantacoesDb->push_back(std::make_shared<Plantacao>(plantacao));
}

} // namespace Daos::EmMemoria
