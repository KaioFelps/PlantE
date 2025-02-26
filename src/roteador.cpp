#include "roteador.hpp"
#include <iostream>

namespace Roteador
{

Aplicativo::Aplicativo() : contexto(std::make_unique<Contexto>())
{
}

Rota::Rota(std::string nome_, HandlerFunction handler_)
    : nome(std::move(nome_)), handler(std::move(handler_))
{
}

const std::string& Rota::obtenhaNome() const
{
    return this->nome;
}

const HandlerFunction& Rota::obtenhaHandler() const
{
    return this->handler;
}

void Aplicativo::listeAsRotas()
{
    std::cout << "Listando todas as rotas registradas:\n";

    for (const auto& pares : this->rotas)
    {
        std::cout << "[" << pares.first << "] " << pares.second->obtenhaNome()
                  << "\n";
    }
}

void Aplicativo::registrarRota(std::string chave,
                               std::string nome,
                               HandlerFunction handler)

{

    this->rotas[ std::move(chave) ] =
        std::make_unique<Rota>(std::move(nome), std::move(handler));
}

std::shared_ptr<Contexto> Aplicativo::obtenhaContextoMutavel()
{
    return this->contexto;
}

std::shared_ptr<Contexto> Aplicativo::obtenhaContexto() const
{
    return this->contexto;
}

void Aplicativo::executarRota(std::string& chave)
{
    auto rota = this->rotas.find(chave);
    if (rota == this->rotas.end())
    {
        std::cout << "Tentou acessar uma rota inválida.\n";
        return;
    }

    const auto* handler = &rota->second->obtenhaHandler();
    (*handler)(*this->contexto);
}

} // namespace Roteador
