#include "terreno.hpp"
#include "util/id.hpp"
#include <iostream>
#include <stdexcept>

namespace Terrenos::Entidades
{

Terreno::Terreno(unsigned int largura_,
                 unsigned int comprimento_,
                 Terrenos::Enums::ExposicaoSolar exposicaoSolar_,
                 Terrenos::Enums::Clima clima_,
                 std::shared_ptr<Identidade::Entidades::Usuario> proprietario_)
    : id(Utils::GeradorDeId::gerarUUID()), largura(largura_),
      comprimento(comprimento_), exposicaoSolar(exposicaoSolar_), clima(clima_),
      proprietario(std::move(proprietario_))
{
}

Terreno::Terreno(const Terreno& terreno)
    : id(terreno.id), largura(terreno.largura),
      comprimento(terreno.comprimento),
      solo(terreno.solo.has_value()
               ? std::make_optional(
                     std::make_unique<Entidades::Solo>(**terreno.solo))
               : std::nullopt),
      exposicaoSolar(terreno.exposicaoSolar), clima(terreno.clima),
      plantacaoAtiva(terreno.plantacaoAtiva), proprietario(terreno.proprietario)
{
}

const std::string& Terreno::obtenhaId() const
{
    return this->id;
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

const std::optional<std::unique_ptr<Solo>>& Terreno::obtenhaSolo() const
{
    return this->solo;
}

Terrenos::Enums::ExposicaoSolar Terreno::obtenhaExposicaoSolar() const
{
    return this->exposicaoSolar;
}

Terrenos::Enums::Clima Terreno::obtenhaClima() const
{
    return this->clima;
}

const std::optional<std::shared_ptr<Plantacao>>&
Terreno::obtenhaPlantacaoAtiva() const
{
    return this->plantacaoAtiva;
}

std::shared_ptr<const Identidade::Entidades::Usuario>
Terreno::obtenhaProprietario() const
{
    return this->proprietario;
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

/// @brief Adiciona uma nova plantação ativa ao terreno.
/// @param plantacao A plantação nova a ser associada com o terreno.
/// @return
/// - `true`, se corretamente adicionado.
///
/// - `false`, se já houver uma plantação
///  associada ao terreno. Nesse caso, também imprime uma mensagem de alerta na
///  saída de erro.
void Terreno::coloquePlantacaoAtiva(std::shared_ptr<Plantacao> plantacao)
{
    if (this->plantacaoAtiva.has_value())
    {
        throw std::invalid_argument(
            "Já existe uma plantação ativa no Terreno de id \"" + this->id +
            "\".");
    }

    this->plantacaoAtiva = std::move(plantacao);
}

void Terreno::finalizePlantacaoAtiva()
{
    if (this->plantacaoAtiva.has_value())
    {
        this->plantacaoAtiva.value()->finalize();
    }

    this->plantacaoAtiva.reset();
}

void Terreno::desistaDaPlantacaoAtiva()
{
    if (this->plantacaoAtiva.has_value())
    {
        this->plantacaoAtiva.value()->cancele();
    }

    this->plantacaoAtiva.reset();
}

} // namespace Terrenos::Entidades
