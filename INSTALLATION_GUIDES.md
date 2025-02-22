# Guias de Instalação
Confira instruções de como configurar e instalar os principais componentes para compilar
e rodar este sistema (e qualquer outra aplicação em C++).

# cmake
CMake é a ferramenta utilizada para montar o arquivo de compilação da aplicação, bem como "linkar"
as bibliotecas das quais o presente sistema necessita para funcionar.

Baixe o CMake diretamente do seu site oficial (https://cmake.org/download/).

Se utilizando o Linux, recomenda-se que baixe o código fonte e compile por conta própria:
1. Baixe o código fonte e descompacte em um diretório qualquer;
2. Entre no diretório descompactado;
3. Rode o script bootstrap (`./boostrap`);
4. Rode o comando `make -j$(nproc)`;
5. Rode o comando `sudo make install`;
6. Rode o comando `cmake --version` para conferir se foi instalado corretamente (pode ser necessário
fechar e abrir o terminal para que comece a funcionar).

No Windows, basta baixar um instalador (como o arquivo `cmake-3.31.5-windows-x86_64.msi`) e executá-lo.

Confira mais detalhes em: https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line.

# vcpkg
VCPkg é um gerenciador de dependências. É necessário para instalar as bibliotecas necessárias para que o
programa seja compilado.

Note que, enquanto o CMake é responsável por "linkar" e compilar, o vcpkg é quem baixa as bibliotecas para
que possam ser "linkadas".

1. Em um diretório qualquer, baixe o repositório oficial do vcpkg (`git clone https://github.com/microsoft/vcpkg.git`);
2. Entre no diretório criado (`cd vcpkg`);
3. Rode o script de bootstrap:
    a. `./bootstrap-vcpkg.sh`, se estiver no Linux;
    b. `.\bootstrap-vcpkg.bat`, se estiver no Windows.

Mova o diretório inteiro para algum outro diretório no seu explorador de arquivos, onde não seja deletado.
No Windows, pode ser uma boa ideia movê-lo para o diretório `Arquivos de Programas`. No Linux, talvez
o diretório `/opt` seja uma opção.

Para chamar o executável diretamente (por exemplo, `vcpkg --version`), é necessário configurar as variáveis
de ambiente.

## Windows
Se estiver no Windows, confira [estas instruções sobre como alterar a variável de ambiente `PATH`].
Abra a janela para editar a variável de ambiente PATH e adicione uma nova linha contendo o caminho
para o diretório clonado do github (por exemplo, `C:\Program Files\vcpkg`).

Veja [este vídeo] para uma demonstração de como adicionar o caminho à variável `PATH`.

[este vídeo]: https://youtu.be/FeBzSYiWkEU?t=149
[estas instruções sobre como alterar a variável de ambiente `PATH`]: https://pt.stackoverflow.com/questions/5024/como-mudar-o-path-nos-windows

## Linux
Edite o arquivo `~/.bashrc` (utlizando VIM ou algum editor de texto qualquer) e adicione, no final do arquivo,
as seguintes novas linhas:

```bashrc
export VCPKG_ROOT=/path/to/vcpkg # substitua /path/to/vcpkg pelo caminho correto. Por exemplo, /opt/vcpkg
export PATH=$VCPKG_ROOT:$PATH
```

Digite o comando `vcpkg --version` para verificar se o gerenciador de pacotes foi corretamente instalado
e configurado.

# CMake User Presets
Caso não tenha copiado o presets, agora é a hora:
```bash
cp CMakeUserPresets.example.json CMakeUserPresets.json
```

Dentro deste arquivo, substitua `"<path to vcpkg>"` pelo caminho correto do diretório vcpkg.
Por exemplo, `C:\Program Files\vcpkg` ou `/opt/vcpkg`, depende de onde você posicionou o diretório.
