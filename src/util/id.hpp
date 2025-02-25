#pragma once

#include <string>

// Observação: classes utilitárias não deveriam ser instanciadas nem extendidas.
// Fazer classes com membros estáticos para servirem de classes "utilitárias" é
// uma solução que, porém, permite esse comportamento inesperado.
//
// Uma alternativa é combinar namespaces com simples funções.
// Leia: https://stackoverflow.com/a/112451/20361836

namespace Utils::GeradorDeId
{

std::string gerarUUID();

} // namespace Utils::GeradorDeId
