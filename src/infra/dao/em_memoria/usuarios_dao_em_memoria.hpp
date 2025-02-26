#pragma once

#include "dominio/identidade/dao/usuarios_dao.hpp"

namespace Daos::EmMemoria
{

class UsuariosDaoEmMemoria : public Identidade::Dao::UsuariosDao
{
  public:
    std::optional<std::shared_ptr<Moderacao::Entidades::Denunciavel>>
    encontre(const std::string& idUsuario) final;

    void coloque(std::shared_ptr<Identidade::Entidades::Usuario> usuario) final;
};

} // namespace Daos::EmMemoria
