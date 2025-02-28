#include "inserir_resultado_de_analise_de_solo.hpp"

namespace Terrenos::CasosDeUso
{

InserirResultadoDeAnaliseDeSolo::InserirResultadoDeAnaliseDeSolo(
    Gerentes::GerenteDeTerrenos gerenteDeTerrenos_)
    : gerenteDeTerrenos(std::move(gerenteDeTerrenos_))
{
}

void InserirResultadoDeAnaliseDeSolo::executar(const std::string& idUsuario)
{
    auto terrenos = this->gerenteDeTerrenos.listeTerrenos(idUsuario);

    std::cout << "Listando todos os seus terrenos:\n";
    for (const auto& terreno : terrenos)
    {
        std::cout << "ID: " << terreno.obtenhaId();
        std::cout << "\nComprimento: " << terreno.obtenhaComprimento();
        std::cout << "\nLargura: " << terreno.obtenhaLargura();
        std::cout << "\nTem plantação ativa?: "
                  << (terreno.obtenhaPlantacaoAtiva() ? "Sim" : "Não");
        std::cout << "\n==============\n\n";
    }

    std::cout << "Escolha um terreno pelo ID para atualizar as informações do "
                 "solo:\n> ";

    std::string idTerreno;
    float acidez;
    unsigned char indiceDeMinerais;
    unsigned char indiceDeSalinidade;
    unsigned char indiceDeArgila;
    unsigned char indiceDeSilte;
    unsigned char cargaEletrica;

    int temp;

    std::cin >> idTerreno;
    std::cout << "Selecionado o terreno de id: \"" << idTerreno << "\".\n";

    std::cout << "Qual a acidez do solo?\n> ";
    std::cin >> acidez;

    std::cout << "Qual o índice de minerais do solo?\n> ";
    std::cin >> temp;
    indiceDeMinerais = static_cast<unsigned char>(temp);

    std::cout << "Qual o índice de argila do solo?\n> ";
    std::cin >> temp;
    indiceDeArgila = static_cast<unsigned char>(temp);

    std::cout << "Qual o índice de silte do solo?\n> ";
    std::cin >> temp;
    indiceDeSilte = static_cast<unsigned char>(temp);

    std::cout << "Qual a carga elétrica do solo?\n> ";
    std::cin >> temp;
    cargaEletrica = static_cast<unsigned char>(temp);

    try
    {

        this->gerenteDeTerrenos.recebaDadosDoSolo(idTerreno,
                                                  acidez,
                                                  indiceDeMinerais,
                                                  indiceDeSalinidade,
                                                  indiceDeArgila,
                                                  indiceDeSilte,
                                                  cargaEletrica);
    }
    catch (const std::invalid_argument& erro)
    {
        std::cout << "Você forneceu algum dado incorreto: " << erro.what()
                  << ". Tente novamente.\n";
    }
    catch (const std::range_error& erro)
    {
        std::cout << "Você forneceu algum valor fora do intervalo permitido: "
                  << erro.what() << ". Tente novamente.\n";
    }
}

} // namespace Terrenos::CasosDeUso
