#include "usuario.hpp"

namespace Identidade::Entidades
{

Usuario::Usuario(std::string nome,
                 std::string email,
                 std::string hashDaSeha,
                 time_t dataDeNascimento,
                 Cargo cargo)
{
    this->nome = nome;
    this->email = email;
    this->hashDaSeha = hashDaSeha;
    this->dataDeNascimento = dataDeNascimento;
    this->cargo = cargo;
};

const std::string* Usuario::obtenhaNome() const
{
    return &this->nome;
}

const std::string* Usuario::obtenhaEmail() const
{
    return &this->email;
}

const std::string* Usuario::obtenhaHashDaSeha() const
{
    return &this->hashDaSeha;
}

const time_t* Usuario::obtenhaDataDeNascimento() const
{
    return &this->dataDeNascimento;
}

const Cargo* Usuario::obtenhaCargo() const
{
    return &this->cargo;
}

void Usuario::coloqueNome(std::string nome)
{
    this->nome = nome;
}

void Usuario::coloqueEmail(std::string email)
{
    this->email = email;
}

void Usuario::coloqueHashDaSeha(std::string hashDaSeha)
{
    this->hashDaSeha = hashDaSeha;
}

void Usuario::coloqueDataDeNascimento(time_t dataDeNascimento)
{
    this->dataDeNascimento = dataDeNascimento;
}

void Usuario::coloqueCargo(Cargo cargo)
{
    this->cargo = cargo;
}

} // namespace Identidade::Entidades
