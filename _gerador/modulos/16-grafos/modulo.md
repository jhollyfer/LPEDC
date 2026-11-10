# Módulo 16 · Grafos

Ruas se cruzam, pessoas se seguem sem reciprocidade, pacotes dependem uns dos
outros. Para isso existe o **grafo**: pontos e ligações, sem regra de forma.
GPS, rede social e gerenciador de pacotes rodam os algoritmos deste módulo.

A pergunta passa a ser "quem são os vizinhos e em que ordem visito?". Quase
tudo é a mesma **busca** com uma estrutura auxiliar diferente: fila (BFS),
pilha da recursão (DFS) ou "menor primeiro" (Dijkstra).

## O que você vai aprender

- vocabulário: vértice, aresta, grau, caminho, ciclo, grafo dirigido e ponderado
- **matriz** e **lista de adjacência**, e quando usar cada uma
- **BFS**: menor caminho em número de arestas
- **DFS**: componentes, ciclos e ordenação topológica
- **Dijkstra**: caminho mínimo com pesos
- escolher o algoritmo para cada pergunta e, de bônus, a **árvore geradora
  mínima** com Prim

## Antes de começar

Usa matrizes (0039), structs (0059 e 0060), `malloc` e `free` (0054), lista
(0076), pilha (0082), fila (0085), recursão (0032) e heap (0102).

Os vértices são números de 0 a V-1, com os nomes num vetor de strings à
parte. Os exemplos examinam os vizinhos em ordem crescente de índice, o que
decide empates: mudar a numeração muda a saída, sem estar errada.

O assunto 0109 traz o TAD `grafo.h` e `grafo.c`, com lista de adjacência; o
comando do exemplo compila o `grafo.c` junto. Nos demais, cada arquivo é
completo, com matriz.

**Progressão.** A lista de adjacência do 0109 é a lista encadeada do balde
(módulo 15), com um balde por vértice. Fila e pilha (módulo 12) viram BFS e
DFS, e o heap (módulo 14) acelera o Dijkstra. O módulo 17 mede o custo.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com as flags de estudo.

**1. Contando arestas.** Escreva `int arestas(const int grau[], int n)`, que
recebe os graus dos vértices de um grafo não dirigido e devolve quantas
arestas ele tem, ou -1 se esses graus forem impossíveis. Teste com 10
vértices de grau 3 e com 7 vértices de grau 3. Depois monte numa matriz de
adjacência 10 × 10 um grafo de verdade com todos os graus 3 (ligue cada `i` a
`(i + 1) % 10` e a `(i + 5) % 10`) e confira, contando os 1 da matriz, quantas
arestas ele tem e se todos os graus deram 3.

<details><summary>Resposta</summary>

```text
10 vértices de grau 3: 15 arestas
7 vértices de grau 3: impossível (soma dos graus ímpar)
Grafo montado: 15 arestas, todos de grau 3: sim
```

Cada aresta soma 1 no grau de cada ponta, então a soma dos graus é o dobro das
arestas: 30 / 2 = 15. Com 7 vértices de grau 3 a soma seria 21, ímpar: não
existe. Todo grafo tem um número par de vértices de grau ímpar. Na matriz,
cada aresta aparece duas vezes (`adj[i][j]` e `adj[j][i]`), por isso a soma dos
1 também se divide por 2.

</details>

**2. Matriz ou lista?** Um mapa tem 10 mil esquinas e 30 mil ruas de mão
dupla. Com `sizeof`, calcule quanta memória gasta a matriz de adjacência de
`int` e quanto gasta a lista de adjacência com nós `struct No { int destino;
struct No *prox; }` (cada rua vira dois nós, mais um vetor de 10 mil
ponteiros para as cabeças). Mostre o `sizeof(No)`, os dois totais em bytes e
quantas vezes a matriz é maior. Use `long` nas contas.

<details><summary>Resposta</summary>

```text
sizeof(No) = 16 bytes
Matriz: 400000000 bytes (400.0 MB)
Lista: 960000 + 80000 = 1040000 bytes (1.04 MB)
A matriz gasta 384 vezes mais
```

