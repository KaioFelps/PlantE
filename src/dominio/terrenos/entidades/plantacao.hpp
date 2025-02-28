#pragma once

#include "./planta.hpp"
#include "./terreno.hpp"
#include <ctime>
#include <memory>
#include <optional>
#include <string>

namespace Terrenos::Entidades
{
class Terreno;
}

namespace Terrenos::Entidades
{

class Plantacao
{
  private:
    std::string id;
    time_t dataDeInicio;
    std::optional<time_t> dataDeFinalizacao;
    std::optional<time_t> dataDeDesistencia;
    std::shared_ptr<Planta> planta;
    std::shared_ptr<Terreno> terreno;

  public:
    Plantacao(std::shared_ptr<Planta> planta, std::shared_ptr<Terreno> terreno);

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
