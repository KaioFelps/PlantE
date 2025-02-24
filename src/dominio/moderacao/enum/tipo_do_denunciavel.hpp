#pragma once

#include <iostream>

namespace Moderacao::Enums
{

enum class TipoDoDenunciavel
{
    USUARIO,
    POSTAGEM,
    COMENTARIO,
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice,
                                const TipoDoDenunciavel& tipo)
{
    switch (tipo)
    {
    case TipoDoDenunciavel::USUARIO:
        IODevice << "Usuário";
        break;
    case TipoDoDenunciavel::POSTAGEM:
        IODevice << "Postagem";
        break;
    case TipoDoDenunciavel::COMENTARIO:
        IODevice << "Comentário";
        break;
    }

    return IODevice;
}

} // namespace Moderacao::Enums
