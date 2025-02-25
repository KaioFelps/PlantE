#include "./plantacao.hpp"
#include "./terreno.hpp"
#include "util/datas.hpp"
#include "util/id.hpp"
#include <chrono>
#include <memory>

namespace Terrenos::Entidades
{

Plantacao::Plantacao(std::unique_ptr<Planta> planta_,
                     std::unique_ptr<Terreno> terreno)
    : id(Utils::GeradorDeId::gerarUUID()),
      dataDeInicio(Utils::DataHora::obtenhaDataHoraAtual()),
      planta(std::move(planta_)), terreno(std::move(terreno))
{
}

const std::string& Plantacao::obtenhaId() const
{
    return this->id;
}

const time_t& Plantacao::obtenhaDataDeInicio() const
{
    return this->dataDeInicio;
}

const std::optional<time_t>& Plantacao::obtenhaDataDeFinalizacao() const
{
    return this->dataDeFinalizacao;
}

const std::optional<time_t>& Plantacao::obtenhaDataDeDesistencia() const
{
    return this->dataDeDesistencia;
}

const Planta& Plantacao::obtenhaPlanta() const
{
    return *this->planta;
}

const Terreno& Plantacao::obtenhaTerreno() const
{
    return *this->terreno;
}

void Plantacao::cancele()
{
    this->dataDeDesistencia = Utils::DataHora::obtenhaDataHoraAtual();
}

void Plantacao::finalize()
{
    this->dataDeFinalizacao = Utils::DataHora::obtenhaDataHoraAtual();
}

} // namespace Terrenos::Entidades
