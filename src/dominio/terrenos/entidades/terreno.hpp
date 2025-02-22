#pragma once

#include "../enums/clima.hpp"
#include "../enums/exposicao_solar.hpp"
#include "./plantacao.hpp"
#include "./solo.hpp"
#include <memory>
#include <optional>
#include <string>

namespace Terrenos::Entidades
{

class Terreno
{
  private:
    std::string id;
    unsigned int largura;
    unsigned int comprimento;
    std::optional<std::unique_ptr<Solo>> solo;
    Terrenos::Enums::ExposicaoSolar exposicaoSolar;
    Terrenos::Enums::Clima clima;
    std::optional<std::shared_ptr<Plantacao>> plantacaoAtiva;

  public:
    Terreno(unsigned int largura,
            unsigned int comprimento,
            Terrenos::Enums::ExposicaoSolar exposicaoSolar,
            Terrenos::Enums::Clima clima);

    const std::string& obtenhaId() const;
    unsigned int obtenhaLargura() const;
    unsigned int obtenhaComprimento() const;
    unsigned int obtenhaTamanho() const;
    const std::optional<std::unique_ptr<Solo>>& obtenhaSolo() const;
    Terrenos::Enums::ExposicaoSolar obtenhaExposicaoSolar() const;
    Terrenos::Enums::Clima obtenhaClima() const;
    const std::optional<std::shared_ptr<Plantacao>>&
    obtenhaPlantacaoAtiva() const;

    void atualizeSolo(std::unique_ptr<Solo> solo);
    void coloqueExposicaoSolar(Terrenos::Enums::ExposicaoSolar exposicaoSolar);
    void coloqueClima(Terrenos::Enums::Clima clima);
    bool coloquePlantacaoAtiva(std::shared_ptr<Plantacao> plantacao);
    void finalizePlantacaoAtiva();
    void desistaDaPlantacaoAtiva();
};

} // namespace Terrenos::Entidades
