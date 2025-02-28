#include "comentario.hpp"

namespace Feed::Entidades
{

Comentario::Comentario(std::shared_ptr<Identidade::Entidades::Usuario> autor_,
                       std::shared_ptr<Postagem> postagem_,
                       std::string conteudo_)
    : Comentavel(conteudo, Moderacao::Enums::TipoDoDenunciavel::COMENTARIO),
      autor(std::move(autor_)), postagem(std::move(postagem_))
{
}

const Postagem& Comentario::obtenhaPostagem() const
{
    return *this->postagem;
}

const Identidade::Entidades::Usuario& Comentario::obtenhaAutor() const
{
    return *this->autor;
}

} // namespace Feed::Entidades
