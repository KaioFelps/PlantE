# Plant&

## Requisitos
- [x] Implementar ao menos 1 caso de uso;
- [x] Implementar 8 operações dos contratos de operações;
- [x] Código orientado a objetos;
- [x] Compila e executa.

### Casos de usos
- [x] Inserir Resultado da Análise do Solo;
- [ ] Realizar Denúncia;
- [ ] Investigar Denúncia;
- [ ] Resolver Denúncia;
- [ ] Adicionar Nova Plantação.

### Operações implementadas
**Dos casos de uso**
- [x] `listeTerrenos`;
- [x] `recebaDadosDoSolo`;
- [x] `denuncie`;
- [x] `listeDenuncias`;
- [x] `marqueComoInvestigando`;
- [x] `marqueComoResolvida`;
- [x] `listePlantas`;
- [x] `adicionePlantacao`;

**Extras**
- [x] `obtenhaSugestoes`;
- [x] `finalizePlantacao`;
- [x] `desistaDaPlantacao`;
- [x] `denuncie`;
- [x] `obtenhaDenuncia`.

## Primeiros passos
Para rodar o projeto, são necessárias ferramentas para baixar as dependências do sistema,
vinculá-las, e compilar tudo.

Siga o [Guia de Instalação] para instruções e referências de como configurar os softwares
necessários para isso.

[Guia de Instalação]: ./INSTALLATION_GUIDES.md

## Rodando a aplicação
Observe que os primeiros passos são essenciais para rodar a aplicação. Se tudo estiver
corretamente configurado, digite os seguintes comandos no seu terminal:

```shell
cmake --preset=default # configura o CMake utilizando o preset do vcpkg
cmake --build build # compila e roda a aplicação
./build/PlantE --seed # a flag seed pré-popula todos os vetores de armazenamento dos DAOs
```

## Contribuindo

Para contribuir com o desenvolvimento do sistema, leia as instruções na [Guia de Contribuição],
bem como os detalhes sobre a **arquitetura** do sistema, **padrões** de código, **configuração do ambiente
de desenvolvimento**, entre outras informações.

[Guia de Contribuição]: ./CONTRIBUTING.md