(Num computador de 64 bits; com ponteiros de 4 bytes os números da lista
mudam.) O nó tem 4 bytes do `int`, 4 de preenchimento para alinhar o
ponteiro e 8 do ponteiro. A matriz guarda 100 milhões de casas, quase todas
zero: para grafos esparsos, a lista ganha de longe. `10000 * 10000 * 4` passa
do `INT_MAX`, por isso o `long`.

</details>

**3. Qual algoritmo? As ilhas.** Quantas ilhas há num mapa é uma pergunta de
componentes, e tanto a BFS quanto a DFS respondem. Neste mapa, `#` é terra e
`.` é água, e duas casas de terra vizinhas (cima, baixo, esquerda, direita)
são a mesma ilha:

```text
##..#...
#...##..
..#....#
......##
##.#....
```

Escreva `int dfs(...)` recursiva e `int bfs(...)` com fila, as duas marcando
as casas de uma ilha e devolvendo o tamanho dela. Varra o mapa linha por linha
e, a cada terra ainda não visitada, chame a busca. Mostre, para cada uma, os
tamanhos na ordem em que as ilhas aparecem e o total.

<details><summary>Resposta</summary>

```text
DFS: tamanhos 3 3 1 3 2 1 -> 6 ilhas
BFS: tamanhos 3 3 1 3 2 1 -> 6 ilhas
```

Só a ordem de visita **dentro** de cada ilha muda; a contagem é a mesma. Para
as outras perguntas do módulo: o menor número de cliques entre duas páginas é
**BFS** (todo clique custa 1); o voo mais barato é **Dijkstra** (preços são
pesos positivos); achar import circular e ordenar disciplinas com
pré-requisito são **DFS** (ou o Kahn, com fila, do desafio 4). Uma assinatura
`void conta(const char *nome, int (*busca)(int[L][C], int, int))` deixa o
mesmo laço de varredura servir às duas.

</details>

**4. A mudança, com fila.** Tarefas: 0 alugar caminhão, 1 encaixotar, 2
desmontar móveis, 3 carregar, 4 descarregar, 5 montar móveis, 6 ligar a
internet nova. Precedências: 0, 1 e 2 antes de 3; 3 antes de 4; 4 antes de 5.
Escreva a ordenação topológica de **Kahn**: conte quantas setas chegam em
cada tarefa, ponha numa fila as que têm zero, e a cada tarefa tirada
desconte 1 das sucessoras. Em que ordem sai, examinando em ordem de índice?
Quantas "rodadas" de tarefas em paralelo são necessárias?

<details><summary>Resposta</summary>

Ordem: **alugar, encaixotar, desmontar, internet, carregar, descarregar,
montar** (0, 1, 2, 6, 3, 4, 5). Rodadas: {0, 1, 2, 6}, {3}, {4}, {5}: **4
rodadas**. Se no fim sobrar tarefa que nunca chegou a zero, o grafo tem
ciclo e não existe ordem possível.

</details>

**5. Dijkstra no grafo dirigido.** Monte numa matriz de pesos o grafo
dirigido S→A 3, S→B 7, A→B 2, A→C 6, B→C 1, C→T 2, B→T 8 (só `peso[a][b]`, sem
a volta) e rode o Dijkstra de S. Mostre os vértices na ordem em que são
fixados, com a distância de cada um, e o caminho até T voltando pelo `pai[]`.

<details><summary>Resposta</summary>

```text
Fixados: S(0) A(3) B(5) C(6) T(8)
Caminho até T: S -> A -> B -> C -> T (custo 8)
```

B fica com 5 (via A), melhor que os 7 diretos; C com 6 (via B); T com 8 (via
C), melhor que os 13 por B direto. O código é o do assunto 0112; a única
diferença do não dirigido é preencher a matriz numa direção só. Para mostrar o
caminho na ordem certa, guarde os vértices de `pai[]` num vetor e imprima de
trás para frente.

</details>

**6. Quantos caminhos mínimos?** Grafo não dirigido: A-B, A-C, B-D, C-D, D-E,
D-F, E-G, F-G. Adapte a BFS a partir de A para contar, em `cont[v]`, quantos
caminhos com o menor número de arestas chegam a cada vértice, e mostre
`dist` e `cont` de todos.

