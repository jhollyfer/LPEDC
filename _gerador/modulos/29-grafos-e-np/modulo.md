# Módulo 29 · Grafos: ciclos e cortes; problemas difíceis

Os módulos 16 e 23 ensinaram a andar pelo grafo e a tirar dele caminhos,
árvores e ordens. Este módulo fecha o assunto com duas perguntas que a prova
do PPGI cobra pelo nome. A primeira é sobre a **forma** do grafo: dá para
passar por toda aresta uma vez só? E por todo vértice? Qual cabo, se
cortado, parte a rede? A segunda é sobre o **custo** de responder: por que
umas perguntas se resolvem em O(V + E) e outras, muito parecidas, parecem
exigir testar tudo?

A primeira metade (0182 a 0185) é algoritmo puro: graus e o teorema de
Euler, o backtracking do ciclo hamiltoniano, a DFS com `tin` e `low` que
acha pontes e articulações numa passada só, e a programação dinâmica da
cadeia de matrizes. A segunda metade (0186 a 0189) é a teoria por trás da
frase "esse problema é NP-completo": problemas de decisão, verificação em
tempo polinomial, P e NP, reduções, e o que fazer quando o problema é
difícil e a resposta é para hoje: aproximar com garantia ou resolver exato
só quando a entrada é pequena.

A mudança na cabeça é perguntar, antes de "qual o algoritmo?", se o problema
**tem** algoritmo rápido. Euler e Hamilton parecem gêmeos, mas um é fácil e o
outro não. Conferir uma resposta custa menos que achá-la. E quando não se
conhece algoritmo rápido, ainda dá para aproximar ou podar em C.

## O que você vai aprender

- **grau**, grau de entrada e de saída, o **lema do aperto de mãos**, e a
  diferença entre **passeio, trajeto, caminho, circuito e ciclo** (com a
  tabela de nomes do Cormen e do edital)
- a condição de **Euler** e o **circuito euleriano** pelo algoritmo de
  **Hierholzer**
- o **ciclo hamiltoniano** por backtracking, o custo fatorial, e por que ele
  é difícil quando o euleriano é fácil
- **pontes** e **vértices de articulação** com uma DFS só (`tin` e `low`),
  incluindo o caso especial da raiz
- a **multiplicação de cadeia de matrizes** por programação dinâmica: as
  tabelas `m[i][j]` e `s[i][j]` e a parentização ótima
- **problema de decisão**, **certificado** e **verificação polinomial**; as
  classes **P**, **NP**, **NP-difícil** e **NP-completo**; **SAT** e
  **3-SAT**
- **redução polinomial**: conjunto independente, **clique** (pelo grafo
  complemento) e **cobertura de vértices**; 3-SAT para clique
- **algoritmos aproximados**: cobertura de vértices 2-aproximada, **bin
  packing** (first fit e first fit decrescente) e **caixeiro viajante**
  métrico pela árvore mínima
- o caixeiro viajante exato pela PD de **Held-Karp** e quando trocar o exato
  pelo aproximado

## Antes de começar

Este módulo usa sem cerimônia a matriz de adjacência e a DFS (0109, 0111),
os componentes conexos (0150), o Prim (0153), a recursão e o backtracking
(0032, 0126, 0127), a programação dinâmica (0138 a 0140), o `qsort` (0096) e
as máscaras de bits (0065). Se a DFS recursiva estiver enferrujada, releia o
0111 antes do 0184.

Nada fica escondido em TAD: cada arquivo traz o algoritmo completo. Refaça no
papel o **passo a passo** quando houver (a pilha do Hierholzer, os
`tin`/`low` da DFS, a tabela da cadeia de matrizes).
Nos grafos, a origem fica roxa, as arestas verdes
são as escolhidas (o circuito, o ciclo, as pontes, a clique) e, nas
articulações, o amarelo marca os vértices de corte.


Convenções que valem para o módulo todo:

- os vértices são números de 0 a V-1, com os nomes num vetor de strings à
  parte, e os vizinhos são examinados em **ordem crescente de índice**. Isso
  decide os empates: numere diferente e a resposta pode mudar, sem estar
  errada;
- grafo não dirigido guarda cada aresta **duas vezes** na matriz
  (`g[a][b]` e `g[b][a]`); grafo dirigido, uma vez;
- conjuntos pequenos (de vértices ou de variáveis) são **máscaras de bits**
  num `int`: o bit `v` ligado quer dizer "v está no conjunto";
