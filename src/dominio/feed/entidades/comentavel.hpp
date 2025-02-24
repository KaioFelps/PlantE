#pragma once

#include "dominio/moderacao/entidades/denunciavel.hpp"
#include <optional>
#include <string>

namespace Feed::Entidades
{

class Comentavel : public Moderacao::Entidades::Denunciavel
{
  protected:
    Comentavel(std::string conteudo, Moderacao::Enums::TipoDoDenunciavel tipo);

    std::string conteudo;
    time_t dataPublicacao;
    std::optional<time_t> dataRemocao;
    bool estaAtivo;

  private:
    static time_t obtenhaDataAtual();

  public:
    const std::string& obtenhaConteudo() const;
    time_t obtenhaDataPublicacao() const;
    bool obtenhaEstaAtivo() const;
    const std::optional<time_t>& obtenhaDataRemocao() const;

    void desativar();
    void coloqueConteudo(std::string conteudo);

    virtual ~Comentavel() = default;
};

} // namespace Feed::Entidades
