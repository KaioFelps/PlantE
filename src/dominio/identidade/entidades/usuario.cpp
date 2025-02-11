#include "./usuario.hpp"

namespace Identidade::Entidades
{

Usuario::Usuario(string nome,
                 string email,
                 string hashDaSenha,
                 time_t dataDeNascimento,
                 Cargo cargo)
{
    this->nome = nome;
    this->email = email;
    this->hashDaSenha = hashDaSenha;
    this->dataDeNascimento = dataDeNascimento;
    this->cargo = cargo;
};

const string* Usuario::obtenhaNome() const
{
    return &this->nome;
}

const string* Usuario::obtenhaEmail() const
{
    return &this->email;
}

const string* Usuario::obtenhaHashDaSenha() const
{
    return &this->hashDaSenha;
}

const time_t* Usuario::obtenhaDataDeNascimento() const
{
    return &this->dataDeNascimento;
}

const Cargo* Usuario::obtenhaCargo() const
{
    return &this->cargo;
}

void Usuario::coloqueNome(string nome)
{
    this->nome = nome;
}

void Usuario::coloqueEmail(string email)
{
    this->email = email;
}

void Usuario::coloqueHashDaSenha(string hashDaSenha)
{
    this->hashDaSenha = hashDaSenha;
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
