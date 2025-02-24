#include <iostream>

namespace Moderacao::Enums
{

enum class EstadoDaDenuncia
{
    PENDENTE,
    ANALISE,
    RESOLVIDO,
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice,
                                const EstadoDaDenuncia& estado)
{
    switch (estado)
    {
    case EstadoDaDenuncia::PENDENTE:
        IODevice << "Cyberbullying";
        break;
    case EstadoDaDenuncia::ANALISE:
        IODevice << "Discurso de ódio";
        break;
    case EstadoDaDenuncia::RESOLVIDO:
        IODevice << "Incentivo ao suicídio";
        break;
    }

    return IODevice;
}

} // namespace Moderacao::Enums
