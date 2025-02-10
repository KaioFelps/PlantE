#pragma once

#include <iostream>
#include <vector>

/**cabecario */
class Postagens;
class Produto;

enum Clima
{
    TROPICAL,
    SUBTROPICAL,
    TEMPERADO,
    ARIDO,
    SEMIARIDO,
    MEDITERRANEO,
    EQUATORIAL
};

enum ExposicaoSolar
{
    SOMBRA,
    MEIASOMBRA,
    SOLPELNO
};

enum EstadoDenuncia
{
    PENDENTE,
    ANALISE,
    RESOLVIDO
};

enum MotivoDenuncia
{
    CYBERBULLYING,
    DISCURSODEODIO,
    INDUCAO_AO_ERRO,
    CONTEUDOINAPROPRIADO,
    SPAM,
    OUTRO,
};

enum CategoriaDeProduto
{
    FERRAMENTA,
    ADUBO,
    SEMENTE,
    PLANTA,
    PLANTADECASA
};

class Postagem
{
};

class Produto
{
};
