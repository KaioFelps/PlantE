namespace Identidade::Enums
{

enum Cargo
{
    USUARIO,
    MODERADOR,
    ADMINISTRADOR,
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

}
