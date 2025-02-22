#pragma once

#include "./solo.hpp"
#include <memory>
#include <optional>

using namespace std;

namespace Terrenos::Entidades
{

class Terreno
{
  private:
    unsigned int largura;
    unsigned int comprimento;
    optional<std::unique_ptr<Solo>> solo;

  public:
    Terreno(unsigned int largura, unsigned int comprimento);
    unsigned int obtenhaLargura() const;
    unsigned int obtenhaComprimento() const;
    unsigned int obtenhaTamanho() const;
    const optional<unique_ptr<Solo>>* obtenhaSolo() const;

    void atualizeSolo(std::unique_ptr<Solo> solo);
};

} // namespace Terrenos::Entidades
