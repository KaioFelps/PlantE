#include "postagem.hpp"

namespace Feed::Entidades
{
Postagem::Postagem(std::shared_ptr<Identidade::Entidades::Usuario> autor_,
                   std::string titulo_,
                   std::string conteudo_)
    : Comentavel(conteudo_, Moderacao::Enums::TipoDoDenunciavel::POSTAGEM),
      autor(std::move(autor_)), titulo(std::move(titulo_))
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

const Identidade::Entidades::Usuario& Postagem::obtenhaAutor() const
{
    return *this->autor;
}

} // namespace Feed::Entidades
