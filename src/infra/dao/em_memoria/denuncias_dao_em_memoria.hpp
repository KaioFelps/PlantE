#pragma once

#include "dominio/moderacao/dao/denuncias_dao.hpp"

namespace Daos::EmMemoria
{

class DenunciasDaoEmMemoria : public Moderacao::Dao::DenunciasDao
{
  public:
    std::vector<Moderacao::Entidades::Denuncia> liste() const final;

    std::shared_ptr<Moderacao::Entidades::Denuncia>
    crie(Moderacao::Enums::MotivoDaDenuncia motivo,
         std::optional<std::string> detalhes,
         std::shared_ptr<Identidade::Entidades::Usuario> relator,
         std::shared_ptr<Moderacao::Entidades::Denunciavel> denunciavel)
        override;

    void salve(Moderacao::Entidades::Denuncia denuncia) override;

    std::optional<Moderacao::Entidades::Denuncia>
    encontre(const std::string& idDenuncia) const override;
};

} // namespace Daos::EmMemoria
