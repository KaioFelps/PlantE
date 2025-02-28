#include "dominio/identidade/dao/usuarios_dao.hpp"
#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/moderacao/dao/denuncias_dao.hpp"
#include "dominio/terrenos/dao/plantacoes_dao.hpp"
#include "dominio/terrenos/dao/plantas_dao.hpp"
#include "dominio/terrenos/dao/terrenos_dao.hpp"
#include "dominio/terrenos/entidades/solo.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include "globais.hpp"
#include "infra/dao/em_memoria/denuncias_dao_em_memoria.hpp"
#include "infra/dao/em_memoria/plantacoes_dao_em_memoria.hpp"
#include "infra/dao/em_memoria/plantas_dao_em_memoria.hpp"
#include "infra/dao/em_memoria/terrenos_dao_em_memoria.hpp"
#include "infra/dao/em_memoria/usuarios_dao_em_memoria.hpp"
#include "roteador.hpp"
#include "util/datas.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char* argv[])
{
    using namespace Terrenos::Entidades;
    using namespace Identidade::Entidades;
    using namespace Identidade::Dao;
    using namespace Terrenos::Dao;
    using namespace Identidade::Enums;
    using namespace Daos::EmMemoria;
    using namespace Moderacao::Dao;
    using namespace Terrenos::Dao;

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

    auto plantasDao = std::make_shared<PlantasDaoEmMemoria>();
    auto usuariosDao = std::make_shared<UsuariosDaoEmMemoria>();
    auto denunciasDao = std::make_shared<DenunciasDaoEmMemoria>();
    auto terrenosDao = std::make_shared<TerrenosDaoEmMemoria>();
    auto plantacoesDao = std::make_shared<PlantacoesDaoEmMemoria>();

    usuariosDao->coloque(usuario);

    auto contexto = aplicativo.obtenhaContextoMutavel();
    contexto->coloque<PlantasDao>(plantasDao);
    contexto->coloque<UsuariosDao>(usuariosDao);
    contexto->coloque<DenunciasDao>(denunciasDao);
    contexto->coloque<TerrenosDao>(terrenosDao);
    contexto->coloque<TerrenosDao>(terrenosDao);
    contexto->coloque<PlantacoesDao>(plantacoesDao);
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
