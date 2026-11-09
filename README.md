# LPEDC · Lógica de Programação, Estrutura de Dados e C

Material de estudo pessoal para relembrar lógica de programação, aprender
estrutura de dados e entender de verdade como a linguagem C funciona: a
memória, os ponteiros, a compilação e o custo de cada escolha.

> [!IMPORTANT]
> **Preparação para o Mestrado do PPGI/UFAM.** O curso está alinhado à Prova de
> Conhecimentos do edital 070/2026 (prova em 27/11/2026). O guia
> [`PPGI.md`](PPGI.md) liga cada tópico do edital e do cursinho do PPGI ao
> assunto que o ensina. Para estudar até a prova, comece pelo
> [plano dia a dia](PPGI.md#comece-aqui).

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
raciocínio e ★★★ é desafio. Cada módulo termina com uma **lista prática** de
30 exercícios de codificar (pasta `lista/`, arquivos `P????.c`, resoluções em
`_respostas/<modulo>/lista/`), uma lista de **desafios** que misturam tudo e
**questões no estilo da prova** do PPGI, com gabarito comentado.

No total: 378 exemplos, 1134 exercícios por assunto, 870 exercícios nas listas
práticas e cerca de 280 questões objetivas.

## Como cada módulo funciona

Todo o texto fica na raiz: este `README.md` é o guia, e cada módulo é um
arquivo só (`01-fundamentos.md`, `02-condicionais.md`...), com todos os
assuntos, os exemplos, os exercícios, a lista prática, os desafios e as
questões da prova. As pastas guardam só o que você roda e os desenhos: em
cada uma, a `lista/` (`P0101.c` a `P0130.c`) e uma subpasta por assunto, com
`ideia.svg`, `fluxograma.svg`, os exemplos (`A003.c`...) e os exercícios
(`E007.c`...). A árvore completa está em
[`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md#1-peças).

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com os
   mesmos valores do código.
2. Leia o código do texto. Quando o assunto tem um TAD na pasta, abra o `.c`
   inteiro também.
3. Siga o **fluxograma** com o dedo: é o caminho que o exemplo faz. Quando
   houver um **Passo a passo**, refaça a tabela no papel.
4. Responda a **Pergunta para você** antes de rodar. Depois rode os exemplos e
   mexa neles: mude um valor, quebre uma linha, rode de novo.
5. Faça os exercícios. As dicas ficam logo abaixo do enunciado, no `.md` do
   módulo e no topo do arquivo: tente antes de ler.
6. No fim do módulo, resolva a lista prática, os desafios e as **questões no
   estilo da prova**, que cobram o mesmo conteúdo em múltipla escolha.

## As cores e as formas

Nos fluxogramas, caixa azul é dado entrando ou saindo, roxa é o programa
fazendo alguma coisa e amarela (losango) é pergunta. Verde é o caminho que o
exemplo segue e o resultado; cinza, o que ele não usa; vermelho, erro. Os
diagramas da ideia seguem as mesmas cores, e cada módulo avisa, em "Antes de
começar", o que elas têm de próprio nos desenhos dele.

<p align="center"><img src="legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>


## Os módulos

| Módulo | Assuntos | O que você sai sabendo |
| --- | --- | --- |
| [01 · Fundamentos de C](01-fundamentos.md) | 0001–0011 | algoritmo, compilação, variáveis, tipos, limites, `printf`, `scanf`, operadores, conversão |
| [02 · Decisões](02-condicionais.md) | 0012–0019 | relacionais, lógicos, `if`, `else if`, ternário, `switch` |
| [03 · Laços](03-repeticoes.md) | 0020–0027 | `while`, `do...while`, `for`, `break`, padrões de laço, aleatórios |
| [04 · Funções](04-funcoes.md) | 0028–0036 | funções, escopo, pilha de chamadas, recursão, módulos `.h`/`.c`, macros |
| [05 · Vetores e strings](05-vetores-e-strings.md) | 0037–0043 | vetores, matrizes, caracteres, strings, leitura segura |
| [06 · Ponteiros](06-ponteiros.md) | 0044–0052 | endereços, `*` e `&`, aritmética, ponteiro para ponteiro e para função |
| [07 · Memória dinâmica](07-memoria-dinamica.md) | 0053–0058 | stack e heap, `malloc`, `realloc`, `free`, valgrind e ASan |
| [08 · Tipos compostos](08-structs.md) | 0059–0066 | `struct`, `typedef`, `enum`, `union`, operações com bits |
| [09 · Arquivos](09-arquivos.md) | 0067–0070 | arquivos texto e binários, `argc` e `argv` |
| [10 · Análise de algoritmos](10-analise.md) | 0071–0074 | contar passos, Big-O, invariantes, tipo abstrato de dado |
| [11 · Listas](11-listas.md) | 0075–0081 | vetor dinâmico, listas encadeadas simples, dupla e circular |
| [12 · Pilhas e filas](12-pilhas-e-filas.md) | 0082–0088 | pilha, fila circular, deque e suas aplicações |
| [13 · Busca e ordenação](13-busca-e-ordenacao.md) | 0089–0096 | busca binária, bubble, selection, insertion, merge, quick |
| [14 · Árvores](14-arvores.md) | 0097–0104 | árvore binária, BST, AVL, heap, heapsort |
| [15 · Tabelas hash](15-hash.md) | 0105–0108 | função hash, encadeamento, endereçamento aberto |
| [16 · Grafos](16-grafos.md) | 0109–0113 | representação, BFS, DFS, Dijkstra |
| [17 · Análise avançada](17-analise-avancada.md) | 0114–0118 | recorrências, teorema mestre, análise amortizada, limite inferior |
| [18 · Ordenação linear](18-ordenacao-linear.md) | 0119–0124 | shell, counting, radix e bucket sort, quickselect |
| [19 · Backtracking](19-backtracking.md) | 0125–0130 | subconjuntos, permutações, poda, N-rainhas, labirinto, sudoku |
| [20 · Divisão e conquista e gulosos](20-dc-e-gulosos.md) | 0131–0137 | potência rápida, inversões, troco, intervalos, mochila fracionária, Huffman |
| [21 · Programação dinâmica](21-programacao-dinamica.md) | 0138–0143 | memoização, troco, mochila 0/1, LCS, distância de edição |
| [22 · Árvores avançadas](22-arvores-avancadas.md) | 0144–0149 | árvores gerais, rubro-negra, árvore B, trie, union-find |
| [23 · Grafos avançados](23-grafos-avancados.md) | 0150–0156 | componentes, ordenação topológica, Kruskal, Prim, Bellman-Ford, Floyd-Warshall |
| [24 · Busca de padrões](24-busca-de-padroes.md) | 0157–0161 | força bruta, KMP, Horspool, Rabin-Karp |
| [25 · Estruturas extras](25-estruturas-extras.md) | 0162–0165 | matriz esparsa, skip list, listas autoajustáveis |
| [26 · Análise formal](26-analise-formal.md) | 0166–0169 | O, Ω e Θ com c e n₀, somatórios, complexidade espacial |
| [27 · Detalhes de C](27-c-detalhes.md) | 0170–0173 | precedência e avaliação, com e sem sinal, VLA |
| [28 · Estruturas: o que faltava](28-estruturas-complementos.md) | 0174–0181 | sentinela, sucessor, remoção AVL, rubro-negra clássica, hash por multiplicação, sondagem quadrática e dupla, pigeonhole |
| [29 · Grafos e NP](29-grafos-e-np.md) | 0182–0189 | euleriano, hamiltoniano, pontes e articulações, cadeia de matrizes, P e NP, reduções, aproximação |

O sumário detalhado, assunto por assunto, está em
[`_fontes/sumario.md`](_fontes/sumario.md).

As provas do PPGI de 2016 a 2023 estão resolvidas, com o gabarito comentado e o link para o
módulo de cada questão, em [`PROVAS.md`](PROVAS.md). Para treinar no formato atual (4 alternativas), há
3 simulados de 20 questões com gabarito comentado em [`SIMULADOS.md`](SIMULADOS.md).

## De onde veio o conteúdo

O texto, os exemplos e os exercícios foram escritos do zero, tomando como
referência os fichamentos em [`_fontes/`](_fontes/) dos materiais abaixo:

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. GEN LTC, 2024 (referência principal do edital do PPGI).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. Cengage Learning, 2010.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados*. 2. ed. Elsevier, 2016.
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

Os `.md` dos módulos (na raiz) e os SVGs são gerados. O guia de escrita está em
[`docs/RULES.md`](docs/RULES.md) (o ponto de partida para agentes é o [`AGENTS.md`](AGENTS.md)) e o gerador em [`_gerador/`](_gerador/):

```bash
cd _gerador && npm install
npm run gerar           # tudo
npm run gerar -- 03-    # só o módulo 03
```

Como conferir um desenho está em [`docs/DESIGN.md`](docs/DESIGN.md).

A fonte Excalifont (`_gerador/fonte/`) vem do projeto Excalidraw e usa a
licença SIL Open Font License.
