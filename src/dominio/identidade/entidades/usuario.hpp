#pragma once

#include "dominio/identidade/enums/cargo.hpp"
#include "dominio/moderacao/entidades/denunciavel.hpp"
#include <ctime>
#include <sstream>

using namespace Identidade::Enums;

namespace Identidade::Entidades
{

class Usuario : public Moderacao::Entidades::Denunciavel
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
