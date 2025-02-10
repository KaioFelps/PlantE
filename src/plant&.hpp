#pragma once

#include <iostream>
#include <vector>

/**cabecario */
class Administrador;
class Moderador;
class Usuario;
class Terreno;
class Postagens;
class Produto;

enum Clima {
    TROPICAL,
    SUBTROPICAL,
    TEMPERADO,
    ARIDO,
    SEMIARIDO,
    MEDITERRANEO,
    EQUATORIAL
};

enum ExposicaoSolar {
    SOMBRA,
    MEIASOMBRA,
    SOLPELNO
};	

enum EstadoDenuncia {
    PENDENTE,
    ANALISE,
    RESOLVIDO
};

enum MotivoDenuncia {
    CYBERBULLYING,
    DISCURSODEODIO,
    INDUÇÃOAOERRO,
    CONTEUDOINAPROPRIADO,
    SPAM,
    OUTRO,
};

enum CategoriaDeProduto {
    FERRAMENTA, 
    ADUBO,
    SEMENTE,
    PLANTA,
    PLANTADECASA
};

class Adminstrador {
    std::string email = "";
    std::string hashSenha = "";
    public:
        std::string emailStaff() {return this ->email;}
        std::string senhaStaff() {return this ->hashSenha;}
};

class Moderador {
    std::string email = "";
    std::string hashSenha = "";
    public:
        std::string emailStaff() {return this ->email;}
        std::string senhaStaff() {return this ->hashSenha;}
};

class Usuario {
    std::string nome = "";
    std::string email = "";
    std::string hashsenha = "";
    std::string dataNascimento = "";
    public:
        std::string nomeUsuario() {return this ->nome;}
        std::string emailUsuario() {return this ->email;}
        std::string senhaUsuario() {return this ->hashsenha;}
        std::string dataNascimentoUsuario() {return this ->dataNascimento;}

};

class Terreno {

};

class Postagem {

};

class Produto {

};



