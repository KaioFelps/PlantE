#include "gerente_de_daos_de_denunciaveis.hpp"
#include "dominio/identidade/dao/usuarios_dao.hpp"

namespace Moderacao::Gerentes
{

std::shared_ptr<Dao::DenunciavelDao>
GerenteDeDaosDeDenunciaveis::obtenhaDao(Enums::TipoDoDenunciavel tipo) const
{
    switch (tipo)
    {
    case Moderacao::Enums::TipoDoDenunciavel::USUARIO:
        return this->contexto->obtenha<Identidade::Dao::UsuariosDao>();
    default:
        throw std::runtime_error("Dao da entidade " +
                                 Enums::tipoDoDenunciavelParaString(tipo) +
                                 "ainda não foi implementado.");
    }
}

} // namespace Moderacao::Gerentes
