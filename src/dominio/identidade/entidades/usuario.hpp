#include "../enums/cargo.hpp"
#include <ctime>
#include <sstream>

using namespace Identidade::Enums;

namespace Identidade::Entidades
{

class Usuario
{
  private:
    std::string nome;
    std::string email;
    std::string hashDaSeha;
    time_t dataDeNascimento;
    Cargo cargo;

  public:
    Usuario(std::string nome,
            std::string email,
            std::string hashDaSeha,
            time_t dataDeNascimento,
            Cargo cargo);

    const std::string* obtenhaNome() const;
    const std::string* obtenhaEmail() const;
    const std::string* obtenhaHashDaSeha() const;
    const time_t* obtenhaDataDeNascimento() const;
    const Cargo* obtenhaCargo() const;

    void coloqueNome(std::string nome);
    void coloqueEmail(std::string email);
    void coloqueHashDaSeha(std::string hashDaSeha);
    void coloqueDataDeNascimento(time_t dataDeNascimento);
    void coloqueCargo(Cargo cargo);
};

} // namespace Identidade::Entidades
