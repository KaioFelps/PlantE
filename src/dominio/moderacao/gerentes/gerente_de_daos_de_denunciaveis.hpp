#pragma once

#include "dominio/moderacao/dao/denunciavel_dao.hpp"
#include "roteador.hpp"

namespace Moderacao::Gerentes
{

// Esse gerente não deveria ser inserido no container de dependências, já que
// ele depende intrinsecamente do contexto atual.
//
// Para inseri-lo no container de dependências, seria necessário que houvesse
// dinstinção entre "singleton", "transient" e "scoped".
class GerenteDeDaosDeDenunciaveis
{
  private:
    Roteador::Contexto& contexto;

  public:
    GerenteDeDaosDeDenunciaveis(Roteador::Contexto& contexto);

    std::shared_ptr<Dao::DenunciavelDao>
    obtenhaDao(Enums::TipoDoDenunciavel tipo) const;
};

} // namespace Moderacao::Gerentes
