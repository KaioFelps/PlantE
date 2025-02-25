#include "./plantacao.hpp"
#include "./terreno.hpp"
#include "util/id.hpp"
#include <chrono>
#include <memory>

namespace Terrenos::Entidades
{

Plantacao::Plantacao(std::unique_ptr<Planta> planta_,
                     std::unique_ptr<Terreno> terreno)
    : id(Utils::GeradorDeId::gerarUUID()),
      dataDeInicio(Plantacao::obtenhaTempoAtual()), planta(std::move(planta_)),
      terreno(std::move(terreno))
{
}

time_t Plantacao::obtenhaTempoAtual()
{
    auto now = std::chrono::system_clock::now();
    auto nowTimeT = std::chrono::system_clock::to_time_t(now);
    return nowTimeT;
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
    this->dataDeDesistencia = Plantacao::obtenhaTempoAtual();
}

void Plantacao::finalize()
{
    this->dataDeFinalizacao = Plantacao::obtenhaTempoAtual();
}

} // namespace Terrenos::Entidades
