#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"
#include "dominio/terrenos/entidades/solo.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include "globais.hpp"
#include "infra/dao/em_memoria/plantas_dao_em_memoria.hpp"
#include "roteador.hpp"
#include "util/datas.hpp"
#include <ctime>
#include <iostream>

using namespace Terrenos::Entidades;
using namespace Terrenos::Dao;
using namespace Identidade::Entidades;
using namespace Identidade::Enums;
using namespace Daos::EmMemoria;

int main(int argc, char* argv[])
{
    if (argc >= 2 && std::string_view(argv[ 1 ]) == "--seed")
    {
        std::cout << "Populando os armazenamentos em memória...\n";
        Daos::EmMemoria::Globais::popular();
    }

    // não há tempo o bastante para implementar toda a parte do login
    auto usuario =
        std::make_shared<Usuario>("John Doe",
                                  "johndoe@gmail.com",
                                  "12345678",
                                  Utils::DataHora::obtenhaDataHoraAtual(),
                                  Identidade::Enums::Cargo::USUARIO);

    Roteador::Aplicativo aplicativo;

    std::shared_ptr<PlantasDao> plantasDao =
        std::make_shared<PlantasDaoEmMemoria>();

    auto contexto = aplicativo.obtenhaContextoMutavel();
    contexto->coloque(plantasDao);
    contexto->coloque(usuario);

    aplicativo.registrarRota("obter-sugestao-de-replantio",
                             "Obter sugestão de replantio",
                             [](const Roteador::Contexto& contexto)
                             {
                                 std::shared_ptr<PlantasDao> plantasDao =
                                     contexto.obtenha<PlantasDao>();

                                 auto usuario = contexto.obtenha<Usuario>();
                                 std::cout
                                     << "Usuario: " << *usuario->obtenhaNome()
                                     << ".\n";
                             });

    aplicativo.rodar();

    return EXIT_SUCCESS;
}
