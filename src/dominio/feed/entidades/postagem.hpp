#include "comentavel.hpp"
#include "dominio/identidade/entidades/usuario.hpp"
#include <memory>
#include <string>

namespace Feed::Entidades
{

class Postagem : public Comentavel
{
  private:
    std::string titulo;
    std::shared_ptr<Identidade::Entidades::Usuario> autor;

  public:
    Postagem(std::shared_ptr<Identidade::Entidades::Usuario> autor,
             std::string titulo,
             std::string conteudo);

    const std::string& obtenhaTitulo() const;
    void coloqueTitulo(std::string titulo);
};

} // namespace Feed::Entidades
