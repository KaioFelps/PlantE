#include "../enums/cargo.hpp"
#include <ctime>
#include <sstream>

using namespace std;
using namespace Identidade::Enums;

namespace Identidade::Entidades
{

class Usuario
{
  private:
    string nome;
    string email;
    string hashDaSeha;
    time_t dataDeNascimento;
    Cargo cargo;

  public:
    Usuario(string nome,
            string email,
            string hashDaSeha,
            time_t dataDeNascimento,
            Cargo cargo);

    const string* obtenhaNome() const;
    const string* obtenhaEmail() const;
    const string* obtenhaHashDaSeha() const;
    const time_t* obtenhaDataDeNascimento() const;
    const Cargo* obtenhaCargo() const;

    void coloqueNome(string nome);
    void coloqueEmail(string email);
    void coloqueHashDaSeha(string hashDaSeha);
    void coloqueDataDeNascimento(time_t dataDeNascimento);
    void coloqueCargo(Cargo cargo);
};

} // namespace Identidade::Entidades
