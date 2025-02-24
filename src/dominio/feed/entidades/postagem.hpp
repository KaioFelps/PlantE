#include "comentavel.hpp"
#include <string>

namespace Feed::Entidades
{

class Postagem : public Comentavel
{
  private:
    std::string titulo;

  public:
    Postagem(std::string titulo, std::string conteudo);

    const std::string& obtenhaTitulo() const;
    void coloqueTitulo(std::string titulo);
};

} // namespace Feed::Entidades
