#pragma once

#include <iostream>

namespace Moderacao::Enums
{

enum class MotivoDaDenuncia
{
    CYBERBULLYING,
    DISCURSO_DE_ODIO,
    INCENTIVO_AO_SUICIDIO,
    COMENTARIO_PRECONCEITUOSO,
    SPAM
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice,
                                const MotivoDaDenuncia& motivo)
{
    switch (motivo)
    {
    case MotivoDaDenuncia::CYBERBULLYING:
        IODevice << "Cyberbullying";
        break;
    case MotivoDaDenuncia::DISCURSO_DE_ODIO:
        IODevice << "Discurso de ódio";
        break;
    case MotivoDaDenuncia::INCENTIVO_AO_SUICIDIO:
        IODevice << "Incentivo ao suicídio";
        break;
    case MotivoDaDenuncia::COMENTARIO_PRECONCEITUOSO:
        IODevice << "Comentário preconceituoso";
        break;
    case MotivoDaDenuncia::SPAM:
        IODevice << "Spam";
        break;
    }

    return IODevice;
}

} // namespace Moderacao::Enums
