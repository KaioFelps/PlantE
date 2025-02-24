#pragma once

#include <vector>
#include <string>
#include "dominio/identidade/entidades/usuario.hpp"

using namespace std;

namespace Identidade::Entidades
{
    class Usuario; 
}

Identidade::Entidades::Usuario* buscarUsuarioPorEmail(const vector<Identidade::Entidades::Usuario*>& usuarios, const string& email);
bool fazerLogin(const vector<Identidade::Entidades::Usuario*>& usuarios, const string& email, const string& hashDaSenha);
