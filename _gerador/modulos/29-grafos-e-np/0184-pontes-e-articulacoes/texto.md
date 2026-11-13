## 0184 · Pontes e articulações

Uma operadora liga sete bairros com cabos de fibra. Duas perguntas tiram o
sono do engenheiro: se um cabo for cortado, algum bairro fica sem sinal? E se
a central de um bairro pegar fogo, os outros continuam se falando? Essas são
as duas perguntas de **conectividade** do edital, e as duas têm resposta com
uma única busca em profundidade.

Lembre que um grafo não dirigido se divide em **componentes conexos**, os
pedaços dentro dos quais todo vértice alcança todo outro (0150). Uma **ponte**,
também chamada aresta de corte, é uma aresta cuja remoção aumenta o número de
componentes: sem ela, o grafo se parte. Um **vértice de articulação**, também
chamado ponto de corte, é um vértice cuja remoção, junto com as arestas que
tocam nele, aumenta o número de componentes (SZWARCFITER, 2018). Na rede da
operadora, a ponte é o cabo que, cortado, isola um bairro; a articulação é a
central que, fora do ar, separa a rede em dois.

O jeito ingênuo de achar as pontes é tirar uma aresta de cada vez e rodar uma
DFS para ver se o grafo continua conexo. São E buscas de custo O(V + E) cada,
O(E · (V + E)) no total. Tarjan mostrou que basta **uma DFS só**, O(V + E),
desde que ela anote dois números em cada vértice (TARJAN, 1972).

O primeiro número é **tin[u]**, o tempo de descoberta: a DFS mantém um
relógio que avança cada vez que ela entra num vértice novo, e `tin[u]` é o
valor do relógio na entrada de `u`. Quanto menor o `tin`, mais perto da raiz
da DFS o vértice está no caminho atual. O segundo é **low[u]**: o menor `tin`
que dá para alcançar a partir de `u` descendo pela árvore da DFS e usando, no
fim, **uma** aresta de volta para um ancestral (FEOFILOFF, s.d., *Algoritmos
para grafos*). Ele mede até onde a subárvore de `u` consegue escapar para cima
sem passar pela aresta que liga `u` ao pai.

O `low` funciona por causa de uma propriedade da DFS em grafo não dirigido:
toda aresta é ou da **árvore**, quando leva a um vértice ainda não visitado,
ou de **volta**, quando leva a um ancestral. Não existe aresta que cruze para
um galho vizinho da árvore, porque a DFS teria seguido por ela antes de
terminar o primeiro galho (CORMEN et al., 2024, cap. 20). Assim, a única
forma de uma subárvore se ligar ao resto é pela aresta do pai ou por arestas
de volta, e o `low` mede exatamente as arestas de volta.

As regras saem disso, olhando uma aresta da árvore `u - v`, com `v` filho de
`u`, na volta da recursão, quando `low[v]` já está completo (TARJAN, 1972). A
aresta é **ponte** se `low[v] > tin[u]`: nada abaixo de `v` alcança `u` ou
algum vértice acima dele, então cortar `u - v` isola a subárvore de `v`. O
vértice `u` é **articulação** se `low[v] >= tin[u]` e `u` não é a raiz: a
subárvore de `v` volta no máximo até o próprio `u`, e sem `u` ela fica
sozinha. A diferença entre `>` e `>=` é a diferença entre cortar um cabo e
derrubar uma central: se `low[v]` é igual a `tin[u]`, a subárvore tem outro
cabo até `u`, mas nenhum caminho que desvie de `u`.

A raiz da DFS precisa de uma regra própria. Ela tem o menor `tin` de todos,
então `low[v] >= tin[u]` vale sempre para os filhos dela, e a regra acima
marcaria toda raiz como articulação. O critério certo é outro: a raiz é
articulação **só se tiver dois ou mais filhos** na árvore da DFS. Se tem dois
filhos, não há aresta entre as subárvores deles (seria de cruzamento), e
tirar a raiz as separa.