- nas rotas, a distância é em **quarteirões**, `|dx| + |dy|`, que respeita
  a desigualdade triangular;
- os nomes seguem o **Cormen**. Quando o edital ou outro livro usa outro
  nome (trajeto, circuito, percurso de Euler...), o texto avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c`
seu. Eles misturam os assuntos do módulo.

**1. Graus impossíveis.** Existe um grafo simples com cinco vértices, todos
de grau 3? E com seis vértices de graus 5, 5, 4, 3, 2, 1?

<details><summary>Resposta</summary>

O primeiro **não**: a soma dos graus seria 15, ímpar, e ela precisa ser 2E.
O segundo tem soma 20 (par), mas também **não** existe: os dois vértices de
grau 5 são ligados a todos os outros cinco, então o vértice de grau 1 já
estaria ligado a dois. A soma par é necessária, não suficiente. Caminho:
lema do aperto de mãos e um argumento de contagem.

</details>

**2. Königsberg com pontes novas.** As sete pontes de Königsberg ligam 4
margens com graus 5, 3, 3 e 3. Quantas pontes novas, no mínimo, permitem um
circuito euleriano? E um trajeto aberto?

<details><summary>Resposta</summary>

São **4** vértices ímpares. Cada ponte nova muda a paridade de duas pontas.
Para o circuito, **2** pontes (pareando os ímpares). Para o trajeto aberto,
basta sobrarem 2 ímpares: **1** ponte. É o raciocínio do E1092 ao contrário.

</details>

**3. Euler e Hamilton no cubo.** O cubo tem 8 vértices e 12 arestas, todos os
vértices de grau 3. Ele tem circuito euleriano? E ciclo hamiltoniano?

<details><summary>Resposta</summary>

Circuito euleriano, **não** (grau 3 é ímpar). Ciclo hamiltoniano, **sim**:
numere os vértices de 000 a 111 e percorra 000, 001, 011, 010, 110, 111,
101, 100 e volte. Cada passo troca um bit só (é o código de Gray). Um dos
dois pode existir sem o outro.

</details>

**4. Pontes numa árvore.** Numa árvore com n vértices, quantas pontes
existem? Quem são as articulações?

<details><summary>Resposta</summary>

**Todas as n - 1 arestas** são pontes: árvore não tem ciclo, então nenhuma
aresta tem caminho alternativo. As articulações são **os vértices de grau
pelo menos 2** (os que não são folhas), desde que n ≥ 3. Confira com o
programa do texto: em árvore, `low[v] = tin[v]` para todo v.

</details>

**5. Ponte e articulação andam juntas?** Se u - v é ponte, u é articulação?
E o contrário: toda articulação toca uma ponte?

<details><summary>Resposta</summary>

Ponte u - v implica que u é articulação **se u tiver grau pelo menos 2**
(se u for folha, tirá-lo não separa nada). O contrário é **falso**: no
texto, Flores é articulação e as duas arestas dela que ficam no triângulo
não são pontes; numa gravata (A365), o Mirante é articulação e não toca
ponte nenhuma.

</details>

**6. Três matrizes.** A1 é 2 × 50, A2 é 50 × 2 e A3 é 2 × 50. Qual a melhor
ordem e quantas multiplicações ela custa? E a pior?

<details><summary>Resposta</summary>

`(A1 A2) A3`: 2 · 50 · 2 + 2 · 2 · 50 = 200 + 200 = **400**. A outra,
`A1 (A2 A3)`: 50 · 2 · 50 + 2 · 50 · 50 = 5000 + 5000 = **10000**, 25 vezes
mais. Regra de bolso: elimine logo a dimensão grande que está "no meio".

</details>

**7. Certificado para o "não".** Para "o grafo tem ciclo hamiltoniano?", o
certificado do sim é a rota. Qual seria um certificado curto para o "não
tem"?

<details><summary>Resposta</summary>

**Não se conhece nenhum.** "Não ter ciclo hamiltoniano" é um problema de
**co-NP**, e ninguém sabe se NP = co-NP. Em casos especiais existe prova
curta (um vértice de grau 1, uma articulação), mas não em geral. É por isso
que o backtracking do A365 só diz "não" depois de esgotar tudo.

</details>

**8. Estrela.** Na estrela com um centro e 5 pontas, qual a maior clique, o
maior conjunto independente e a menor cobertura? Quanto a 2-aproximação da
cobertura devolve?

<details><summary>Resposta</summary>

Maior clique: **2** (qualquer aresta). Maior independente: **5** (as
pontas). Menor cobertura: **1** (o centro), e 5 + 1 = 6 = n, como manda o
teorema do 0187. A 2-aproximação pega uma aresta e põe as duas pontas:
**2**, exatamente o dobro do ótimo.

</details>

**9. O first fit na ordem pior.** Capacidade 10 e itens 2, 2, 2, 2, 8, 8, 8, 8
(nessa ordem). Quantas caixas o first fit usa? E o first fit decrescente?

<details><summary>Resposta</summary>

First fit: os quatro 2 enchem 8 da primeira caixa, e cada 8 vai sozinho:
**5** caixas. Decrescente: cada 8 abre uma caixa e cada 2 completa uma: **4**,
que é o limite inferior (40 / 10). A ordem dos itens decide o resultado.

</details>

**10. Garantia em números.** Num caixeiro viajante métrico, a árvore geradora
mínima pesa 50. Entre quais valores está o ótimo? E a rota da pré-ordem?

<details><summary>Resposta</summary>

O ótimo é **maior que 50** (tirando uma aresta do ciclo ótimo sobra uma
árvore geradora, que pesa pelo menos 50) e a rota da pré-ordem é **no máximo
100** (duas vezes a árvore). Logo 50 < ótimo ≤ rota ≤ 100.

</details>

**11. Memória do Held-Karp.** Com `int` de 4 bytes, quanto ocupa a tabela
`dp[1 << n][n]` para n = 20 e para n = 30? E a de anteriores?

<details><summary>Resposta</summary>

n = 20: 2²⁰ × 20 × 4 bytes = **80 MB**. n = 30: 2³⁰ × 30 × 4 bytes =
**120 GB** (mais 120 GB para os anteriores, se guardados). O tempo,
O(n² 2ⁿ), também pesa, mas é a memória que costuma parar o exato primeiro.
O E1132 reconstrói a rota sem a segunda tabela.

</details>

## Questões no estilo da prova

Questões objetivas como as da prova do PPGI. Todo código foi compilado e
rodado antes de fixar o gabarito.

**Questão 1.** Um grafo simples não dirigido tem 6 vértices e 9 arestas.
Cinco vértices têm graus 3, 3, 4, 2 e 2. Qual o grau do sexto?

- (A) 1
- (B) 2
- (C) 3
- (D) 4
- (E) 5

<details><summary>Gabarito</summary>

**(D)**. Pelo lema do aperto de mãos, a soma dos graus é 2 × 9 = 18. Os
cinco somam 14, então o sexto tem grau 4. Veja 0182.

</details>

**Questão 2.** Qual destes grafos tem circuito euleriano?

- (A) o completo K4
- (B) o bipartido completo K3,3
- (C) o cubo (8 vértices, grau 3)
- (D) a casinha do A364
- (E) o completo K5

<details><summary>Gabarito</summary>

**(E)**. No K5 todo vértice tem grau 4 (par) e o grafo é conexo. K4, K3,3 e
o cubo têm todos os graus iguais a 3; a casinha tem dois vértices de grau 3
(tem trajeto aberto, não circuito). Veja 0182.

</details>

**Questão 3.** O que o programa mostra?

```c
#include <stdio.h>

