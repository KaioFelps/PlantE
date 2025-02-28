#include "dominio/terrenos/dao/terrenos_dao.hpp"

namespace Daos::EmMemoria
{

class TerrenosDaoEmMemoria : public Terrenos::Dao::TerrenosDao
{
    std::optional<Terrenos::Entidades::Terreno>
    encontre(const std::string& idTerreno) const final;

    std::unique_ptr<Terrenos::Entidades::Solo>
    crieSolo(double acidez,
             unsigned int indiceDeMinerais,
             unsigned int indiceDeSalinidade,
             unsigned int indiceDeArgila,
             unsigned int indiceDeSilte,
             unsigned int indiceDeAreia,
             double cargaEletrica) final;

    void salve(std::shared_ptr<Terrenos::Entidades::Terreno> terreno) final;

    std::vector<Terrenos::Entidades::Terreno> listeTodosDoUsuario(
        const Identidade::Entidades::Usuario& usuario) const final;
};

} // namespace Daos::EmMemoria
