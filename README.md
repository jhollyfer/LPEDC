# LPEDC · Lógica de Programação, Estrutura de Dados e C

Material de estudo pessoal para relembrar lógica de programação, aprender
estrutura de dados e entender de verdade como a linguagem C funciona: a
memória, os ponteiros, a compilação e o custo de cada escolha.

> [!IMPORTANT]
> **Preparação para o Mestrado do PPGI/UFAM.** O curso está alinhado à Prova de
> Conhecimentos do edital 070/2026 (prova em 27/11/2026). O guia
> [`PPGI.md`](PPGI.md) liga cada tópico do edital e do cursinho do PPGI ao
> assunto que o ensina. Para estudar até a prova, comece pelo
> [plano dia a dia](PPGI.md#comece-aqui); a [`TRILHA.md`](TRILHA.md) mostra o que vem antes de quê.

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

Compile com o `gcc` e execute o resultado. O `-o` dá o nome do executável, que fica ao lado do `.c`:

```bash
gcc ~/LPEDC/material/A003.c -o ~/LPEDC/material/A003 && ~/LPEDC/material/A003
```

Para testar sem digitar, mande a entrada por um cano; para passar argumentos, escreva-os depois do executável:

```bash
gcc ~/LPEDC/material/A011.c -o ~/LPEDC/material/A011 && printf '25\n' | ~/LPEDC/material/A011
gcc ~/LPEDC/material/A137.c -o ~/LPEDC/material/A137 && ~/LPEDC/material/A137 um dois tres
```

Os assuntos com TAD têm `.c` de apoio na pasta (`pilha.c`, `lista.c`...): o comando do exemplo já os lista.

Para estudar, use as **flags de estudo**: acrescente
`-std=c17 -Wall -Wextra -pedantic -g -fsanitize=address,undefined -lm` antes do `-o`. O
**AddressSanitizer** para o programa e aponta a linha quando você acessa memória que não devia ou
esquece um `free`, e o detector de comportamento indefinido pega o estouro de inteiro. Os avisos
e relatórios citados nos módulos aparecem com essas flags. Para vazamento difícil, use
`valgrind ~/LPEDC/<caminho>/A107` sobre o executável compilado com `-g`.

Os arquivos têm nome curto e numeração única no curso inteiro:

- `A001.c`, `A002.c`... são os **exemplos** resolvidos;
- `E001.c`, `E002.c`... são os **exercícios**: a resposta vai dentro do próprio
  arquivo, embaixo de `// Escreva sua resposta abaixo:`;
- `_respostas/` tem uma resolução de cada exercício. Só olhe **depois** de
  tentar de verdade.

Cada assunto tem 2 exemplos e 4 exercícios, todos de escrever código na mão:
um ★☆☆ (aquecimento), dois ★★☆ (raciocínio) e um ★★★ (desafio). O enunciado
traz só o que escrever e a saída esperada. Cada módulo termina com uma
**lista prática** de 30 exercícios de codificar (pasta `lista/`, arquivos
`P????.c`, resoluções em `_respostas/<modulo>/lista/`), uma lista de
**desafios** que misturam tudo e **questões reais das provas do PPGI**, com
gabarito oficial.

No total: 378 exemplos, 756 exercícios por assunto e 870 exercícios nas listas
práticas.

## Como cada módulo funciona

Os arquivos do curso ficam todos numa pasta só, `material/`. O texto de cada módulo é um arquivo só
(`01-fundamentos.md`, `02-condicionais.md`...), com os assuntos, os exemplos, os
exercícios, a lista prática, os desafios e as questões da prova. Em `material/` moram os
arquivos que você roda: `A###.c` (exemplos), `E###.c` (exercícios), `P####.c` (lista
prática) e os desenhos `NNNN-ideia.svg` e `NNNN-fluxograma.svg`. Os TADs de apoio levam o número
do assunto no nome (`0076-lista.c`). As resoluções ficam em `_respostas/`. A árvore completa
está em [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md#1-peças).

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com os
   mesmos valores do código.
2. Leia o código do texto. Quando o assunto tem um TAD na pasta, abra o `.c`
   inteiro também.
3. Siga o **fluxograma** com o dedo: é o caminho que o exemplo faz. Quando
   houver um **Passo a passo**, refaça a tabela no papel.
4. Responda a **Pergunta para você** antes de rodar. Depois rode os exemplos e
   mexa neles: mude um valor, quebre uma linha, rode de novo.
5. Faça os exercícios: o enunciado e a saída esperada estão no `.md` do módulo e
   no topo do arquivo. Escreva o código sozinho e compare a saída.
6. No fim do módulo, resolva a lista prática, os desafios e as **questões das
   provas do PPGI**, que cobram o mesmo conteúdo em múltipla escolha.

## As cores e as formas

Nos fluxogramas, caixa azul é dado entrando ou saindo, roxa é o programa
fazendo alguma coisa e amarela (losango) é pergunta. Verde é o caminho que o
exemplo segue e o resultado; cinza, o que ele não usa; vermelho, erro. Os
diagramas da ideia seguem as mesmas cores, e cada módulo avisa, em "Antes de
começar", o que elas têm de próprio nos desenhos dele.

<p align="center"><img src="material/legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>


## Mapa do jogo

O curso é uma rota de **29 etapas**, agrupadas em **8 mundos**. Cada etapa é um módulo: você só avança quando fecha os checkpoints dela, e cada uma usa o que a anterior ensinou. Os módulos com ★ são **bônus**: o número do arquivo vem depois, mas a etapa destrava antes, no ponto da rota em que ela ajuda. Cada módulo abre com o mapa da fase (missão, de onde você vem, para onde vai e checkpoints) e fecha com o **chefão**: as questões reais de prova.

| Etapa | Mundo | Módulo | Assuntos | Missão |
| --- | --- | --- | --- | --- |
| 1 | Mundo 1 · Primeiros passos | [01 · Fundamentos de C](01-fundamentos.md) | 0001–0011 | Compilar o primeiro programa, guardar valores em variáveis e mostrar resultados |
| 2 | Mundo 1 · Primeiros passos | [02 · Decisões](02-condicionais.md) | 0012–0019 | Fazer o programa escolher caminhos com `if`, `else` e `switch` |
| 3 | Mundo 1 · Primeiros passos | [03 · Laços](03-repeticoes.md) | 0020–0027 | Repetir tarefas com `while`, `do...while` e `for` |
| 4 | Mundo 1 · Primeiros passos | [04 · Funções e modularização](04-funcoes.md) | 0028–0036 | Dividir o programa em funções, entender escopo e pilha de chamadas e usar recursão |
| 5 | Mundo 2 · Memória e dados | [05 · Vetores, matrizes e strings](05-vetores-e-strings.md) | 0037–0043 | Guardar vários valores juntos e trabalhar com texto |
| 6 | Mundo 2 · Memória e dados | [06 · Ponteiros](06-ponteiros.md) | 0044–0052 | Enxergar endereços de memória e usá-los |
| 7 | Mundo 2 · Memória e dados | [07 · Memória dinâmica](07-memoria-dinamica.md) | 0053–0058 | Pedir e devolver memória durante a execução, sem vazar |
| 8 | Mundo 2 · Memória e dados | [08 · Tipos compostos](08-structs.md) | 0059–0066 | Agrupar dados com `struct`, `union`, `enum` e operações com bits |
| 9 | Mundo 2 · Memória e dados | [27 · Detalhes de C que caem em prova](27-c-detalhes.md) ★ | 0170–0173 | Dominar as pegadinhas de precedência, sinal e VLA que a prova cobra |
| 10 | Mundo 2 · Memória e dados | [09 · Arquivos e linha de comando](09-arquivos.md) | 0067–0070 | Ler e gravar arquivos e receber argumentos na linha de comando |
| 11 | Mundo 3 · Custo e estruturas lineares | [10 · Pensar como cientista da computação](10-analise.md) | 0071–0074 | Medir o custo de um algoritmo e escrever tipos abstratos de dado |
| 12 | Mundo 3 · Custo e estruturas lineares | [26 · Notação assintótica, somatórios e espaço](26-analise-formal.md) ★ | 0166–0169 | Provar custos com O, Ω, Θ e somatórios |
| 13 | Mundo 3 · Custo e estruturas lineares | [11 · Listas](11-listas.md) | 0075–0081 | Montar listas encadeadas simples, duplas e circulares |
| 14 | Mundo 3 · Custo e estruturas lineares | [12 · Pilhas e filas](12-pilhas-e-filas.md) | 0082–0088 | Usar pilhas, filas e deques |
| 15 | Mundo 4 · Buscar e ordenar | [13 · Busca e ordenação](13-busca-e-ordenacao.md) | 0089–0096 | Buscar e ordenar com os algoritmos clássicos e comparar seus custos |
| 16 | Mundo 4 · Buscar e ordenar | [18 · Ordenação além da comparação e seleção](18-ordenacao-linear.md) | 0119–0124 | Ordenar sem comparar: counting, radix e bucket sort |
| 17 | Mundo 5 · Árvores | [14 · Árvores](14-arvores.md) | 0097–0104 | Montar árvore binária, ABB, AVL e heap |
| 18 | Mundo 5 · Árvores | [22 · Árvores e conjuntos avançados](22-arvores-avancadas.md) | 0144–0149 | Conhecer rubro-negra, árvore B, trie e union-find |
| 19 | Mundo 6 · Tabelas hash | [15 · Tabelas hash](15-hash.md) | 0105–0108 | Montar tabelas hash com encadeamento e endereçamento aberto |
| 20 | Mundo 6 · Tabelas hash | [28 · Estruturas: o que faltava](28-estruturas-complementos.md) ★ | 0174–0181 | Fechar as lacunas de listas, árvores e hash que a prova cobra |
| 21 | Mundo 7 · Grafos | [16 · Grafos](16-grafos.md) | 0109–0113 | Representar grafos e percorrer com BFS, DFS e Dijkstra |
| 22 | Mundo 7 · Grafos | [23 · Grafos: estrutura e caminhos](23-grafos-avancados.md) | 0150–0156 | Ordenar topologicamente, achar árvore geradora mínima e caminhos mínimos |
| 23 | Mundo 7 · Grafos | [29 · Grafos: ciclos e cortes; problemas difíceis](29-grafos-e-np.md) | 0182–0189 | Separar problemas fáceis dos NP-completos e entender aproximação |
| 24 | Mundo 8 · Técnicas de projeto | [17 · Medindo algoritmos recursivos](17-analise-avancada.md) | 0114–0118 | Resolver recorrências e aplicar o teorema mestre |
| 25 | Mundo 8 · Técnicas de projeto | [19 · Enumeração e backtracking](19-backtracking.md) | 0125–0130 | Explorar todas as soluções com poda |
| 26 | Mundo 8 · Técnicas de projeto | [20 · Divisão e conquista e algoritmos gulosos](20-dc-e-gulosos.md) | 0131–0137 | Dividir para conquistar e escolher o melhor local |
| 27 | Mundo 8 · Técnicas de projeto | [21 · Programação dinâmica](21-programacao-dinamica.md) | 0138–0143 | Guardar subproblemas repetidos para ganhar velocidade |
| 28 | Mundo 8 · Técnicas de projeto | [24 · Busca de padrões em texto](24-busca-de-padroes.md) | 0157–0161 | Achar padrões em texto com KMP, Horspool e Rabin-Karp |
| 29 | Mundo 8 · Técnicas de projeto | [25 · Estruturas especiais](25-estruturas-extras.md) | 0162–0165 | Conhecer matriz esparsa, skip list e listas autoajustáveis |

Depois da etapa 29 vêm os [simulados](SIMULADOS.md) e as [provas antigas](PROVAS.md). A rota por peso na prova está em [`TRILHA.md`](TRILHA.md) e o plano dia a dia em [`PPGI.md`](PPGI.md#comece-aqui).

O sumário detalhado, assunto por assunto, está em
[`_fontes/sumario.md`](_fontes/sumario.md).

As provas do PPGI de 2016 a 2023 estão resolvidas, com o gabarito comentado e o link para o
módulo de cada questão, em [`PROVAS.md`](PROVAS.md). Para treinar no formato atual (4 alternativas), há
3 simulados de 20 questões com gabarito comentado em [`SIMULADOS.md`](SIMULADOS.md).

Para treinar com as provas em formato de quiz, com o porquê de cada alternativa logo depois de responder:
**[jhollyfer.github.io/LPEDC](https://jhollyfer.github.io/LPEDC/)**.

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