int main(void) {
    int g[5][5] = {{0, 1, 1, 0, 0},
                   {1, 0, 1, 1, 1},
                   {1, 1, 0, 1, 1},
                   {0, 1, 1, 0, 0},
                   {0, 1, 1, 0, 0}};
    int impares = 0;
    for (int u = 0; u < 5; u++) {
        int grau = 0;
        for (int v = 0; v < 5; v++) grau += g[u][v];
        if (grau % 2) impares++;
    }
    if (impares == 0) printf("circuito\n");
    else if (impares == 2) printf("trajeto\n");
    else printf("nenhum\n");
    return 0;
}
```

- (A) `circuito`
- (B) `trajeto`
- (C) `nenhum`
- (D) nada
- (E) o programa não compila

<details><summary>Gabarito</summary>

**(A)**. Os graus são 2, 4, 4, 2, 2: nenhum ímpar. (O programa não confere a
conexidade, mas este grafo é conexo.) Veja 0182.

</details>

**Questão 4.** Sobre circuito euleriano e ciclo hamiltoniano, analise as
afirmações.

- I. Decidir se existe circuito euleriano está em P: basta conferir a
  conexidade e se todos os graus são pares.
- II. Verificar se uma sequência de vértices dada é um ciclo hamiltoniano é
  polinomial, mas decidir se o grafo tem algum é NP-completo.
- III. Todo grafo conexo com todos os graus pares tem ciclo hamiltoniano.

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) II, apenas.
- (C) I e II, apenas.
- (D) II e III, apenas.
- (E) I e III, apenas.

<details><summary>Gabarito</summary>

**(C)**. I e II são verdadeiras. III é falsa: a gravata do A365 tem todos os
graus pares (circuito euleriano) e nenhum ciclo hamiltoniano. Para o
hamiltoniano não se conhece teste rápido, só o verificador polinomial. Veja
0183 e 0186.

</details>

**Questão 5.** O programa abaixo roda a DFS com `tin` e `low`. O que ele
mostra?

```c
#include <stdio.h>

