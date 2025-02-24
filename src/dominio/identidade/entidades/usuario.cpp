#include "usuario.hpp"

namespace Identidade::Entidades
{

Usuario::Usuario(std::string nome_,
                 std::string email_,
                 std::string hashDaSeha_,
                 time_t dataDeNascimento_,
                 Cargo cargo_)
    : Denunciavel(Moderacao::Enums::TipoDoDenunciavel::USUARIO),
      nome(std::move(nome_)), email(std::move(email_)),
      hashDaSeha(std::move(hashDaSeha_)), dataDeNascimento(dataDeNascimento_),
      cargo(cargo_)
{
}

const std::string& Usuario::obtenhaId() const
{
    return this->id;
}
Moderacao::Enums::TipoDoDenunciavel Usuario::obtenhaTipo() const
{
    return this->tipo;
}

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
