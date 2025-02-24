#pragma once

#include "comentavel.hpp"
#include "dominio/identidade/entidades/usuario.hpp"
#include "postagem.hpp"
#include <memory>
#include <string>

namespace Feed::Entidades
{

class Comentario : public Comentavel
{
  private:
    std::shared_ptr<Identidade::Entidades::Usuario> autor;
    std::shared_ptr<Postagem> postagem;

  public:
    Comentario(std::shared_ptr<Identidade::Entidades::Usuario> autor,
               std::shared_ptr<Postagem> postagem,
               std::string conteudo);

    const Postagem& obtenhaPostagem() const;
    const Identidade::Entidades::Usuario& obtenhaAutor() const;
};

} // namespace Feed::Entidades
