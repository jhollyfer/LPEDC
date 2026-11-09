# Módulo 16 · Grafos

Lista, pilha, fila, árvore, hash: até aqui toda estrutura tinha uma forma
bem comportada. Cada nó tinha um próximo, ou um pai, ou um balde. O mundo
real não é tão educado. Ruas se cruzam e fecham voltas, pessoas se seguem sem
reciprocidade, pacotes dependem uns dos outros. Para tudo isso existe o
**grafo**: pontos e ligações, sem regra de forma.

Fora da sala de aula, grafo aparece em todo canto. O GPS que acha a rota, a
rede social que sugere amigos, o gerenciador de pacotes que ordena as
dependências e reclama de dependência circular, o roteador que escolhe por
onde mandar o pacote: todos rodam alguma variação dos algoritmos deste módulo.

A pergunta deixa de ser "qual é o próximo?" e passa a ser "quem são os
vizinhos, e em que ordem eu visito?". Quase tudo aqui é a mesma **busca** com
uma estrutura auxiliar diferente: a pilha da recursão (DFS), a fila (BFS) ou
o "menor primeiro" (Dijkstra). O módulo usa muito do que veio antes:
matrizes, `malloc`, listas, filas, pilhas, recursão, structs e heap.

## O que você vai aprender

- o vocabulário de **grafos**: vértice, aresta, grau, caminho, ciclo, grafo dirigido e ponderado
- as duas representações: **matriz de adjacência** e **lista de adjacência**, e quando usar cada uma
- a **busca em largura** (BFS) com fila, e o menor caminho em número de arestas
- a **busca em profundidade** (DFS) com recursão ou pilha: componentes, ciclos e ordenação topológica
- o algoritmo de **Dijkstra** para o caminho mínimo com pesos, e a armadilha do INFINITO que estoura
- escolher o algoritmo certo para cada pergunta, e um bônus: a **árvore geradora mínima** com Prim

## Antes de começar

Você vai usar sem cerimônia: matrizes (0039), structs e `typedef` (0059 e
0060), `malloc` e `free` (0054), lista encadeada (0076), pilha (0082), fila
(0085), recursão (0032) e, no último assunto, heap (0102). Se algum desses
estiver enferrujado, revise antes.

Nos desenhos, a origem da busca fica roxa, o destino verde, e as arestas
verdes são as que a busca usou (a árvore da busca ou a rota final). Faça o
teste de mesa da fila, da pilha ou do vetor de distâncias no papel (em
grafos, ele é metade do aprendizado) e responda a **Pergunta para você**
antes de rodar.

Os vértices são números de 0 a V-1, e o nome de cada um fica num vetor de
strings à parte. Os exemplos examinam os vizinhos em ordem crescente de
índice, o que decide empates e a ordem da visita: mude a numeração e a saída
muda, sem estar errada.

O assunto 0109 traz o TAD `grafo.h` + `grafo.c` com lista de adjacência; o
`rodar` compila o `grafo.c` junto com os arquivos daquela pasta. Nos outros
assuntos, cada arquivo traz tudo dentro dele, com matriz de adjacência, para
o algoritmo ficar inteiro na tela.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

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
letra e só depois abra o gabarito. Sempre que a questão traz código, dá para
conferir rodando.

**1.** O grafo não dirigido abaixo tem os vértices A a H e as arestas A–B,
A–D, B–C, B–E, C–F, D–E, E–F, E–G, F–H e G–H. Uma busca em largura (BFS)
começa em A e examina os vizinhos de cada vértice em ordem alfabética. Em que
ordem os vértices saem da fila?

- (A) A, B, C, D, E, F, G, H
- (B) A, B, D, C, E, F, G, H
- (C) A, B, C, F, E, D, G, H
- (D) A, D, B, E, C, G, F, H
- (E) A, B, D, E, C, F, G, H

<details><summary>Gabarito</summary>

**B.** A descobre B e D (distância 1). B descobre C e E (distância 2); D não
descobre ninguém, porque E já está na fila. C descobre F, E descobre G
(distância 3), e F descobre H (distância 4). A ordem da fila é a ordem da
descoberta: A, B, D, C, E, F, G, H. A alternativa (C) é a ordem da DFS no
mesmo grafo. Veja 0110.

