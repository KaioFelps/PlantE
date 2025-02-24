#include "postagem.hpp"

namespace Feed::Entidades
{
Postagem::Postagem(std::string titulo_, std::string conteudo_)
    : Comentavel(conteudo_, Moderacao::Enums::TipoDoDenunciavel::POSTAGEM),
      titulo(titulo_)
{
}

const std::string& Postagem::obtenhaTitulo() const
{
    return this->titulo;
}

void Postagem::coloqueTitulo(std::string titulo)
{
    this->titulo = std::move(titulo);
}

} // namespace Feed::Entidades