<details><summary>Resposta</summary>

```text
A: dist 0, caminhos 1
B: dist 1, caminhos 1
C: dist 1, caminhos 1
D: dist 2, caminhos 2
E: dist 3, caminhos 2
F: dist 3, caminhos 2
G: dist 4, caminhos 4
```

Os 4 caminhos até G: A-B-D-E-G, A-B-D-F-G, A-C-D-E-G e A-C-D-F-G. Comece com
`cont[A] = 1`. Ao examinar a aresta u-v: se v é novo, `dist[v] = dist[u] + 1`
e `cont[v] = cont[u]`; se v já foi visto e `dist[v] == dist[u] + 1`, então
`cont[v] += cont[u]` (mais um jeito de chegar com o mesmo tamanho). Como a BFS
tira os vértices por camada, `cont[u]` já está completo quando u sai da fila.

</details>

**7. Estrada crítica.** Pegue o mapa da transportadora do assunto 0113 e
escreva `void criticas(Grafo *g)`: para cada estrada, apague (km 0), rode a
DFS do CD e veja se o número de lugares alcançáveis caiu; depois recoloque o
km. Mostre as estradas críticas, ou "nenhuma estrada crítica". Rode no mapa
original e depois de ligar a Ilha à Vila com uma ponte de 6 km.

<details><summary>Resposta</summary>

```text
Mapa do assunto 0113:
  nenhuma estrada crítica
Com a ponte Vila-Ilha:
  crítica: Vila-Ilha
```

No mapa original, toda estrada está em algum ciclo (CD-Centro-Feira,
Centro-Porto-Morro-Feira, Centro-Porto-Vila): se uma cai, sempre há outro
caminho. A ponte nova é o único acesso à Ilha. Compare com o total de antes
de apagar, não com `g->n`: no mapa original a Ilha já está fora. Percorra só
`b > a` para testar cada estrada uma vez. Custa O(E · (V + E)); essas
arestas se chamam **pontes**, e existe um algoritmo com uma DFS só (Tarjan)
para achar todas.

</details>

**8. Kruskal contra Prim.** Refaça a fibra óptica do A226 com o algoritmo de
**Kruskal**: ordene todos os trechos do mais barato ao mais caro e aceite cada
um que não feche ciclo. Em que ordem os trechos entram? O total muda?

<details><summary>Resposta</summary>

Entram Caicó–Currais Novos (9), Mossoró–Pau dos Ferros (16), Natal–Currais
Novos (18) e Mossoró–Caicó (20); os seguintes fechariam ciclo. Total **R$ 63
mil**, o mesmo do Prim (a árvore é a mesma, só a ordem muda). Para saber se
fecha ciclo, guarde em `grupo[v]` o "chefe" de cada vértice e só aceite a
aresta se os chefes forem diferentes (a ideia do union-find).

</details>

**9. Todas as distâncias.** Rodar Dijkstra a partir de cada vértice dá a
tabela de todas as distâncias. Existe um jeito com três laços aninhados, o
**Floyd-Warshall**: `para k, para i, para j: d[i][j] = min(d[i][j], d[i][k] +
d[k][j])`. Escreva-o para o mapa do assunto 0113 (com a Ilha), começando com
`d[i][i] = 0`, os km das estradas e `INFINITO` no resto, e mostre a tabela
(`-` quando não há caminho) e quantas vezes o laço de dentro rodou.

<details><summary>Resposta</summary>

```text
            CD Centro  Feira  Porto  Morro   Vila   Ilha
CD           0      3      2      7      5     10      -
Centro       3      0      1      6      4      9      -
Feira        2      1      0      5      3      8      -
Porto        7      6      5      0      2      3      -
Morro        5      4      3      2      0      5      -
Vila        10      9      8      3      5      0      -
Ilha         -      -      -      -      -      -      0
Passos do laço de dentro: 343
```

São V³ = 7³ = 343 passos: O(V³), igual a V execuções do Dijkstra com matriz,
com código bem menor. O cuidado é o do assunto 0112: com `INT_MAX`,
`d[i][k] + d[k][j]` estoura. Use `#define INFINITO 1000000000`, que somado
duas vezes ainda cabe em `int`, e mostre `-` quando `d[i][j] >= INFINITO`.
A linha do CD confere com o Dijkstra do assunto 0113: 10 km até a Vila.

