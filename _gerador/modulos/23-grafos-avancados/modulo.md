# Módulo 23 · Grafos: estrutura e caminhos

O módulo 16 ensinou BFS, DFS e Dijkstra: "como eu ando pelo grafo?". Aqui a
pergunta é "**o que ele esconde?**": pedaços soltos, ciclos, ordem das
tarefas, o jeito mais barato de ligar todos, pesos negativos e caminhos de
todos para todos.

Cada assunto reaproveita uma peça conhecida: a DFS vira detector de ciclos e
ordenação topológica, a fila vira o Kahn, `qsort` e union-find viram o
Kruskal, o heap vira o Prim e a tabela da PD vira o Floyd-Warshall.

## O que você vai aprender

- **componentes conexos** e **ciclos**, com a DFS de três cores nos grafos
  dirigidos
- **ordenação topológica**: **Kahn** (fila) e pós-ordem invertida da DFS
- **árvore geradora mínima**: **Kruskal** (ordenação + union-find) e **Prim**
  (heap), e a diferença entre Prim e Dijkstra, que mora numa linha
- **pesos negativos** e **ciclo negativo** com **Bellman-Ford**
- **todos os pares** com **Floyd-Warshall** e a reconstrução das rotas
- escolher o algoritmo pela pergunta, num programa que planeja semestres e
  rotas

## Antes de começar

Cada assunto traz o algoritmo inteiro num arquivo, sem TAD. Nos desenhos, a
origem é roxa e as arestas verdes são as escolhidas; na DFS de três cores,
amarelo é o cinza (na pilha) e verde é o preto (terminado).

Você precisa do módulo 16 (matriz de adjacência, BFS 0110, DFS 0111 e
Dijkstra 0112, a reler antes do 0153), fila (0085), heap (0102), `qsort`
(0096), union-find (0148), recursão (0032), permutações (0126) e PD (módulo
21). Grau, circuitos, grafos eulerianos e hamiltonianos, pontes e
articulações, que o edital do PPGI também cobra, estão nos assuntos 0182 a
0184.

Três convenções valem para o módulo:

- vértices são números de 0 a V-1, com os nomes num vetor de strings à parte,
  e os vizinhos são examinados em **ordem crescente de índice**; isso decide
  os empates, e mudar a numeração pode mudar a saída sem errar;
- na matriz de pesos, **0 quer dizer "sem aresta"**, salvo aviso (o A311
  mostra o problema disso);
