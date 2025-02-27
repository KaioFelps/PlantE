#pragma once

#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/moderacao/entidades/denuncia.hpp"
#include "dominio/terrenos/entidades/planta.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace Daos::EmMemoria::Globais
{

template <typename T>
using DbEmMemoria = std::shared_ptr<std::vector<std::shared_ptr<T>>>;

template <typename T>
DbEmMemoria<T> instanciarArmazenamento()
{
    return std::make_shared<std::vector<std::shared_ptr<T>>>();
}

extern std::shared_ptr<std::mutex> plantasDbMutex;
extern DbEmMemoria<Terrenos::Entidades::Planta> plantasDb;

extern std::shared_ptr<std::mutex> usuariosDbMutex;
extern DbEmMemoria<Identidade::Entidades::Usuario> usuariosDb;

extern std::shared_ptr<std::mutex> denunciasDbMutex;
extern DbEmMemoria<Moderacao::Entidades::Denuncia> denunciasDb;

void popular();

} // namespace Daos::EmMemoria::Globais
