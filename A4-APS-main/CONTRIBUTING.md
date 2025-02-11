# Guia de Contribuição

Siga as instruções listadas neste documento para garantir a padronização do código fonte do sistema.

## Setup
Antes de começar, instale as extensões necessárias para o desenvolvimento:  
1. Se estiver utilizando Windows, recomenda-se utilizar [WSL2] para compilar e rodar os arquivos C++;
2. Instale o g++ (`sudo apt-get install g++`) para compilar e rodar o código;
3. Instale a extensão [C/C++ Extension Pack] para obter intellisense ao programar com C++;
4. Instale [clang-format] (`sudo apt-get install clang-format`) para formatar o código;
5. Instale bear (`sudo apt-get install bear`) para gerar um banco de dados de compilação utilizando o Makefile;
6. Instale clang-tidy (`sudo apt-get install clang-tidy`) para garantir os padrões do código.

Por fim, rode os comandos abaixo para configurar o ambiente de desenvolvimento:
```bash
# gera o arquivo build/compile_commands.json
# para que o clang-tidy possa analisar o código e formatá-lo
./tidy.sh
# copia as configurações das extensões
cp .vscode/settings.example.json .vscode/settings.json
```

[WSL2]: https://learn.microsoft.com/pt-br/windows/wsl/install
[C/C++ Extension `Pack]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
[clang-format]: https://terminalroot.com.br/2023/07/formate-seu-codigo-com-clang-format.html

## Padrões de código
- Todos os nomes devem estar em **português**;
- Nomes de pastas, arquivos, variáveis, métodos e de classes **não devem conter acentos nem espaços**;
- Nomes de pastas e arquivos devem seguir o padrão **[snake_case]** (por exemplo: `./criar_novo_usuário.cpp`);
- Variáveis, propriedades e métodos devem utilizar o padrão **[camelCase]** (por exemplo: `obtenhaTerreno()`);
- Nomes de classes, enums e workspaces devem utilizar o padrão **[PascalCase]** (por exemplo: ``class FooBar {};`);
- Constantes (globais ou não) devem utilizar **[screaming snake case]** (por exemplo: `IDADE_MÍNIMA`);
- Escopos devem seguir o padrão **[Allman]**;
- O código deve ser identado como 4 espaços.


[snake case]: https://www.alura.com.br/artigos/convencoes-nomenclatura-camel-pascal-kebab-snake-case#tabela
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
| Gerentes                  | `gerentess/`      | São classes que atuam como "factories" (fábricas), responsáveis por instanciar e ceder instâncias de um determinado conteúdo. |

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
