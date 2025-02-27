#include "denuncias_dao_em_memoria.hpp"
#include "globais.hpp"
#include <algorithm>

namespace Daos::EmMemoria
{

using Globais::denunciasDb;
using Globais::denunciasDbMutex;

std::vector<std::shared_ptr<Moderacao::Entidades::Denuncia>>
DenunciasDaoEmMemoria::liste() const
{
    std::lock_guard<std::mutex> lock(*denunciasDbMutex);
    return *denunciasDb;
}

std::shared_ptr<Moderacao::Entidades::Denuncia> DenunciasDaoEmMemoria::crie(
    Moderacao::Enums::MotivoDaDenuncia motivo,
    std::optional<std::string> detalhes,
    std::shared_ptr<Identidade::Entidades::Usuario> relator,
    std::shared_ptr<Moderacao::Entidades::Denunciavel> denunciavel)
{
    std::lock_guard<std::mutex> lock(*denunciasDbMutex);
    auto denuncia = std::make_shared<Moderacao::Entidades::Denuncia>(
        detalhes,
        motivo,
        Moderacao::Enums::EstadoDaDenuncia::PENDENTE,
        relator,
        denunciavel);

    denunciasDb->push_back(denuncia);
    return denuncia;
}

void DenunciasDaoEmMemoria::salve(Moderacao::Entidades::Denuncia denuncia)
{
    using Moderacao::Entidades::Denuncia;

    auto idDenuncia = denuncia.obtenhaId();
    std::lock_guard<std::mutex> lock(*denunciasDbMutex);

    auto denunciaEncontrada =
        std::find_if(denunciasDb->begin(),
                     denunciasDb->end(),
                     [ &idDenuncia ](const std::shared_ptr<Denuncia>& denuncia_)
                     { return denuncia_->obtenhaId() == idDenuncia; });

    bool denunciaExiste = denunciaEncontrada != denunciasDb->end();
    if (denunciaExiste)
    {
        (*denunciaEncontrada) = std::make_shared<Denuncia>(denuncia);

        return;
    }

    denunciasDb->push_back(std::make_shared<Denuncia>(denuncia));
}

std::optional<std::shared_ptr<Moderacao::Entidades::Denuncia>>
DenunciasDaoEmMemoria::encontre(const std::string& idDenuncia) const
{
    using Moderacao::Entidades::Denuncia;

    std::lock_guard<std::mutex> lock(*denunciasDbMutex);

    auto denunciasIterator =
        std::find_if(denunciasDb->begin(),
                     denunciasDb->end(),
                     [ &idDenuncia ](const std::shared_ptr<Denuncia>& denuncia)
                     { return denuncia->obtenhaId() == idDenuncia; });

    bool denunciaFoiEncontrada = denunciasIterator != denunciasDb->end();

    if (denunciaFoiEncontrada)
    {
        return *denunciasIterator;
    }

    return std::nullopt;
}

} // namespace Daos::EmMemoria
