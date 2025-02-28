#pragma once

#include "dominio/moderacao/entidades/denuncia.hpp"
#include "roteador.hpp"
#include <vector>

namespace Moderacao::Gerentes
{

class GerenteDeDenuncias
{
  private:
    Roteador::Contexto& contexto;

  public:
    GerenteDeDenuncias(Roteador::Contexto& contexto);

    // Essas funções não retornam um `shared_ptr` porque, de fato, elas devem
    // copiar todas as Denuncias. Fornecendo o shared_ptr, as instâncias seriam
    // mutáveis e refletiriam diretamente no armazenamento em memória. Se a
    // intenção for modificar uma denúncia, deve-se utilizar os respectivos
    // métodos para tal.

    std::vector<Moderacao::Entidades::Denuncia> listeDenuncias() const;

    std::optional<Moderacao::Entidades::Denuncia>
    obtenhaDenuncia(std::string& idDenuncia) const;

    void denuncie(std::string idRelator,
                  std::string idDenunciavel,
                  Moderacao::Enums::TipoDoDenunciavel tipo,
                  Moderacao::Enums::MotivoDaDenuncia motivo,
                  std::optional<std::string> detalhes);

    void marqueComoInvestigando(const std::string& idModerador,
                                const std::string& idDenuncia);

    void marqueComoResolvida(const std::string& idModerador,
                             const std::string& idDenuncia);
};

} // namespace Moderacao::Gerentes
