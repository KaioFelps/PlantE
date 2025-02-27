#pragma once

#include <any>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <typeindex>
#include <unordered_map>

// Boa parte dessas classes foram geradas com inteligência artificial.
namespace Roteador
{

/// @brief Container para uma injeção de depenndências extremamente básica.
class Contexto
{
  private:
    std::unordered_map<std::type_index, std::any> container;

  public:
    template <typename T>
    void coloque(std::shared_ptr<T> instancia)
    {
        container[ std::type_index(typeid(T)) ] = std::move(instancia);
    }

    template <typename T>
    std::shared_ptr<T> obtenha() const
    {
        auto dependencia = container.find(std::type_index(typeid(T)));
        if (dependencia != container.end())
        {
            if (auto ptr =
                    std::any_cast<std::shared_ptr<T>>(&dependencia->second))
            {
                return *ptr;
            }
        }

        throw std::runtime_error("Dependência do tipo '" +
                                 std::string(typeid(T).name()) +
                                 "' não encontrada no contexto");
    }
};

// Handler de uma rota
using HandlerFunction = std::function<void(Contexto&)>;

/// @brief Representa uma rota para alguma funcionalidade do sistema.
class Rota
{
  private:
    std::string nome;
    HandlerFunction handler;

  public:
    Rota(std::string nome, HandlerFunction handler);
    const std::string& obtenhaNome() const;
    const HandlerFunction& obtenhaHandler() const;
};

/// @brief Roteador do sistema
class Aplicativo
{
  private:
    std::unordered_map<std::string, std::unique_ptr<Rota>> rotas;
    std::shared_ptr<Contexto> contexto;
    void exibaMensagemPadrao();

  public:
    Aplicativo();

    void listeAsRotas();
    void
    registrarRota(std::string chave, std::string nome, HandlerFunction handler);
    void executarRota(std::string& chave);

    std::shared_ptr<Contexto> obtenhaContextoMutavel();
    std::shared_ptr<Contexto> obtenhaContexto() const;

    void rodar();
};

} // namespace Roteador
