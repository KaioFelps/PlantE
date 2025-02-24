#include "comentavel.hpp"
#include <chrono>

namespace Feed::Entidades
{

Comentavel::Comentavel(std::string conteudo_,
                       Moderacao::Enums::TipoDoDenunciavel tipo)
    : Moderacao::Entidades::Denunciavel(tipo), conteudo(std::move(conteudo_)),
      dataPublicacao(Comentavel::obtenhaDataAtual()), estaAtivo(true)

{
}

time_t Comentavel::obtenhaDataAtual()
{
    auto now = std::chrono::system_clock::now();
    auto nowTimeT = std::chrono::system_clock::to_time_t(now);
    return nowTimeT;
}

const std::string& Comentavel::obtenhaConteudo() const
{
    return this->conteudo;
}

time_t Comentavel::obtenhaDataPublicacao() const
{
    return this->dataPublicacao;
}

bool Comentavel::obtenhaEstaAtivo() const
{
    return this->estaAtivo;
}

const std::optional<time_t>& Comentavel::obtenhaDataRemocao() const
{
    return this->dataRemocao;
}

void Comentavel::desativar()
{
    this->dataRemocao = Comentavel::obtenhaDataAtual();
    this->estaAtivo = false;
}

void Comentavel::coloqueConteudo(std::string conteudo)
{
    this->conteudo = std::move(conteudo);
}

} // namespace Feed::Entidades
