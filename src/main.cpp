#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/terrenos/entidades/solo.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include <ctime>
#include <iostream>
#include <memory>

using namespace Terrenos::Entidades;
using namespace Identidade::Entidades;
using namespace Identidade::Enums;

int main()
{
    const auto TEST_THOUSAND = 1000;
    const auto TEST_TEN = 10;
    auto* terreno = new Terreno(TEST_THOUSAND, TEST_THOUSAND);

    std::unique_ptr<Solo> solo = std::make_unique<Solo>(
        TEST_TEN, TEST_TEN, TEST_TEN, TEST_TEN, TEST_TEN, TEST_TEN, TEST_TEN);

    terreno->atualizeSolo(std::move(solo));

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