</details>

**10. Labirinto com lama.** Num galpão como o do A220, casas com `~` têm
lama: entrar nelas custa 5 em vez de 1.

```text
S.~~~.E
.#~#.#.
.......
```

Rode a BFS e o Dijkstra (cada casa é um vértice; o peso da aresta é o custo
de entrar na casa de destino) de S até E. Para cada um, mostre quantos passos
o caminho tem, o custo total e o mapa com o caminho marcado com `*`.

<details><summary>Resposta</summary>

```text
BFS: 6 passos, custo 18
S*****E
.#~#.#.
.......
Dijkstra: 10 passos, custo 10
S.~~~.E
*#~#.#*
*******
```

A BFS conta casas, não custo: acha o caminho com menos passos, que atravessa
três casas de lama (1 + 5 + 5 + 5 + 1 + 1 = 18). O Dijkstra dá a volta por
baixo e chega com 10. Os vizinhos continuam saindo da conta das 4 direções;
só a fila vira "o menor `dist` primeiro", com `dist[u] + custo(v)` no lugar de
`dist[u] + 1`. A casa `u` é o número `l * C + c`, como no A220.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. Nas de simulação, desenhe o grafo e
anote a fila, a pilha ou a tabela de distâncias a cada passo. Quando o
enunciado não disser outra coisa, os vizinhos são examinados em ordem
alfabética (ou numérica) e o grafo é simples.

**1.** Considere as afirmações sobre as representações de um grafo
G = (V, E):

I. A matriz de adjacências ocupa Θ(V²) de memória, qualquer que seja o número
de arestas.
II. A lista de adjacências ocupa Θ(V + E).
III. Na lista de adjacências, testar se a aresta (u, v) existe custa O(1) no
pior caso.
IV. Num grafo não dirigido, a soma dos graus de todos os vértices é 2|E|.

Marque a alternativa **CORRETA**.

- (A) Apenas I e II.
- (B) Apenas I, II e IV.
- (C) Apenas III e IV.
- (D) Apenas I e III.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**B.** A III é falsa: na lista é preciso percorrer os vizinhos de `u`, o que custa
O(grau de u) e, no pior caso, O(V). É a matriz que responde em O(1). A IV é o
lema do aperto de mãos: cada aresta soma 1 ao grau de cada ponta. Veja 0109.

</details>

**2.** Considere as afirmações sobre a busca em largura (BFS) e a busca em
profundidade (DFS), ambas sobre listas de adjacências:

I. A BFS usa uma fila e, em grafo não ponderado, calcula o menor número de
arestas da origem até cada vértice alcançável.
II. A BFS pode usar uma pilha no lugar da fila sem mudar a ordem em que os
vértices são visitados.
III. As duas custam Θ(V + E).

Marque a alternativa **CORRETA**.

- (A) Apenas I.
- (B) Apenas II.
- (C) Apenas II e III.
- (D) Apenas I e III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**D.** Trocar a fila por uma pilha transforma a BFS numa variante da DFS: a
ordem de visita muda, e a garantia de menor distância some (II falsa). Em
ambas, cada vértice entra uma vez e cada aresta é examinada uma ou duas vezes,
o que dá Θ(V + E) com lista de adjacências. Veja 0110 e 0111.

</details>

**3.** Considere as afirmações sobre o algoritmo de Dijkstra:

I. Ele exige que todos os pesos das arestas sejam não negativos.
II. Quando um vértice sai da fila de prioridade, a distância dele já é a
definitiva.
III. Com pesos negativos ele continua correto, desde que o grafo seja
conexo.
IV. Com heap binário e lista de adjacências, custa O((V + E) log V).

Marque a alternativa **CORRETA**.

- (A) Apenas I, II e IV.
- (B) Apenas I e II.
- (C) Apenas II e III.
- (D) I, II, III e IV.
- (E) Apenas III e IV.

<details><summary>Gabarito</summary>

