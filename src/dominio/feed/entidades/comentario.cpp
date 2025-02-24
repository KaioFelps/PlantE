#include "comentario.hpp"

namespace Feed::Entidades
{

Comentario::Comentario(std::string conteudo)
    : Comentavel(conteudo, Moderacao::Enums::TipoDoDenunciavel::COMENTARIO)
{
}

} // namespace Feed::Entidades
