#pragma once

#include "dominio/identidade/entidades/usuario.hpp"
#include "dominio/moderacao/dao/denunciavel_dao.hpp"

namespace Identidade::Dao
{

class UsuariosDao : public Moderacao::Dao::DenunciavelDao
{
  public:
    /// @brief Encontra uma instância de `Moderacao::Entidades::Denunciavel`
    /// pelo seu `id`. É necessário realizar um `dynamic_pointer_cast` para
    /// obter `Identidade::Entidades::Usuario`.
    ///
    /// @details Retorna um
    /// `std::optional<std::shared_ptr<Identidade::Entidades::Denunciavel>>`,
    /// que pode conter um ponteiro para um `Usuario` caso encontrado.
    ///
    /// @example
    /// ```cpp
    /// UsuariosDaoEmMemoria usuariosDao;
    /// std::string id;
    ///
    /// auto usuarioEncontrado = usuariosDao.encontre(id);
    ///
    /// if (usuarioEncontrado)
    /// {
    ///     auto usuario =
    ///     std::dynamic_pointer_cast<Identidade::Entidades::Usuario>(*usuarioEncontrado);
    ///
    ///     if (usuario)
    ///     {
    ///         std::cout << usuario->obtenhaNome();
    ///     }
    /// }
    /// ```
    std::optional<std::shared_ptr<Moderacao::Entidades::Denunciavel>>
    encontre(const std::string& idUsuario) override = 0;

    virtual void
    coloque(std::shared_ptr<Identidade::Entidades::Usuario> usuario) = 0;
};

} // namespace Identidade::Dao