**A.** A III é falsa: a conectividade não ajuda. Com uma aresta negativa, um
vértice já extraído pode ganhar um caminho melhor depois, e o argumento de que
a distância é definitiva deixa de valer. Para pesos negativos use Bellman-Ford.
Veja 0112.

</details>

**4.** O grafo não dirigido tem as arestas S–A, S–C, A–B, A–D, B–E, C–D, D–F,
E–G, F–G e F–H. Uma BFS começa em S. Em que ordem os vértices saem da fila?

- (A) S, A, B, C, D, E, F, G, H
- (B) S, A, B, D, C, E, F, G, H
- (C) S, A, C, B, D, E, F, G, H
- (D) S, C, A, D, B, F, E, G, H
- (E) S, A, C, D, B, E, F, H, G

<details><summary>Gabarito</summary>

**C.** S descobre A e C (distância 1). A descobre B e D; C só vê D, que já foi
descoberto (distância 2). B descobre E e D descobre F (distância 3). E
descobre G, e F vê G e descobre H (distância 4). A fila sai por distância
crescente: S; A, C; B, D; E, F; G, H. Veja 0110.

</details>

**5.** Uma DFS percorre o grafo **dirigido** de vértices 1 a 6 e arestas 1→2,
1→3, 2→4, 3→4, 3→6, 4→5, 5→2 e 6→5. O laço principal tenta os vértices em
ordem crescente, os vizinhos também, e o relógio começa em 1 (cada descoberta
e cada término avança o relógio). Quais são o tempo de descoberta e o de
término do vértice 3 (`d / f`)?

- (A) 8 / 10
- (B) 9 / 10
- (C) 3 / 6
- (D) 8 / 12
- (E) 8 / 11

<details><summary>Gabarito</summary>

**E.** A DFS desce 1 (d=1), 2 (2), 4 (3), 5 (4); em 5 a aresta 5→2 aponta para 2,
que ainda está aberto: é uma aresta de retorno, e o grafo tem ciclo. 5 termina
em 5, 4 em 6, 2 em 7. Volta ao 1, que desce para 3 (d=8), cujo vizinho 4 já
terminou; 3 desce para 6 (d=9), 6 vê 5 (já terminou) e termina em 10; 3 termina
em 11 e o 1, em 12. A (D) mistura o `d` do 3 com o `f` do 1. Veja 0111.

</details>

**6.** Rode o Dijkstra a partir de `s` no grafo **dirigido** com as arestas
s→a 7, s→b 2, b→a 3, b→c 8, a→c 2, a→d 4, c→d 1, c→t 6 e d→t 2. Qual é a ordem
em que os vértices saem da fila de prioridade e o valor final de `t.d`?

- (A) s, b, a, d, c, t; `t.d` = 10
- (B) s, b, a, c, d, t; `t.d` = 10
- (C) s, a, b, c, d, t; `t.d` = 11
- (D) s, b, a, c, d, t; `t.d` = 9
- (E) s, b, c, a, d, t; `t.d` = 14

<details><summary>Gabarito</summary>

**B.** Distâncias finais: b = 2, a = 5 (por b, não pelo 7 direto), c = 7 (a→c), d = 8
(c→d, melhor que a→d, que daria 9) e t = 10 (d→t). A ordem de extração é a das
distâncias crescentes: s(0), b(2), a(5), c(7), d(8), t(10). O caminho de peso
mínimo é s, b, a, c, d, t. Veja 0112.

</details>

**7.** Um grafo não dirigido simples tem 8 vértices e todos têm grau 3. Quantas
arestas ele tem?

- (A) 24
- (B) 8
- (C) 11
- (D) 12
- (E) 16

<details><summary>Gabarito</summary>

**D.** A soma dos graus é 8 · 3 = 24, e cada aresta é contada duas vezes (uma em
cada ponta): |E| = 24/2 = 12. A (A) é a soma dos graus, esquecendo de dividir
por 2. Veja 0109.

</details>

**8.** O trecho abaixo é uma DFS recursiva sobre um grafo representado por
matriz de adjacências. Para o grafo não dirigido com as arestas 0–1 e 1–2 e
a chamada `dfs(0)`, o que acontece?

