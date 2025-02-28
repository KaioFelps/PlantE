#include "denuncia.hpp"
#include "util/id.hpp"

namespace Moderacao::Entidades
{

Denuncia::Denuncia(std::optional<std::string> detalhes_,
                   Enums::MotivoDaDenuncia motivo_,
                   Enums::EstadoDaDenuncia estado_,
                   std::shared_ptr<Identidade::Entidades::Usuario> relator_,
                   std::shared_ptr<Denunciavel> denunciavel_)
    : id(Utils::GeradorDeId::gerarUUID()), detalhes(std::move(detalhes_)),
      motivo(motivo_), estado(estado_), relator(std::move(relator_)),
      denunciavel(std::move(denunciavel_))

{
}

const std::string& Denuncia::obtenhaId() const
{
    return this->id;
}

const std::optional<std::string>& Denuncia::obtenhaDetalhes() const
{
    return this->detalhes;
}

Enums::MotivoDaDenuncia Denuncia::obtenhaMotivo() const
{
    return this->motivo;
}

Enums::EstadoDaDenuncia Denuncia::obtenhaEstado() const
{
    return this->estado;
}

const Identidade::Entidades::Usuario& Denuncia::obtenhaRelator() const
{
    return *this->relator;
}

const std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>&
Denuncia::obtenhaModeradorInvestigador() const
{
    return this->moderadorInvestigador;
}

const std::optional<std::shared_ptr<Identidade::Entidades::Usuario>>&
Denuncia::obtenhaModeradorResolutor() const
{
    return this->moderadorResolutor;
}

const Denunciavel& Denuncia::obtenhaDenunciavel() const
{
    return *this->denunciavel;
}

// setters

void Denuncia::coloqueEstado(Enums::EstadoDaDenuncia estado)
{
    this->estado = estado;
}

void Denuncia::coloqueModeradorInvestigador(
    std::shared_ptr<Identidade::Entidades::Usuario> moderadorInvestigador)
{
    this->moderadorInvestigador = std::move(moderadorInvestigador);
}

void Denuncia::coloqueModeradorResolutor(
    std::shared_ptr<Identidade::Entidades::Usuario> moderadorResolutor)
{
    this->moderadorResolutor = std::move(moderadorResolutor);
}

} // namespace Moderacao::Entidades
