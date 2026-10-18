# LPEDC · Lógica de Programação, Estrutura de Dados e C

Material de estudo pessoal para **relembrar lógica de programação**, **aprender
estrutura de dados** e **entender de verdade como a linguagem C funciona**: a
memória, os ponteiros, a compilação e o custo de cada escolha.

Segue a filosofia do [LPPOO](https://github.com/jhollyfer/LPPOO). Cada assunto
conta **um exemplo só**, em quatro partes que batem entre si: o texto, o
**diagrama da ideia**, o código e o **fluxograma**. Depois vêm os exemplos para
rodar e os exercícios.

## Como preparar o computador

```bash
sudo pacman -S --needed base-devel gdb valgrind git     # Arch Linux
sudo apt install build-essential gdb valgrind git       # Debian / Ubuntu
git clone https://github.com/jhollyfer/LPEDC ~/LPEDC
```

No Windows, use o WSL com Ubuntu (`wsl --install` no PowerShell) e siga a
linha do Debian/Ubuntu dentro dele. No macOS, `xcode-select --install` instala
o compilador (`clang`, que aceita os mesmos comandos).

## Como rodar um arquivo

```bash
~/LPEDC/rodar 01-fundamentos/0002-variaveis/A003.c
```

O `rodar` compila com `gcc -std=c17 -Wall -Wextra -pedantic` e com o
**AddressSanitizer**, que para o programa e aponta a linha quando você acessa
memória que não devia ou esquece um `free`. O caminho pode ser relativo ao
LPEDC, à pasta atual ou absoluto. Outros usos:

```bash
printf '25\n' | ~/LPEDC/rodar 01-fundamentos/0006-scanf/A011.c   # já manda a entrada
~/LPEDC/rodar --valgrind 07-memoria-dinamica/0054-malloc-free/A107.c
~/LPEDC/rodar 09-arquivos/0069-argumentos/A137.c um dois tres     # argumentos do programa
```

Os arquivos têm nome curto e numeração única no curso inteiro:

- `A001.c`, `A002.c`... são os **exemplos** resolvidos;
- `E001.c`, `E002.c`... são os **exercícios**: a resposta vai dentro do próprio
  arquivo, embaixo de `// Escreva sua resposta abaixo:`;
- `_respostas/` tem uma resolução de cada exercício. Só olhe **depois** de
  tentar de verdade.

Cada assunto tem 2 exemplos e 6 exercícios: ★☆☆ é aquecimento, ★★☆ pede
raciocínio e ★★★ é desafio. Cada módulo termina com uma lista de **desafios**
que misturam tudo.

## Como cada módulo funciona

```
01-fundamentos/
├── README.md          o módulo inteiro: é por ele que você estuda
└── 0002-variaveis/    um assunto
    ├── ideia.svg      o diagrama da ideia
    ├── fluxograma.svg o caminho que o programa faz
    ├── A003.c A004.c  exemplos: rode, mude, quebre, rode de novo
    └── E007.c ...     exercícios
```

O caminho de cada assunto:

1. Leia o assunto no `README.md` do módulo e tente responder a **Pergunta para
   você** antes de rodar.
2. Rode os exemplos e mexa neles à vontade.
3. Faça os exercícios. Travou? As dicas estão logo abaixo do enunciado, no
   README e no topo do arquivo.

As formas e as cores dos desenhos:

<p align="center"><img src="legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Os módulos

| Módulo | Assuntos | O que você sai sabendo |
| --- | --- | --- |
| [01 · Fundamentos de C](01-fundamentos/README.md) | 0001–0011 | variáveis, tipos, limites, `printf`, `scanf`, operadores, conversão |
| [02 · Decisões](02-condicionais/README.md) | 0012–0019 | relacionais, lógicos, `if`, `else if`, ternário, `switch` |
| [03 · Laços](03-repeticoes/README.md) | 0020–0027 | `while`, `do...while`, `for`, `break`, padrões de laço, aleatórios |
| [04 · Funções](04-funcoes/README.md) | 0028–0036 | funções, escopo, pilha de chamadas, recursão, módulos `.h`/`.c`, macros |
| [05 · Vetores e strings](05-vetores-e-strings/README.md) | 0037–0043 | vetores, matrizes, caracteres, strings, leitura segura |
| [06 · Ponteiros](06-ponteiros/README.md) | 0044–0052 | endereços, `*` e `&`, aritmética, ponteiro para ponteiro e para função |
| [07 · Memória dinâmica](07-memoria-dinamica/README.md) | 0053–0058 | stack e heap, `malloc`, `realloc`, `free`, valgrind e ASan |
| [08 · Tipos compostos](08-structs/README.md) | 0059–0066 | `struct`, `typedef`, `enum`, `union`, operações com bits |
| [09 · Arquivos](09-arquivos/README.md) | 0067–0070 | arquivos texto e binários, `argc` e `argv` |
| [10 · Análise de algoritmos](10-analise/README.md) | 0071–0074 | contar passos, Big-O, invariantes, tipo abstrato de dado |
| [11 · Listas](11-listas/README.md) | 0075–0081 | vetor dinâmico, listas encadeadas simples, dupla e circular |
| [12 · Pilhas e filas](12-pilhas-e-filas/README.md) | 0082–0088 | pilha, fila circular, deque e suas aplicações |
| [13 · Busca e ordenação](13-busca-e-ordenacao/README.md) | 0089–0101 | busca binária, bubble, selection, insertion, merge, quick |
| [14 · Árvores](14-arvores/README.md) | 0097–0104 | árvore binária, BST, AVL, heap, heapsort |
| [15 · Tabelas hash](15-hash/README.md) | 0110–0108 | função hash, encadeamento, endereçamento aberto |
| [16 · Grafos](16-grafos/README.md) | 0109–0113 | representação, BFS, DFS, Dijkstra |

O sumário detalhado, assunto por assunto, está em
[`_fontes/sumario.md`](_fontes/sumario.md).

## De onde veio o conteúdo

O texto, os exemplos e os exercícios foram escritos do zero, tomando como
referência os fichamentos em [`_fontes/`](_fontes/) dos materiais abaixo:

- BACKES, A. *Linguagem C: completa e descomplicada*. Elsevier, 2013 (e a apostila *Linguagem C: descomplicada*).
- DEITEL, P.; DEITEL, H. *C: como programar*. Pearson.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Elsevier, 2009.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. PUC-Rio, 2002.
- TENENBAUM, A.; LANGSAM, Y.; AUGENSTEIN, M. *Estruturas de dados usando C*. Makron Books.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Universidade de Aveiro.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Unicesumar.
- CARVALHO, V. A. *Lógica de programação*. IFES.
- ANTONELLO, R. *Linguagem C*.
- HARA, C.; ZOLA, W.; DELGADO, A. L. N. *Linguagem C: notas de aula*. UFPR, 2008.
- MARTINS, L. G. A. *Apostila de linguagem C*. UFU.
- SENAI-RS. *Fundamentos de linguagem C*. 1997.
- UNICAMP. *Introdução à linguagem C*. Centro de Computação.
- Apostila "slago" de C e o apêndice *Manual de sintaxe da linguagem C*.

## Para quem for mexer no material

Os READMEs dos módulos e os SVGs são gerados. O guia de escrita está em
[`CLAUDE.md`](CLAUDE.md) e o gerador em [`_gerador/`](_gerador/):

```bash
cd _gerador && npm install
npm run gerar           # tudo
npm run gerar -- 03-    # só o módulo 03
node ver.mjs ../03-repeticoes/0020-while/ideia.svg   # vira PNG para conferir
```

A fonte Excalifont (`_gerador/fonte/`) vem do projeto Excalidraw e usa a
licença SIL Open Font License.