```c
#define N 3
int adj[N][N];
int visitado[N];

void dfs(int u) {
    for (int v = 0; v < N; v++)
        if (adj[u][v] && !visitado[v])
            dfs(v);
    visitado[u] = 1;
}
```

- (A) A recursão não termina (estouro de pilha): o vértice só é marcado depois do laço, e `dfs(1)` volta a chamar `dfs(0)`.
- (B) Visita 0, 1 e 2 uma vez cada e termina.
- (C) Visita só o vértice 0, porque `visitado[0]` já vale 1.
- (D) Falta um `free(visitado)` no fim da função.
- (E) Acessa `adj[3][0]`, fora da matriz.

<details><summary>Gabarito</summary>

**A.** A marcação está no lugar errado. `dfs(0)` chama `dfs(1)` (0 ainda não está
marcado); `dfs(1)` enxerga o vizinho 0, ainda "não visitado", e chama `dfs(0)`
de novo, e assim por diante. Rodando, o programa termina em falha de
segmentação por estouro da pilha. A marca `visitado[u] = 1` tem de vir antes do
laço. Veja 0111.

</details>

**9.** Sobre BFS, DFS e ordenação topológica, marque a alternativa
**INCORRETA**.

- (A) A BFS visita os vértices em ordem crescente de distância (em arestas) a partir da origem.
- (B) Num grafo dirigido, a DFS encontra uma aresta de retorno se e somente se o grafo tem ciclo.
- (C) Num grafo não dirigido, a DFS gera apenas arestas de árvore e de retorno.
- (D) A ordenação topológica só existe para grafo dirigido sem ciclo.
- (E) A BFS a partir de `s` alcança todos os vértices do grafo, qualquer que seja ele.

<details><summary>Gabarito</summary>

**E.** O "qualquer que seja ele" derruba a alternativa: num grafo desconexo, ou
num dirigido sem caminho de `s` até alguns vértices, a BFS só alcança os
vértices acessíveis a partir de `s`. As demais são verdadeiras: a fila garante
a ordem por distância (A), o ciclo é a aresta de retorno (B), em grafo não
dirigido não há avanço nem cruzamento (C) e a ordenação topológica exige DAG
(D). Veja 0110 e 0111.

</details>

**10.** Sobre grafos não dirigidos, marque a alternativa **CORRETA**.

- (A) Todo grafo com `n` vértices e `n − 1` arestas é uma árvore.
- (B) Um grafo conexo com `n` vértices tem pelo menos `n` arestas.
- (C) Um grafo conexo com `n` vértices e exatamente `n − 1` arestas não tem ciclo, ou seja, é uma árvore.
- (D) O número de vértices de grau ímpar pode ser ímpar.
- (E) Um grafo simples com `n` vértices pode ter até `n²` arestas.

<details><summary>Gabarito</summary>

**C.** Conexo exige no mínimo `n − 1` arestas, e com exatamente `n − 1` não
sobra aresta para fechar ciclo. A (A) falha porque o grafo pode ser desconexo e
ainda ter um ciclo (um triângulo mais vértices isolados). A (D) é impossível
pelo lema do aperto de mãos: a soma dos graus é par. O máximo num grafo simples
é `n(n − 1)/2`, não `n²` (E). Veja 0109 e 0150.

</details>

## Para ler mais

- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 8: grafos e suas aplicações.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 5: filas e distâncias em uma rede.
- FEOFILOFF, P. *Algoritmos para grafos*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos_para_grafos/>.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Tipos abstratos de dados, pilhas e filas.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Parte VI: cap. 20 (BFS, DFS com tempos de descoberta e término, ordenação topológica), cap. 21 (árvore geradora mínima) e cap. 22 (caminhos mínimos de fonte única, RELAX e Dijkstra).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 7: algoritmos em grafos.
- DIJKSTRA, E. W. A note on two problems in connexion with graphs. *Numerische Mathematik*, v. 1, p. 269-271, 1959.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989.
- CPPREFERENCE. *Numeric limits* (`INT_MAX`) e *Arithmetic operators* (estouro de inteiro com sinal). Disponível em: <https://en.cppreference.com/w/c/types/limits>.
