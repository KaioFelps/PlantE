#pragma once

#include "./solo.hpp"
#include <memory>
#include <optional>

namespace Terrenos::Entidades
{

class Terreno
{
  private:
    unsigned int largura;
    unsigned int comprimento;
    std::optional<std::unique_ptr<Solo>> solo;

  public:
    Terreno(unsigned int largura, unsigned int comprimento);
    unsigned int obtenhaLargura() const;
    unsigned int obtenhaComprimento() const;
    unsigned int obtenhaTamanho() const;
    const std::optional<std::unique_ptr<Solo>>* obtenhaSolo() const;

    void atualizeSolo(std::unique_ptr<Solo> solo);
};

} // namespace Terrenos::Entidades