- ao somar distâncias, o INFINITO é `1000000000`, que somado a outro INFINITO
  ainda cabe num `int`; quando o código usa `INT_MAX`, testa antes de somar.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c`
seu. Eles misturam os assuntos do módulo.

**1. Três cores à mão.** Grafo dirigido: A → B, A → C, B → C, C → D, D → B.
Rode a DFS de três cores a partir de A, examinando os vizinhos em ordem
alfabética. Existe ciclo? Qual é a seta que o denuncia, e quem está cinza
nesse momento?

<details><summary>Resposta</summary>

Existe. A DFS entra em A, B, C e D, todos cinza. D olha B, que está
**cinza**: a seta **D → B** fecha o ciclo **B → C → D → B**. A seta A → C, que
seria examinada depois, nem chega a ser vista. Com um `visitado[]` simples o
ciclo também seria achado aqui, mas por sorte: troque D → B por A → D e o
`visitado[]` gritaria "ciclo" sem haver nenhum.

</details>

**2. Quantas ordens?** DAG: 0 → 2, 1 → 2, 2 → 3, 2 → 4. Quantas ordenações
topológicas existem? Qual o Kahn com fila mostra?

<details><summary>Resposta</summary>

**4**: 0 e 1 vêm antes de 2 em qualquer ordem (2 jeitos), e 3 e 4 vêm depois,
em qualquer ordem (2 jeitos): 2 × 2. O Kahn mostra **0 1 2 3 4**. O vértice 2
é um "gargalo": todo mundo antes dele, todo mundo depois.

</details>

**3. Kruskal na rede do poço.** Refaça a rede de canos do assunto 0153 com
Kruskal. Em que ordem os canos entram? O total muda?

<details><summary>Resposta</summary>

Ordem: Cida-Davi 2, Ana-Beto 3, Poço-Ana 4, Davi-Elza 4, Beto-Cida 5. Depois
disso já são 5 canos. Total **18 m**, o mesmo do Prim, com os mesmos canos.
Só a ordem muda: o Kruskal começa pelo cano mais curto do mapa inteiro, longe
do Poço; o Prim cresce a partir do Poço.

</details>

**4. Quantas árvores mínimas?** Triângulo A-B (1), B-C (2), A-C (2), mais
C-D (3). Quantas árvores geradoras mínimas existem e qual o custo?

<details><summary>Resposta</summary>

**Duas**, ambas com custo **6**: {A-B, B-C, C-D} e {A-B, A-C, C-D}. O empate
entre B-C e A-C permite qualquer um dos dois. Com todos os pesos diferentes,
a árvore mínima seria única.

</details>

**5. Somar uma constante resolve?** Alguém propõe: "para usar Dijkstra com
pesos negativos, some 10 em todos os pesos". Teste no grafo S → A (-2),
A → T (3), S → T (2).

<details><summary>Resposta</summary>

**Não resolve.** O certo é S → A → T, custo **1**. Somando 10: S → A vira 8 e
A → T vira 13, total 21; S → T vira 12, e o Dijkstra escolhe S → T. Somar uma
constante castiga mais os caminhos com mais arestas, e a ordem entre eles
muda. Para isso existe o Bellman-Ford (e, para todos os pares, o algoritmo
de Johnson, que repondera os pesos com uma rodada de Bellman-Ford).

</details>

**6. Rodadas no pior caso.** Um caminho 0 → 1 → 2 → 3 → 4 → 5, todas as
arestas com peso 1. Quantas rodadas o Bellman-Ford com parada antecipada faz
com a lista na ordem do caminho? E com a lista invertida?

<details><summary>Resposta</summary>

Na ordem: **2** (a primeira já acerta tudo, a segunda confirma que nada mudou).
Invertida: **5**, uma aresta do caminho por rodada, e a quinta já é a última
permitida (V - 1). É o que o A308 mede.

</details>

**7. Floyd-Warshall à mão.** Grafo dirigido: A → B 5, B → C 2, A → C 9, C → A 3.
Dê a matriz depois de cada rodada (k = A, B, C).

<details><summary>Resposta</summary>

k = A: C → B passa a valer 3 + 5 = **8**. k = B: A → C cai de 9 para 5 + 2 =
**7**. k = C: B → A passa a valer 2 + 3 = **5**. Matriz final, linhas A, B, C:
**(0, 5, 7)**, **(5, 0, 2)**, **(3, 8, 0)**.

</details>

**8. Qual algoritmo?** Para cada pergunta, diga o algoritmo: (a) ligar 500
casas com o mínimo de cabo; (b) a ordem de compilar os módulos de um
projeto; (c) achar uma sequência de trocas de moeda que dá lucro; (d) a
tabela de distâncias entre 50 cidades; (e) quantos grupos de amigos existem,
com amizades chegando a toda hora; (f) o GPS de uma cidade, sem pesos
negativos.

<details><summary>Resposta</summary>

(a) **Kruskal ou Prim**; (b) **ordenação topológica** (Kahn ou DFS); (c)
**Bellman-Ford** com pesos -log(taxa), procurando ciclo negativo (A307); (d)
**Floyd-Warshall** (50³ = 125 mil passos); (e) **union-find** (A300); (f)
**Dijkstra** com heap.

</details>

**9. Caminho crítico.** Tarefas com duração em dias: A (3); B (2), depois de A;
C (4), depois de A; D (1), depois de B e de C. Qual o prazo mínimo com
equipes em paralelo? Qual o caminho crítico? Quantos dias a tarefa B pode
atrasar sem atrasar a obra?

<details><summary>Resposta</summary>

Prazo **8 dias**: A termina no dia 3, C no dia 7, D começa no 7 e termina no 8.
Caminho crítico: **A → C → D**. B pode começar no dia 3 e precisa terminar até
o dia 7 (quando D começa): tem **2 dias de folga**. É o E904 com uma conta a
mais, a do "mais tarde possível", feita de trás para frente.

</details>

**10. Semestres com prioridade.** No E934, escolher as disciplinas pelo índice
deu 5 semestres. Calcule, para cada disciplina, a "altura": o tamanho da
maior corrente de pré-requisitos que ainda vem depois dela. Escolhendo
sempre as de maior altura, quantos semestres são necessários?

<details><summary>Resposta</summary>

Alturas: Algoritmos 3 (Estruturas, Redes, TCC), Cálculo I 2, Estruturas 2,
Cálculo II 1, Redes 1, Física 0, Inglês 0, TCC 0. Semestres (empate decidido
pelo índice): {Algoritmos, Cálculo I}, {Estruturas, Cálculo II}, {Redes,
Inglês}, {TCC, Física}: **4**. A
altura sai de uma DFS com memória: altura(u) = 1 + maior altura dos
sucessores (0 se não tem nenhum).

</details>

**11. Floresta pelo Kruskal.** Você roda o Kruskal até o fim da lista num grafo
com 10 vértices e ele aceita 7 arestas. Quantos componentes o grafo tem? E
se o grafo tivesse 15 arestas no total, quantas formariam ciclo?

<details><summary>Resposta</summary>

Cada aresta aceita junta dois grupos: 10 - 7 = **3 componentes**. Das 15
arestas, 7 entraram e **8** foram recusadas por fechar ciclo. Rodado até o
fim, o Kruskal também conta componentes, como o union-find do A300.

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. As questões 1 e 2 usam o mesmo grafo **não dirigido**,
com as arestas (peso):

```text
A-B 4   A-C 1   B-C 2   B-D 5   C-D 8
C-E 10  D-E 2   D-F 6   E-F 3
```

**1.** Rodando o Kruskal nesse grafo, qual é a **primeira** aresta
rejeitada e qual o peso total da árvore geradora mínima?

- (A) C-D, total 13
- (B) A-B, total 12
- (C) D-F, total 14
- (D) A-B, total 13
- (E) B-D, total 13

<details><summary>Gabarito</summary>

**(D).** Em ordem: A-C 1, B-C 2, D-E 2 e E-F 3 entram; A-B 4 fecharia o
ciclo A-C-B (A e B já estão no mesmo conjunto) e é a primeira rejeitada;
B-D 5 entra e completa as V − 1 = 5 arestas. Total 1 + 2 + 2 + 3 + 5 = 13.
B-D não pode ser rejeitada: é a única ligação barata entre {A, B, C} e
{D, E, F}. Veja 0152.

</details>

**2.** No mesmo grafo, o Prim a partir de A acrescenta as arestas em que
ordem?

- (A) A-C, C-B, B-D, D-E, E-F
- (B) A-C, B-C, D-E, E-F, B-D
- (C) A-C, C-B, A-B, B-D, D-E
- (D) A-B, B-C, B-D, D-E, E-F
- (E) A-C, C-B, C-D, D-E, E-F

<details><summary>Gabarito</summary>

**(A).** O Prim mantém uma árvore só e sempre pega a aresta mais leve que
sai dela: de {A}, A-C 1; de {A, C}, C-B 2; de {A, B, C}, a mais leve para
fora é B-D 5 (C-D custa 8, C-E 10); depois D-E 2 e E-F 3. Mesmo total do
Kruskal (13), outra ordem. A alternativa B é a ordem do **Kruskal**. Veja
0153.

</details>

**3.** No grafo dirigido com as arestas A→B, A→C, B→D, C→D, D→E, C→F e
F→E, qual sequência **não** é uma ordenação topológica?

- (A) A, B, C, D, F, E
- (B) A, C, F, B, D, E
- (C) A, C, B, F, D, E
- (D) A, C, B, D, F, E
- (E) A, B, C, F, E, D

<details><summary>Gabarito</summary>

**(E).** A aresta D→E exige D antes de E, e em (E) o E vem antes do D. As
outras respeitam todas as setas: a ordenação topológica raramente é única.
No Cormen, ela sai da DFS em ordem decrescente do tempo de término; o Kahn
dá outra ordem válida. Veja 0151.

</details>

**4.** O Bellman-Ford roda a partir de `s` no grafo dirigido com as arestas
s→a (2), a→b (3), c→d (−3) e d→c (1). O que ele devolve?

- (A) FALSO, porque há um ciclo de peso negativo (c, d, c).
- (B) VERDADEIRO, com `a.d = 2`, `b.d = 5` e `c.d = d.d = ∞`.
- (C) VERDADEIRO, com `c.d = −∞` e `d.d = −∞`.
- (D) Ele não termina, porque as distâncias de c e d caem sem parar.
- (E) FALSO, porque há uma aresta de peso negativo.

<details><summary>Gabarito</summary>

**(B).** O ciclo c→d→c pesa −2, mas não é **alcançável** a partir de `s`:
`c.d` e `d.d` continuam ∞, nenhuma aresta melhora na rodada extra, e o
algoritmo devolve VERDADEIRO. Ele termina sempre (são V − 1 rodadas fixas)
e aceita pesos negativos; só devolve FALSO com ciclo negativo alcançável.
Acrescente b→c (1) e a resposta vira FALSO. Veja 0154.

</details>

**5.** Sobre caminhos mínimos, analise as afirmações.

- I. O Dijkstra funciona com pesos negativos, desde que não haja ciclo
  negativo.
- II. O Floyd-Warshall custa Θ(V³) de tempo e Θ(V²) de memória.
- III. Num DAG com pesos negativos, relaxar as arestas na ordem topológica dá
  os caminhos mínimos em O(V + E).

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**(C).** I é falsa: o Dijkstra pode errar com qualquer peso negativo, mesmo
sem ciclo negativo (o exemplo do motoboy no 0154); quem aceita pesos
negativos sem ciclo negativo é o Bellman-Ford, em O(V · E). II: três laços de
V voltas e uma matriz V × V. III: no DAG não há ciclo, e cada vértice é
relaxado depois de todos os seus antecessores. Veja 0151, 0154 e 0155.

</details>

**6.** O Floyd-Warshall roda no grafo dirigido com os vértices 1 a 4 e as
arestas 1→2 (3), 1→3 (8), 2→3 (2), 2→4 (7), 3→4 (1) e 4→1 (2). Seja
`d14^(k)` a distância de 1 a 4 usando como passagem só os vértices 1..k.
Quanto valem `d14^(2)` e `d14^(4)`?

- (A) ∞ e 6
- (B) 10 e 10
- (C) 7 e 6
- (D) 9 e 6
- (E) 10 e 6

<details><summary>Gabarito</summary>

**(E).** Não há aresta 1→4, então `d14^(0) = d14^(1) = ∞`. Com o 2 liberado,
1→2→4 = 3 + 7 = 10. Com o 3, 1→2→3→4 = 3 + 2 + 1 = 6, e liberar o 4 não
melhora. Veja 0155.

</details>

**7.** O programa roda uma DFS com cores (0 branco, 1 cinza, 2 preto) no
grafo dirigido com as arestas 0→1, 1→2, 2→0, 0→3, 3→4, 4→3 e 2→4, e conta as
arestas que chegam a um vértice **cinza**. O que ele mostra?

```c
#include <stdio.h>

