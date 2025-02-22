# Guia de Contribuição

Siga as instruções listadas neste documento para garantir a padronização do código fonte do sistema.

## Setup
Antes de começar, instale as extensões e softwares necessários para o desenvolvimento:  
1. Se estiver utilizando Windows, recomenda-se utilizar [WSL2] para compilar e rodar os arquivos C++;
2. Instale o g++ (`sudo apt-get install g++`) para compilar e rodar o código;
3. Instale a extensão [C/C++ Extension Pack] para obter intellisense ao programar com C++;
4. Instale o `cmake` (veja as [instruções de instalação do cmake]);
5. Instale o vcpkg (veja as [instruções de instalação do vcpkg]);
6. Instale [clang-format] (`sudo apt-get install clang-format-14`) para formatar o código;
7. Instale clang-tidy (`sudo apt-get install clang-tidy-14`) para garantir os padrões do código.

### Configurando o cmake
Para configurar o **cmake**, primeiro copie o json de exemplo com o comando abaixo.
```bash
cp CMakeUserPresets.example.json CMakeUserPresets.json
```

Abrindo o json, substitua o valor `"<path to vcpkg>"` do campo `"VCPKG_ROOT"` pelo caminho até o
diretório que contém o binário do vcpkg. Exemplo: `"/opt/vcpkg"`.

Se ainda não configurou o vcpkg, confira as [instruções de instalação do vcpkg].

### Configurando a extensão do vscode
Copie as configurações de exemplo para configurações reais utilizando o comando abaixo:
```bash
cp .vscode/settings.example.json .vscode/settings.json
```

### Dependências e como rodar o projeto
Confira as instruções do arquivo [README.md](./README.md) para instalar todas as bibliotecas necessárias
e compilar a aplicação.

[WSL2]: https://learn.microsoft.com/pt-br/windows/wsl/install
[C/C++ Extension Pack]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
[clang-format]: https://terminalroot.com.br/2023/07/formate-seu-codigo-com-clang-format.html
[instruções de instalação do cmake]: ./INSTALLATION_GUIDES.md#cmake
[instruções de instalação do vcpkg]: ./INSTALLATION_GUIDES.md#vcpkg

## Padrões de código
- Todos os nomes devem estar em **português**;
- Nomes de pastas, arquivos, variáveis, métodos e de classes **não devem conter acentos nem espaços**;
- Nomes de pastas e arquivos devem seguir o padrão **[snake_case]** (por exemplo: `./criar_novo_usuário.cpp`);
- Variáveis, propriedades e métodos devem utilizar o padrão **[camelCase]** (por exemplo: `obtenhaTerreno()`);
- Nomes de classes, enums e workspaces devem utilizar o padrão **[PascalCase]** (por exemplo: ``class FooBar {};`);
- Constantes (globais ou não) devem utilizar **[screaming snake case]** (por exemplo: `IDADE_MÍNIMA`);
- Escopos devem seguir o padrão **[Allman]**;
- O código deve ser identado como 4 espaços.


[snake_case]: https://www.alura.com.br/artigos/convencoes-nomenclatura-camel-pascal-kebab-snake-case#tabela
[screaming snake case]: https://www.alura.com.br/artigos/convencoes-nomenclatura-camel-pascal-kebab-snake-case#tabela
[Allman]: https://en.wikipedia.org/wiki/Indentation_style#Allman_style
[camelCase]: https://www.alura.com.br/artigos/convencoes-nomenclatura-camel-pascal-kebab-snake-case#tabela
[PascalCase]: https://www.alura.com.br/artigos/convencoes-nomenclatura-camel-pascal-kebab-snake-case#tabela

## Estrutura de pastas
Todo arquivo -- `.hpp` ou `.cpp` -- deve estar dentro do diretório `src/`, mais especificamente, dentro
do diretório do seu domínio e da sua categoria.

### Domínios

O sistema é dividido em domínios:
| Domínio       | Descrição                                         |
|---            |---                                                |
| Identidade    | Autenticação e autorização de usuários no sistema |
| Moderação     | Regras de conduta dentro do sistema               |
| Terreno       | Manejo de terrenos e solos de usuários            |
| Plantas       | Plantas registradas no sistema                    |
| Feed          | Feed/Timeline da aplicação                        |

Os arquivos são classificados de acordo com sua responsabilidade, e logo, armazenados dentro do respectivo
diretório dentro do domínio ao qual pertence:

| Tipo de classe    | Diretório | Responsabilidade  |
| ---               | ---       | ---               |
| Entidades                 | `entidades/`      | São classes que representam entidades do sistema. Por exemplo, `Usuário` ou `Terreno`. |
| Data Access Object        | `dao/`            | São classes que atuam como repositórios, servindo como acesso para o armazenamento de uma entidade específica (seja para criar, atualizar, remover ou buscá-la).   |
| Data Validation Object    | `dvo/`            | São classes responsáveis por validar os dados de uma entidade. Por exemplo, ela pode garantir que determinada propriedade esteja sempre dentro de um intervalo específico, como idade. |
| Casos de Uso              | `casos_de_uso/`   | São classes responáveis por executar um caso de uso do sistema. |
| Gerentes                  | `gerentes/`      | São classes que atuam como "factories" (fábricas), responsáveis por instanciar e ceder instâncias de um determinado conteúdo. |

### Infraestrutura
Serviços externos devem ser alocados no diretório `infra/`. Por exemplo, implementações de DAOs devem ser
posicionados dentro desta pasta.

### Exemplo
Considerando casos de uso responssáveis pela autenticação no sistema, teríamos a seguinte estrutura:
```plain
src/
... dominios/
...... identidade/
......... entidades/
............ usuario.cpp
............ usuario.hpp
......... dao/
............ usuarios_dao.hpp (apenas a *interface* de um DAO)
......... dvo/
............ usuario_dvo.hpp
............ usuario_dvo.cpp
......... casos_de_uso/
............ casos_de_uso_de_usuarios.hpp
............ crie_usuario.cpp
............ atualize_usuario.cpp
............ remova_usuario.cpp
............ ache_varios_usuarios.cpp
............ encontre_usuario.cpp
... infra/
...... dao/
......... em_memoria/
............ mem_usuarios_dao.cpp (implementação do DAO dos usuários em memória)
......... jdbc/
............ jdbc_usuarios_dao.cpp (implementação do DAO dos usuários utilizandoo JDBC, por exemplo)
```
