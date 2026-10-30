# Estrutura de Dados em C

Repositório com implementações de estruturas de dados feitas em C durante a disciplina de **Estrutura de Dados**, na faculdade (Estácio).

## Estruturas implementadas

| Estrutura | Arquivo | Descrição |
|-----------|---------|-----------|
| Árvore Binária de Busca | `ArvoreBinaria.c` | Inserção, remoção e percursos (pré-ordem, em ordem e pós-ordem) |
| Fila circular (vetor) | `FilaCircular.c` | Fila com vetor de tamanho fixo, enfileira e desenfileira com controle circular |
| Fila linear (vetor) | `FilaLinear.c` | Fila simples com vetor de tamanho fixo |
| Lista encadeada | `ListaEncadeada.c` | Criação da lista com inserção no final, impressão e liberação de memória |

## Pré-requisitos

- Compilador C (GCC)
  - Windows: [MSYS2](https://www.msys2.org) com o pacote `mingw-w64-ucrt-x86_64-gcc`
  - Linux / WSL: `sudo apt install build-essential`
- VS Code (opcional), com a extensão C/C++

Pra conferir se está tudo certo:

```bash
gcc --version
```

## Como compilar e executar

```bash
gcc ArvoreBinaria.c -o ArvoreBinaria
./ArvoreBinaria
```

No Windows (PowerShell), o executável roda assim:

```powershell
.\ArvoreBinaria.exe
```

O mesmo vale pros outros arquivos: troque o nome pelo do arquivo que quiser testar.

## Como usar

### Árvore Binária

O programa abre um menu no terminal:

```
1 - Inserir
2 - Excluir
3 - Pré-ordem
4 - Em ordem
5 - Pós-ordem
6 - Sair
```

### Filas

O programa pede 10 valores, enfileira todos e depois desenfileira mostrando na ordem de saída (primeiro a entrar, primeiro a sair).

### Lista encadeada

O programa pergunta quantos nós a lista terá, pede os valores um por um e mostra a lista no final.

## Estrutura do repositório

```
.
├── ArvoreBinaria.c
├── FilaVetor.c
├── FilaLinear.c
├── ListaEncadeada.c
└── README.md
```
