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
inline std::string tipoDoDenunciavelParaString(TipoDoDenunciavel tipo)
{
    switch (tipo)
    {
    case TipoDoDenunciavel::USUARIO:
        return "Usuário";
    case TipoDoDenunciavel::POSTAGEM:
        return "Postagem";
    case TipoDoDenunciavel::COMENTARIO:
        return "Comentário";
    default:
        throw std::runtime_error(
            "Tentativa de stringificar um TipoDoDenunciavel inválido.");
    }
}

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice,
                                const TipoDoDenunciavel& tipo)
{
    IODevice << tipoDoDenunciavelParaString(tipo);
    return IODevice;
}

} // namespace Moderacao::Enums
