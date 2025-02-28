#include "comentavel.hpp"
#include "util/datas.hpp"
#include <chrono>

namespace Feed::Entidades
{

Comentavel::Comentavel(std::string conteudo_,
                       Moderacao::Enums::TipoDoDenunciavel tipo)
    : Moderacao::Entidades::Denunciavel(tipo), conteudo(std::move(conteudo_)),
      dataPublicacao(Utils::DataHora::obtenhaDataHoraAtual())

{
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
    this->dataRemocao = Utils::DataHora::obtenhaDataHoraAtual();
    this->estaAtivo = false;
}

void Comentavel::coloqueConteudo(std::string conteudo)
{
    this->conteudo = std::move(conteudo);
}

} // namespace Feed::Entidades