</details>

**2.** Uma DFS no estilo do Cormen percorre o grafo **dirigido** com as arestas
A→B, A→D, B→C, C→A, C→E, D→E, E→F e F→D. O laço principal tenta os vértices
em ordem alfabética, as listas de adjacência estão em ordem alfabética, e o
relógio começa em 1 (cada descoberta e cada término avança o relógio). Quais
são o tempo de descoberta e o de término de E (`E.d / E.f`)?

- (A) 4 / 7
- (B) 5 / 8
- (C) 6 / 7
- (D) 3 / 10
- (E) 4 / 9

<details><summary>Gabarito</summary>

**E.** A desce para B (2), B para C (3). C→A leva a um vértice cinza (aresta
de retorno), então C desce para E (4), E para F (5) e F para D (6). D→E é outra
aresta de retorno, e D termina em 7. Na volta: F termina em 8, **E em 9**, C em
10, B em 11 e A em 12 (A→D já encontra D preto). Tempos: A 1/12, B 2/11, C
3/10, E 4/9, F 5/8, D 6/7. Veja 0111.

</details>

**3.** Um grafo não dirigido simples tem 7 vértices e 10 arestas. Seis dos
graus são 1, 2, 2, 3, 3 e 4. Qual é o grau do sétimo vértice?

- (A) 3
- (B) 4
- (C) 5
- (D) 6
- (E) não existe grafo assim

<details><summary>Gabarito</summary>

**C.** A soma dos graus é o dobro do número de arestas: 2 × 10 = 20. Os seis
graus conhecidos somam 15, então falta 5. Um grau 5 cabe num grafo de 7
vértices (o máximo é 6), e a sequência 5, 4, 3, 3, 2, 2, 1 é realizável. Veja
0109.

</details>

**4.** Sobre as representações de um grafo G = (V, E), assinale a afirmação
correta.

- (A) A lista de adjacências ocupa Θ(V²) de memória, qualquer que seja E.
- (B) Na matriz de adjacências, listar todos os vizinhos de um vértice custa
  Θ(grau do vértice).
- (C) Na lista de adjacências, saber se a aresta (u, v) existe custa O(1).
- (D) A matriz ocupa Θ(V²) e responde "(u, v) é aresta?" em O(1); a lista
  ocupa Θ(V + E) e é a escolha natural para grafos esparsos.
- (E) Num grafo não dirigido, a lista de adjacências guarda cada aresta uma
  vez só.

<details><summary>Gabarito</summary>

**D.** A matriz tem V² casas, mesmo com poucas arestas, e consultar
`adj[u][v]` é O(1). A lista guarda só o que existe: V cabeças mais um nó por
aresta dirigida (duas por aresta não dirigida, por isso a (E) está errada).
Listar os vizinhos na matriz custa Θ(V), porque a linha inteira é varrida.
Veja 0109.

</details>

**5.** Rode o Dijkstra a partir de `s` no grafo **dirigido** com os pesos
s→a 4, s→b 1, b→a 2, a→c 1, b→c 5, c→d 3, b→d 8, d→t 1 e c→t 6. Qual é a
ordem em que os vértices são extraídos da fila de prioridade e qual é o valor
final de `t.d`?

- (A) s, b, a, c, d, t; `t.d` = 8
- (B) s, b, a, c, t, d; `t.d` = 10
- (C) s, a, b, c, d, t; `t.d` = 9
- (D) s, b, c, a, d, t; `t.d` = 8
- (E) s, b, a, d, c, t; `t.d` = 7

<details><summary>Gabarito</summary>

**A.** Depois de `s`: a = 4, b = 1. Extrai b (1) e relaxa: a cai para 3, c = 6,
d = 9. Extrai a (3): c cai para 4. Extrai c (4): d cai para 7, t = 10. Extrai
d (7): t cai para 8. Por último, t. Não há empate em nenhum passo. O caminho
é s, b, a, c, d, t, com custo 1 + 2 + 1 + 3 + 1 = 8. Veja 0112.

</details>

**6.** Sobre caminhos mínimos, assinale a afirmação correta.

