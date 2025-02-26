#include "usuarios_dao_em_memoria.hpp"
#include "globais.hpp"
#include <algorithm>

namespace Daos::EmMemoria
{

std::optional<std::shared_ptr<Moderacao::Entidades::Denunciavel>>
UsuariosDaoEmMemoria::encontre(const std::string& idUsuario)
{
    using Globais::usuariosDb;
    using Globais::usuariosDbMutex;
    using Identidade::Entidades::Usuario;

    std::lock_guard<std::mutex> lock(*usuariosDbMutex);

    auto usuario =
        std::find_if(usuariosDb->begin(),
                     usuariosDb->end(),
                     [ &idUsuario ](const std::shared_ptr<Usuario>& usuario)
                     { return usuario->obtenhaId() == idUsuario; });

    bool usuarioFoiEncontrado = usuario != usuariosDb->end();
    if (usuarioFoiEncontrado)
    {
        return *usuario;
    }

    return std::nullopt;
}

void UsuariosDaoEmMemoria::coloque(
    std::shared_ptr<Identidade::Entidades::Usuario> usuario)
{
    using Globais::usuariosDb;
    using Globais::usuariosDbMutex;

    std::lock_guard<std::mutex> lock(*usuariosDbMutex);

    usuariosDb->push_back(std::move(usuario));
}

} // namespace Daos::EmMemoria
