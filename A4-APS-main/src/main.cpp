#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/terrenos/entidades/solo.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include <ctime>
#include <iostream>

using namespace Terrenos::Entidades;
using namespace Identidade::Entidades;
using namespace Identidade::Enums;

int main()
{
    auto* terreno = new Terreno(1000, 1000);
    terreno->atualizeSolo(new Solo(10, 10, 10, 10, 10, 10, 10));

    std::cout << "Hello World!\n";

    std::cout << "Tamanho do terreno: " << terreno->obtenhaTamanho() << "km²"
              << std::endl;

    delete terreno;

    auto* usuario = new Usuario("John Doe",
                                "johndoe@gmail.com",
                                "senha-hasheada",
                                time(nullptr),
                                Cargo::ADMINISTRADOR);

    std::cout << "Usuário: " << *usuario->obtenhaNome()
              << "; Cargo: " << *usuario->obtenhaCargo()

              << "; Nascido em: "
              << std::asctime(
                     std::localtime(usuario->obtenhaDataDeNascimento()))
              << std::endl;

    delete usuario;

    return 0;
}