int g[6][6], tin[6], low[6], t = 0;

void dfs(int u, int p) {
    tin[u] = low[u] = ++t;
    for (int v = 0; v < 6; v++) {
        if (!g[u][v] || v == p) continue;
        if (tin[v]) { if (tin[v] < low[u]) low[u] = tin[v]; continue; }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) printf("%d-%d\n", u, v);
    }
}

int main(void) {
    int e[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3}};
    for (int k = 0; k < 7; k++) g[e[k][0]][e[k][1]] = g[e[k][1]][e[k][0]] = 1;
    dfs(0, -1);
    return 0;
}
```

- (A) nada
- (B) `2-3`
- (C) `2-3` e `3-4`
- (D) `0-1` e `2-3`
- (E) `2-3`, `3-4` e `4-5`

<details><summary>Gabarito</summary>

**(B)**. São dois triângulos (0-1-2 e 3-4-5) ligados pela aresta 2-3, a única
ponte. Dentro de cada triângulo há caminho alternativo, então `low[v]` volta
ao ancestral e o teste `low[v] > tin[u]` falha. Veja 0184.

</details>

**Questão 6.** Matrizes A1 (5 × 10), A2 (10 × 3), A3 (3 × 12) e A4 (12 × 5).
Qual o menor número de multiplicações escalares para calcular A1 A2 A3 A4?

- (A) 405
- (B) 330
- (C) 580
- (D) 630
- (E) 750

<details><summary>Gabarito</summary>

**(A)**. A ordem ótima é `(A1 A2)(A3 A4)`: 150 + 180 + 5 · 3 · 5 = 405. Da
esquerda para a direita custaria 150 + 180 + 300 = 630; `A1 (A2 (A3 A4))`,
580. O 330 é `m[1][3]` (e também `m[2][4]`), não a cadeia inteira. Veja
0185.

</details>

**Questão 7.** Sobre as classes P e NP, analise as afirmações.

- I. P ⊆ NP.
- II. NP é a classe dos problemas que não têm algoritmo polinomial.
- III. Se algum problema NP-completo tiver algoritmo polinomial, então
  P = NP.
- IV. Já foi provado que P ≠ NP.

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) II e IV, apenas.
- (C) III e IV, apenas.
- (D) I e III, apenas.
- (E) I, II e III, apenas.

<details><summary>Gabarito</summary>

**(D)**. NP é "verificável em tempo polinomial", não "não polinomial" (II é
falsa), e todo problema de P é verificável rápido (I). III é a razão de se
procurar um algoritmo rápido para qualquer NP-completo. IV é falsa: P versus
NP está em aberto. Veja 0186.

</details>

**Questão 8.** Para provar que um problema novo X é NP-difícil, basta:

- (A) reduzir X a SAT em tempo polinomial.
- (B) mostrar que a força bruta de X é exponencial.
- (C) reduzir em tempo polinomial um problema NP-completo conhecido a X.
- (D) mostrar um verificador polinomial para X.
- (E) reduzir X a um problema de P.

<details><summary>Gabarito</summary>

**(C)**. Se um NP-completo Y satisfaz Y ≤p X, um algoritmo rápido para X
resolveria Y. A alternativa (A) é o sentido errado: mostra só que X não é
mais difícil que SAT. (D) mostra que X está em NP, não que é difícil.
Veja 0187.

</details>

**Questão 9.** Num grafo G com 10 vértices, o maior conjunto independente tem
4 vértices. Então:

- (A) a maior clique de G tem 6 vértices.
- (B) a maior clique do complemento de G tem 4 vértices e a menor cobertura de
  vértices de G tem 6.
- (C) a menor cobertura de vértices de G tem 4 vértices.
- (D) a maior clique do complemento de G tem 6 vértices.
- (E) não dá para concluir nada sobre clique e cobertura.

<details><summary>Gabarito</summary>

**(B)**. S é independente em G ⇔ S é clique no complemento ⇔ V − S é
cobertura de G. Maior independente com 4 dá maior clique do complemento com
4 e menor cobertura com 10 − 4 = 6. Sobre a clique do próprio G nada se
conclui (A). Veja 0187.

</details>

**Questão 10.** O programa aplica o first fit com caixas de capacidade 10.
O que ele mostra?

```c
#include <stdio.h>

