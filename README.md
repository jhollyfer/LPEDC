# LPEDC · Lógica de Programação, Estrutura de Dados e C

Guia de estudo pessoal de lógica, linguagem C e estruturas de dados, feito para a Prova de
Conhecimentos do Mestrado do PPGI/UFAM (edital 070/2026, prova em 27/11/2026).

> [!IMPORTANT]
> Para estudar até a prova, comece pelo [plano dia a dia](PPGI.md#comece-aqui) do
> [`PPGI.md`](PPGI.md). A [`TRILHA.md`](TRILHA.md) mostra o que vem antes de quê.

## 1. Conceitos gerais

- **Módulo**: um arquivo `.md` na raiz (`01-fundamentos.md`, `02-condicionais.md`...). São 29.
- **Cada módulo tem três partes**: **1. Conceitos gerais** (definições curtas, com a fonte de cada
  uma), **2. Exemplos de uso** (código comentado, com desenho e fluxograma) e **3. Exercícios
  práticos** (exercícios, lista do módulo, desafios e questões de prova com gabarito).
- **Assunto**: um tópico do módulo, com número fixo (`0002 · Variáveis`). Aparece nas três partes.
- **Arquivos**: tudo o que se roda fica em `material/`. `A###.c` são exemplos resolvidos, `E###.c`
  são exercícios (a resposta vai dentro do arquivo), `P####.c` é a lista do módulo. As resoluções
  ficam em `_respostas/`: só olhe depois de tentar.
- **Níveis**: ★☆☆ aquecimento, ★★☆ raciocínio, ★★★ desafio.
- **Cores dos desenhos**: azul é dado entrando ou saindo, roxo é o programa agindo, amarelo
  (losango) é pergunta, verde é o caminho seguido, cinza o que não é usado e vermelho é erro.

<p align="center"><img src="material/legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

**Fontes.** As definições foram escritas do zero com base nos fichamentos em [`_fontes/`](_fontes/).
Cada conceito cita a obra; a referência completa fica em "Para ler mais", no fim do módulo:

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

## 2. Exemplos de uso

Preparar o computador:

```bash
sudo pacman -S --needed base-devel gdb valgrind git     # Arch Linux
sudo apt install build-essential gdb valgrind git       # Debian / Ubuntu
git clone https://github.com/jhollyfer/LPEDC ~/LPEDC
```

No Windows, use o WSL com Ubuntu (`wsl --install`). No macOS, `xcode-select --install`.

Rodar um arquivo (o `-o` dá o nome do executável):

```bash
gcc ~/LPEDC/material/A003.c -o ~/LPEDC/material/A003 && ~/LPEDC/material/A003
```

Mandar a entrada sem digitar e passar argumentos:

```bash
gcc ~/LPEDC/material/A011.c -o ~/LPEDC/material/A011 && printf '25\n' | ~/LPEDC/material/A011
gcc ~/LPEDC/material/A137.c -o ~/LPEDC/material/A137 && ~/LPEDC/material/A137 um dois tres
```

**Flags de estudo**: acrescente `-std=c17 -Wall -Wextra -pedantic -g -fsanitize=address,undefined -lm`
antes do `-o`. O compilador passa a apontar a linha de erros de memória e de estouro de inteiro.
Para vazamento difícil, use `valgrind` no executável compilado com `-g`. Assuntos com TAD têm `.c` de
apoio (`0076-lista.c`); o comando do exemplo já os inclui.

Como estudar um assunto:

1. Leia o conceito (parte 1).
2. Leia o exemplo (parte 2), siga o fluxograma e rode o código. Mude um valor e rode de novo.
3. Faça os exercícios do assunto (parte 3) sem olhar a resposta.

## 3. Exercícios práticos

O curso é uma rota de 29 etapas em 8 mundos. Cada etapa é um módulo e termina com as questões reais
de prova. Os módulos com ★ são bônus e entram no ponto da rota em que ajudam.

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

Depois da etapa 29:

- [`SIMULADOS.md`](SIMULADOS.md): 3 simulados de 20 questões no formato atual;
- [`PROVAS.md`](PROVAS.md): as 11 provas de 2016 a 2023, com gabarito comentado;
- quiz das provas, com o porquê de cada alternativa: **[jhollyfer.github.io/LPEDC](https://jhollyfer.github.io/LPEDC/)**.

---

**Para quem for mexer no material.** Os `.md` dos módulos e os SVGs são gerados a partir de
[`_gerador/`](_gerador/); nunca edite o `.md` do módulo à mão. Regras em
[`docs/RULES.md`](docs/RULES.md), ponto de partida para agentes em [`AGENTS.md`](AGENTS.md).

```bash
cd _gerador && npm install
npm run gerar           # tudo
npm run gerar -- 03-    # só o módulo 03
```

A fonte Excalifont (`_gerador/fonte/`) vem do projeto Excalidraw, sob a licença SIL Open Font License.
