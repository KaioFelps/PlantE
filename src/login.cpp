#include "login.hpp"
#include <iostream>

using namespace std;


Identidade::Entidades::Usuario* buscarUsuarioPorEmail(const vector<Identidade::Entidades::Usuario*>& usuarios, const string& email)
{
    for (Identidade::Entidades::Usuario* usuario : usuarios)
    {
        if (*usuario->obtenhaEmail() == email)
        {
            return usuario;
        }
    }
    return nullptr; 
}


bool fazerLogin(const vector<Identidade::Entidades::Usuario*>& usuarios, const string& email, const string& hashDaSenha)
{
    Identidade::Entidades::Usuario* usuario = buscarUsuarioPorEmail(usuarios, email);

    if (usuario == nullptr)
    {
        cout << "Usuário não encontrado!" << endl;
        return false;
    }

  
    if (*usuario->obtenhaHashDaSeha() == hashDaSenha)
    {
        cout << "Login bem-sucedido! Bem-vindo, " << *usuario->obtenhaNome() << "!" << endl;
        return true;
    }
    else
    {
        cout << "Senha ou Email incorreta!" << endl;
        return false;
    }
}