int main(void) {
    int item[] = {5, 7, 5, 2, 4, 2, 5, 1, 6}, livre[9], caixas = 0;
    for (int i = 0; i < 9; i++) {
        int c = 0;
        while (c < caixas && livre[c] < item[i]) c++;
        if (c == caixas) livre[caixas++] = 10;
        livre[c] -= item[i];
    }
    printf("%d\n", caixas);
    return 0;
}
```

- (A) 3
- (B) 4
- (C) 9
- (D) 6
- (E) 5

<details><summary>Gabarito</summary>

**(E)**. As caixas ficam (5 5), (7 2 1), (4 2), (5) e (6). O limite inferior
é 37 / 10 → 4, e 4 caixas são possíveis, por exemplo (5 5), (7 2 1),
(6 4) e (5 2): o first fit não é ótimo, mas tem garantia. Veja 0188.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Apêndice B (grafos: graus, caminhos, ciclos), cap. 20 (busca em profundidade e o problema do percurso de Euler), cap. 14 (multiplicação de cadeia de matrizes), cap. 34 (NP-completude: verificação, reduções, SAT, 3-SAT, clique, cobertura de vértices, ciclo hamiltoniano, caixeiro viajante) e cap. 35 (algoritmos de aproximação: cobertura de vértices e caixeiro viajante métrico).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 7 (algoritmos em grafos) e cap. 9 (problemas NP-completos e algoritmos aproximados).
- SZWARCFITER, J. L. *Teoria computacional de grafos: os algoritmos*. Rio de Janeiro: Elsevier, 2018. Capítulos sobre conectividade (articulações e pontes), ciclos eulerianos e hamiltonianos.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Capítulo sobre grafos.
- FEOFILOFF, P. *Algoritmos para grafos*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos_para_grafos/>. Seções sobre pontes, articulações e ciclos eulerianos.
- FEOFILOFF, P. *Análise de algoritmos*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/analise_de_algoritmos/>. Seções sobre programação dinâmica, P, NP e reduções.
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Rascunho. Capítulos sobre trilhas eulerianas, redução e P versus NP.
- KLEINBERG, J.; TARDOS, É. *Algorithm design*. Boston: Pearson, 2006. Cap. 8 (NP e intratabilidade) e cap. 11 (algoritmos de aproximação, bin packing).
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seção 6.5 (reduções e intratabilidade). Disponível em: <https://algs4.cs.princeton.edu/>.
- HIERHOLZER, C.; WIENER, C. Über die Möglichkeit, einen Linienzug ohne Wiederholung und ohne Unterbrechung zu umfahren. *Mathematische Annalen*, v. 6, n. 1, p. 30-32, 1873.
- TARJAN, R. E. Depth-first search and linear graph algorithms. *SIAM Journal on Computing*, v. 1, n. 2, p. 146-160, 1972.
- COOK, S. A. The complexity of theorem-proving procedures. In: ACM SYMPOSIUM ON THEORY OF COMPUTING, 3., 1971, Shaker Heights. *Proceedings* [...]. New York: ACM, 1971. p. 151-158.
- KARP, R. M. Reducibility among combinatorial problems. In: MILLER, R. E.; THATCHER, J. W. (ed.). *Complexity of computer computations*. New York: Plenum, 1972. p. 85-103.
- HELD, M.; KARP, R. M. A dynamic programming approach to sequencing problems. *Journal of the SIAM*, v. 10, n. 1, p. 196-210, 1962.
- CHRISTOFIDES, N. *Worst-case analysis of a new heuristic for the travelling salesman problem*. Pittsburgh: Carnegie Mellon University, 1976. Relatório técnico 388.
