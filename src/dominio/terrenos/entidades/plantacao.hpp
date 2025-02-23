#pragma once

#include "./planta.hpp"
#include <ctime>
#include <memory>
#include <optional>
#include <string>

namespace Terrenos::Entidades
{

class Plantacao
{
  private:
    std::string id;
    time_t dataDeInicio;
    std::optional<time_t> dataDeFinalizacao;
    std::optional<time_t> dataDeDesistencia;
    std::unique_ptr<Planta> planta;
    std::unique_ptr<Terreno> terreno;

    static time_t obtenhaTempoAtual();

  public:
    Plantacao(std::unique_ptr<Planta> planta, std::unique_ptr<Terreno> terreno);

    const std::string& obtenhaId() const;
    const time_t& obtenhaDataDeInicio() const;
    const std::optional<time_t>& obtenhaDataDeFinalizacao() const;
    const std::optional<time_t>& obtenhaDataDeDesistencia() const;
    const Planta& obtenhaPlanta() const;
    const Terreno& obtenhaTerreno() const;

    void finalize();
    void cancele();
};

} // namespace Terrenos::Entidades
