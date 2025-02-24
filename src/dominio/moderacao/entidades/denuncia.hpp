#pragma once

#include "denunciavel.hpp"
#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/moderacao/enum/estado_da_denuncia.hpp"
#include "dominio/moderacao/enum/motivo_da_denuncia.hpp"
#include <memory>
#include <optional>
#include <string>

namespace Moderacao::Entidades
{

class Denuncia
{
  private:
    std::string id;
    std::optional<std::string> detalhes;
    Enums::MotivoDaDenuncia motivo;
    Enums::EstadoDaDenuncia estado;
    Identidade::Entidades::Usuario relator;

    std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>
        moderadorInvestigador;

    std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>
        moderadorResolutor;

    std::shared_ptr<Denunciavel> denunciavel;

  public:
    Denuncia(std::optional<std::string> detalhes,
             Enums::MotivoDaDenuncia motivo,
             Enums::EstadoDaDenuncia estado,
             Identidade::Entidades::Usuario relator,
             std::shared_ptr<Denunciavel> denunciavel);

    void coloqueEstado(Enums::EstadoDaDenuncia estado);

    // getters
    const std::string& obtenhaId() const;
    const std::optional<std::string>& obtenhaDetalhes() const;
    const Identidade::Entidades::Usuario& obtenhaRelator() const;

    Enums::MotivoDaDenuncia obtenhaMotivo() const;
    Enums::EstadoDaDenuncia obtenhaEstado() const;

    const std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>&
    obtenhaModeradorInvestigador() const;

    const std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>&
    obtenhaModeradorResolutor() const;

    const std::shared_ptr<Denunciavel>& obtenhaDenunciavel() const;

    // setters
    void coloqueEstado(Enums::EstadoDaDenuncia estado);

    void coloqueModeradorInvestigador(
        std::shared_ptr<Identidade::Entidades::Usuario> moderadorInvestigador);

    void coloqueModeradorResolutor(
        std::shared_ptr<Identidade::Entidades::Usuario> moderadorResolutor);
};

} // namespace Moderacao::Entidades