> [!WARNING]
> Usar `low[v] >= tin[u]` também na raiz sempre dá verdadeiro e a marca como
> articulação sem ser. E trocar `>` por `>=` na ponte cria pontes falsas em
> toda aresta que entra num ciclo.

{{exemplo}}

Uma operadora liga sete bairros de Manaus com fibra: que cabo cortado deixa
bairro sem sinal? Do Centro, a DFS desce em ordem de índice. Ao lado de cada
bairro, `tin/low`; verdes são as pontes, amarelos as articulações:

{{ideia}}

```c
#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *bairros[V] = {"Centro", "Aleixo", "Adrianópolis", "Flores", "Cidade Nova", "Tarumã", "Ponta Negra"};
int fibra[V][V];
int tin[V];    // tempo de descoberta (0 = ainda não visitado)
int low[V];    // menor tin que a subárvore alcança com UMA aresta de volta
bool corte[V]; // vértice de articulação
int relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    int filhos = 0;
    for (int v = 0; v < V; v++) {
        if (!fibra[u][v] || v == pai) continue;
        if (tin[v] != 0) {                  // aresta de volta: v é ancestral
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        filhos++;
        dfs(v, u);                          // aresta da árvore u - v
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u])                // v não volta acima de u
            printf("Ponte: %s - %s\n", bairros[u], bairros[v]);
        if (pai != -1 && low[v] >= tin[u])  // v não volta acima de u nem pula u
            corte[u] = true;
    }
    if (pai == -1 && filhos >= 2) corte[u] = true; // raiz: caso especial
}

int main(void) {
    int cabos[][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    for (int k = 0; k < 8; k++) fibra[cabos[k][0]][cabos[k][1]] = fibra[cabos[k][1]][cabos[k][0]] = 1;

    dfs(0, -1);
    printf("Articulações:");
    for (int u = 0; u < V; u++)
        if (corte[u]) printf(" %s", bairros[u]);
    printf("\n");
    for (int u = 0; u < V; u++) printf("%s: tin %d, low %d\n", bairros[u], tin[u], low[u]);
    return 0;
}
// Saída:
// Ponte: Tarumã - Ponta Negra
// Ponte: Aleixo - Flores
// Articulações: Aleixo Flores Tarumã
// Centro: tin 1, low 1
// Aleixo: tin 2, low 1
// Adrianópolis: tin 3, low 1
// Flores: tin 4, low 4
// Cidade Nova: tin 5, low 4
// Tarumã: tin 6, low 4
// Ponta Negra: tin 7, low 7
```

As duas perguntas vêm **na volta** da recursão, com `low[v]` completo:

{{fluxograma}}

### Passo a passo

| Evento | tin / low atualizados | Conclusão |
| --- | --- | --- |
| entra em Centro, Aleixo, Adrianópolis | tin 1, 2, 3 | |
| Adrianópolis vê Centro (volta) | low[Adrianópolis] = 1 | |
| volta a Aleixo | low[Aleixo] = 1 | Aleixo - Adrianópolis não é ponte (1 ≤ 2) |
| entra em Flores, Cidade Nova, Tarumã | tin 4, 5, 6 | |
| Tarumã vê Flores (volta) | low[Tarumã] = 4 | |
| entra em Ponta Negra; ela não tem volta | tin 7, low 7 | 7 > 6: **ponte** Tarumã - Ponta Negra; Tarumã é **articulação** |
| volta a Cidade Nova | low = 4 | 4 ≤ 5: nada |
| volta a Flores | low = 4 | 4 ≥ 4: Flores é **articulação**; 4 > 4 é falso: não é ponte |
| volta a Aleixo | low[Flores] = 4 | 4 > 2: **ponte** Aleixo - Flores; Aleixo é **articulação** |
| volta ao Centro (raiz) | | um filho só: **não** é articulação |

Flores é articulação, mas Flores - Cidade Nova não é ponte (o triângulo tem
dois caminhos): a diferença é o `>` contra o `>=`.
