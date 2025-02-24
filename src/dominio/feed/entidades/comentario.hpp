#include "comentavel.hpp"
#include <string>

namespace Feed::Entidades
{

class Comentario : public Comentavel
{
  public:
    Comentario(std::string conteudo);
};

} // namespace Feed::Entidades
