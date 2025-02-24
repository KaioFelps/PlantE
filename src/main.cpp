#include "dominio/identidade/entidades/usuario.hpp"
//#include "dominio/terrenos/entidades/solo.hpp"
#include "dominio/terrenos/entidades/terreno.hpp"
#include "login.hpp"
#include <ctime>
#include <iostream>
#include <vector>

using namespace Terrenos::Entidades;
using namespace Identidade::Entidades;
using namespace Identidade::Enums;
using namespace std;

int main()
{
    vector<Identidade::Entidades::Usuario*> usuarios;
    usuarios.push_back(new Identidade::Entidades::Usuario("João Silva", "joao@example.com", "hash123", time(nullptr), Identidade::Enums::Cargo::USUARIO));
    usuarios.push_back(new Identidade::Entidades::Usuario("Maria Souza", "maria@example.com", "hash456", time(nullptr), Identidade::Enums::Cargo::ADMINISTRADOR));


    
    string email, hashDaSenha;
    cout << "Digite o email: ";
    cin >> email;
    cout << "Digite o hash da senha: ";
    cin >> hashDaSenha;
 
    if (fazerLogin(usuarios, email, hashDaSenha))
    {
        
        char resposta;
        cout << "Deseja ver o terreno? (s/n): ";
        cin >> resposta;
 
        if (resposta == 's' || resposta == 'S')
        {
             
            Terrenos::Entidades::Terreno terreno(100, 200); 
            cout << "Terreno criado com sucesso!" << endl;
            cout << "Largura: " << terreno.obtenhaLargura() << " metros" << endl;
            cout << "Comprimento: " << terreno.obtenhaComprimento() << " metros" << endl;
            cout << "Tamanho total: " << terreno.obtenhaTamanho() << " metros quadrados" << endl;
 
            
            Terrenos::Entidades::Solo* solo = new Terrenos::Entidades::Solo(50, 70, 30, 40, 60, 20, 10);
            terreno.atualizeSolo(solo);
 
            if (terreno.obtenhaSolo().has_value())
            {
                cout << "Informações do solo:" << endl;
                cout << "Acidez: " << (int)terreno.obtenhaSolo().value()->obtenhaAcidez() << endl;
                cout << "Índice de Minerais: " << (int)terreno.obtenhaSolo().value()->obtenhaIndiceDeMinerais() << endl;
                cout << "Índice de Salinidade: " << (int)terreno.obtenhaSolo().value()->obtenhaIndiceDeSalinidade() << endl;
                cout << "Índice de Argila: " << (int)terreno.obtenhaSolo().value()->obtenhaIndiceDeArgila() << endl;
                cout << "Índice de Areia: " << (int)terreno.obtenhaSolo().value()->obtenhaIndiceDeAreia() << endl;
                cout << "Índice de Silite: " << (int)terreno.obtenhaSolo().value()->obtenhaIndiceDeSilite() << endl;
                cout << "Carga Elétrica: " << (int)terreno.obtenhaSolo().value()->obtenhaCargaEletrica() << endl;
            }
            else
            {
                cout << "Nenhum solo associado ao terreno." << endl;
            }
        }
        else
        {
            cout << "Ok, você escolheu não ver o terreno." << endl;
        }
    }
    else
    {
        cout << "Falha no login." << endl;
    }
 
    
    for (Identidade::Entidades::Usuario* usuario : usuarios)
    {
        delete usuario;
    }
 
    return 0;
}

