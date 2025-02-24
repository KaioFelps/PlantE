#include "postagem.hpp"

namespace Feed::Entidades
{
Postagem::Postagem(std::shared_ptr<Identidade::Entidades::Usuario> autor_,
                   std::string titulo_,
                   std::string conteudo_)
    : Comentavel(conteudo_, Moderacao::Enums::TipoDoDenunciavel::POSTAGEM),
      autor(autor_), titulo(titulo_)
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
