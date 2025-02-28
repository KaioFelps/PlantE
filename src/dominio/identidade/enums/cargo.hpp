#pragma once

#include <iostream>

namespace Identidade::Enums
{

enum class Cargo
{
    USUARIO,
    MODERADOR,
    ADMINISTRADOR,
};

// o modificador inline permite que a implementação seja feita diretamente no
// cabeçalho, no entanto, o inline força o linker a deduplicar a definição dessa
// função (mesmo sendo incluída em varios arquivos, no final, haverá somente uma
// definição desta função)
inline std::ostream& operator<<(std::ostream& IODevice, const Cargo& cargo)
{
    switch (cargo)
    {
    case Cargo::ADMINISTRADOR:
        IODevice << "Administrador";
        break;
    case Cargo::MODERADOR:
        IODevice << "Moderador";
        break;
    case Cargo::USUARIO:
        IODevice << "Usuário";
        break;
    }

    return IODevice;
}

} // namespace Identidade::Enums