- (A) A BFS acha o caminho de menor peso em qualquer grafo ponderado.
- (B) O Dijkstra está correto com pesos negativos, desde que não haja ciclo
  de peso negativo.
- (C) O Bellman-Ford roda em O(V · E), aceita pesos negativos e detecta um
  ciclo negativo alcançável a partir da origem.
- (D) Com heap binário e lista de adjacências, o Dijkstra custa Θ(V³).
- (E) O Floyd-Warshall resolve só o problema de fonte única.

<details><summary>Gabarito</summary>

**C.** O Bellman-Ford relaxa todas as arestas V - 1 vezes e, numa passada a
mais, qualquer relaxamento que ainda melhore uma distância denuncia um ciclo
negativo. O Dijkstra fixa um vértice de vez e pode errar com uma aresta
negativa que aparece depois, mesmo sem ciclo negativo. Com heap, ele custa
O((V + E) log V). A BFS só serve quando todas as arestas custam o mesmo, e o
Floyd-Warshall calcula **todos os pares**. Veja 0112 e 0154.

</details>

**7.** Qual é a complexidade da BFS abaixo, em função do número de vértices
`n` e de arestas `m`, sabendo que cada vértice entra na fila no máximo uma vez?

```c
while (inicio < fim) {
    int u = fila[inicio++];
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            fila[fim++] = v;
        }
    }
}
```

- (A) Θ(n + m)
- (B) Θ(n²)
- (C) Θ(m log n)
- (D) Θ(n · m)
- (E) Θ(m)

<details><summary>Gabarito</summary>

**B.** Com matriz de adjacências, cada vértice que sai da fila varre a linha
inteira, de `n` casas, tenha ele muitos ou poucos vizinhos. Se o grafo é
conexo, os `n` vértices passam pela fila: n × n. O Θ(n + m) da BFS vale com
lista de adjacências. Veja 0110.

</details>

**8.** Na DFS da questão 2, como fica a classificação das arestas?

- (A) A→D é de árvore, e o grafo é acíclico.
- (B) A→D é de retorno, e é ela que prova que o grafo tem ciclo.
- (C) A→D é de cruzamento, e C→A é de avanço.
- (D) Não há aresta de retorno, então o grafo admite ordenação topológica.
- (E) A→D é de avanço; C→A e D→E são de retorno, então o grafo tem ciclo e
  não admite ordenação topológica.

<details><summary>Gabarito</summary>

**E.** Quando A examina A→D, D já está preto e é descendente de A (A.d = 1 <
D.d = 6): aresta de **avanço**. C→A e D→E chegam a vértices cinzas, ainda na
pilha de chamadas: arestas de **retorno**. Um grafo dirigido tem ciclo se e
somente se a DFS acha aresta de retorno; aqui há dois ciclos (A, B, C e D, E,
F). Veja 0111.

</details>

**9.** Qual é o peso total da árvore geradora mínima do grafo não dirigido com
as arestas A–B 4, A–C 1, B–C 3, B–D 2, C–D 5, C–E 7, D–E 6, D–F 8 e E–F 3?

- (A) 13
- (B) 14
- (C) 16
- (D) 15
- (E) 18

<details><summary>Gabarito</summary>

**D.** No Kruskal, em ordem de peso: A–C (1), B–D (2), B–C (3) e E–F (3)
entram; A–B (4) e C–D (5) fechariam ciclo; D–E (6) liga os dois grupos. São 5
arestas para 6 vértices: 1 + 2 + 3 + 3 + 6 = 15. O Prim a partir de qualquer
vértice chega à mesma soma. Veja 0113 (Prim) e, no módulo 23, 0152 e 0153.

</details>

**10.** Um grafo não dirigido tem 12 vértices e 3 componentes conexos, e cada
componente é uma árvore. Quantas arestas ele tem?

- (A) 9
- (B) 10
- (C) 11
- (D) 12
- (E) depende do formato das árvores

<details><summary>Gabarito</summary>

**A.** Uma árvore com k vértices tem k - 1 arestas. Somando as três
componentes: (k₁ - 1) + (k₂ - 1) + (k₃ - 1) = 12 - 3 = 9, qualquer que seja o
tamanho de cada uma. Veja 0109 e 0111 (contar componentes com DFS).

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
