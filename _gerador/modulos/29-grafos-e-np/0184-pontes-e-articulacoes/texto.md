## 0184 · Pontes e articulações

A operadora ligou sete bairros de Manaus com fibra. Se um cabo for cortado,
algum bairro fica sem sinal? E se a central de um bairro pegar fogo? São as
duas perguntas de **conectividade** do edital:

- **ponte** (aresta de corte): aresta cuja remoção aumenta o número de
  componentes conexos (0150);
- **vértice de articulação** (ponto de corte): vértice cuja remoção, com as
  arestas dele, aumenta o número de componentes.

Tirar cada cabo e rodar uma DFS custa O(E · (V + E)) (o A368 confere). **Uma
DFS só**, O(V + E), anota dois números por vértice.

**tin[u]** é o tempo de descoberta: o relógio da DFS ao entrar em `u`.
**low[u]** é o menor `tin` que a subárvore de `u` alcança descendo pela árvore
e usando **uma** aresta de volta para um ancestral.

Numa DFS não dirigida só há arestas da **árvore** (a um vértice novo) e de
**volta** (a um ancestral); nenhuma "cruza" para o lado. `low` mede quanto a
subárvore escapa para cima sem passar pelo pai.

Para uma aresta da árvore `u - v` (v filho de u):

- **ponte** se `low[v] > tin[u]`: nada abaixo de `v` volta a `u` ou acima;
- **articulação** se `low[v] >= tin[u]`, com `u` diferente da raiz: a
  subárvore de `v` volta no máximo ao próprio `u`. Sem `u`, fica sozinha;
- **raiz**: a regra anterior vale sempre para ela, então não serve. A raiz é
  articulação **só com dois ou mais filhos** na árvore da DFS.

Do Centro, a DFS desce em ordem de índice. Ao lado de cada bairro, `tin/low`.
As arestas verdes são as pontes; os bairros em amarelo, as articulações:

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

No fluxograma, as duas perguntas vêm **na volta** da recursão, com `low[v]`
completo:

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

> [!WARNING]
> Dois erros clássicos. Usar `low[v] >= tin[u]` também na raiz: sempre dá
> verdadeiro, e o Centro apareceria como articulação sem ser (o A367 mostra).
> E trocar `>` por `>=` na ponte: toda aresta que sai da raiz para um ciclo
> vira ponte falsa.

> [!NOTE]
> **Pergunta para você:** a operadora vai passar um cabo novo entre Ponta
> Negra e o Centro (`{6, 0}`). Quais pontes e articulações sobram?

{{pratique}}
