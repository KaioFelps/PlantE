#pragma once

#include "./planta.hpp"
#include <ctime>
#include <memory>
#include <optional>

namespace Terrenos::Entidades
{

class Plantacao
{
  private:
    time_t dataDeInicio;
    std::optional<time_t> dataDeFinalizacao;
    std::optional<time_t> dataDeDesistencia;
    std::unique_ptr<Planta> planta;

    static time_t obtenhaTempoAtual();

  public:
    Plantacao(std::unique_ptr<Planta> planta);

    const time_t* obtenhaDataDeInicio() const;
    const std::optional<time_t>* obtenhaDataDeFinalizacao() const;
    const std::optional<time_t>* obtenhaDataDeDesistencia() const;
    const Planta* obtenhaPlanta() const;

    void finalize();
    void cancele();
};

} // namespace Terrenos::Entidades
