#pragma once

#include "./solo.hpp"
#include <optional>

using namespace std;

namespace Terrenos::Entidades
{

class Terreno
{
  private:
    unsigned int largura;
    unsigned int comprimento;
    optional<Solo*> solo;

  public:
    Terreno(unsigned int largura, unsigned int comprimento);
    ~Terreno();
    unsigned int obtenhaLargura() const;
    unsigned int obtenhaComprimento() const;
    unsigned int obtenhaTamanho() const;
    optional<Solo*> obtenhaSolo() const;
    void atualizeSolo(Solo* solo);
};

} // namespace Terrenos::Entidades