int g[5][5], cor[5], voltas = 0;

void dfs(int u) {
    cor[u] = 1;
    for (int v = 0; v < 5; v++) {
        if (!g[u][v]) continue;
        if (cor[v] == 1) voltas++;
        else if (cor[v] == 0) dfs(v);
    }
    cor[u] = 2;
}

int main(void) {
    int e[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 3}, {2, 4}};
    for (int k = 0; k < 7; k++) g[e[k][0]][e[k][1]] = 1;
    for (int u = 0; u < 5; u++)
        if (cor[u] == 0) dfs(u);
    printf("%d\n", voltas);
    return 0;
}
```

- (A) 0
- (B) 1
- (C) 2
- (D) 3
- (E) 4

<details><summary>Gabarito</summary>

**(C).** A DFS desce 0, 1, 2; de 2, a aresta 2→0 chega a um vértice cinza (uma
aresta de retorno, e o ciclo 0, 1, 2). A aresta 2→4 é de árvore: o 4 ainda é
branco e a DFS desce por ele. De 4, vai para 3 (branco); do 3, a aresta 3→4
chega ao 4, que está cinza: segunda aresta de retorno, o ciclo 3, 4. A aresta
4→3 já foi tratada como aresta da árvore, e 0→3 chega depois ao 3, já preto.
Cinza na pilha significa ciclo. Veja 0150.

</details>

**8.** Quantos componentes **fortemente conexos** tem o grafo dirigido com
os vértices 1 a 8 e as arestas 1→2, 2→3, 3→1, 3→4, 4→5, 5→4, 5→6, 6→7,
7→8 e 8→6?

- (A) 1
- (B) 2
- (C) 4
- (D) 3
- (E) 8

<details><summary>Gabarito</summary>

**(D).** {1, 2, 3}, {4, 5} e {6, 7, 8}: dentro de cada grupo, todo mundo
alcança todo mundo seguindo as setas. As setas 3→4 e 5→6 só vão para a
frente, então os grupos não se fundem. Ignorando a direção, o grafo é um
componente só (A), que é a conectividade **fraca**. Veja 0150.

</details>

**9.** Sobre árvores geradoras mínimas (MST) de um grafo conexo e não
dirigido, analise as afirmações.

- I. Se todos os pesos forem distintos, a MST é única.
- II. Com pesos repetidos, o Kruskal e o Prim podem devolver árvores
  diferentes, mas sempre com o mesmo peso total.
- III. A MST sempre dá o caminho mínimo entre quaisquer dois vértices.
- IV. A MST sempre contém a aresta de maior peso do grafo.

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) II e III, apenas.
- (C) III e IV, apenas.
- (D) I, II e IV, apenas.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**(A).** I e II decorrem da propriedade do corte: a aresta leve que cruza um
corte é segura, e com empates há mais de uma MST de mesmo total. III é falsa:
no 0153, a árvore do Dijkstra gasta 21 m e a do Prim, 18 m. IV é falsa: a
aresta mais pesada de um ciclo, se for a única com aquele peso, não entra em
MST nenhuma. Veja 0152 e 0153.

</details>

**10.** Qual a complexidade do Kruskal (com union-find por posto e
compressão de caminho) e do Prim com heap binário, num grafo com `V`
vértices e `E` arestas?

- (A) O(V²) e O(E²)
- (B) O(E log V) e O(E log V)
- (C) O(V · E) e O(V³)
- (D) O(E) e O(V)
- (E) O(E log E) e O(V²) obrigatoriamente

<details><summary>Gabarito</summary>

**(B).** O Kruskal é dominado pela ordenação, O(E log E) = O(E log V)
porque E < V². O Prim faz até E operações no heap, cada uma O(log V). O
Prim com vetor em vez de heap é que custa O(V²), bom para grafo denso (o
A305); com um heap de Fibonacci, o Prim chega a O(E + V log V). Veja 0152 e
0153.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 20 (busca em profundidade, ordenação topológica e componentes fortemente conexos), cap. 21 (árvores geradoras mínimas: Kruskal e Prim), cap. 22 (caminhos mínimos de fonte única: Bellman-Ford, DAG e Dijkstra) e cap. 23 (caminhos mínimos entre todos os pares: Floyd-Warshall).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Cap. 7 (algoritmos em grafos: busca em profundidade e em largura, ordenação topológica, componentes fortemente conectados, árvore geradora mínima e caminhos mais curtos).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Rascunho. Capítulos sobre grafos, árvores geradoras mínimas e caminhos mínimos.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Seção sobre ordenação topológica.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 8: grafos e suas aplicações (fecho transitivo, Warshall, árvore geradora mínima, escalonamento por contagem).
- FEOFILOFF, P. *Algoritmos para grafos*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos_para_grafos/>.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009.
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seções 4.2 (grafos dirigidos), 4.3 (árvores geradoras mínimas) e 4.4 (caminhos mínimos). Disponível em: <https://algs4.cs.princeton.edu/>.
- KRUSKAL, J. B. On the shortest spanning subtree of a graph and the traveling salesman problem. *Proceedings of the American Mathematical Society*, v. 7, n. 1, p. 48-50, 1956.
- PRIM, R. C. Shortest connection networks and some generalizations. *Bell System Technical Journal*, v. 36, n. 6, p. 1389-1401, 1957.
- BELLMAN, R. On a routing problem. *Quarterly of Applied Mathematics*, v. 16, n. 1, p. 87-90, 1958.
- FLOYD, R. W. Algorithm 97: shortest path. *Communications of the ACM*, v. 5, n. 6, p. 345, 1962.
- KAHN, A. B. Topological sorting of large networks. *Communications of the ACM*, v. 5, n. 11, p. 558-562, 1962.
- CPPREFERENCE. *qsort, qsort_s* e *INFINITY*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
