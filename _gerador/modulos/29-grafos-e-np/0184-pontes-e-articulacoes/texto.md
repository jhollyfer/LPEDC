## 0184 · Pontes e articulações

- **Ponte** (aresta de corte): aresta cuja remoção aumenta o número de
  componentes conexos (0150) (SZWARCFITER, 2018).
- **Vértice de articulação** (ponto de corte): vértice cuja remoção, com suas
  arestas, aumenta o número de componentes (SZWARCFITER, 2018).
- **Uma DFS só**: tirar cada aresta e rodar uma DFS custa O(E · (V + E)); a
  DFS com dois números por vértice resolve em O(V + E) (TARJAN, 1972).
- **tin[u]**: o tempo de descoberta de `u`. **low[u]**: o menor `tin` que a
  subárvore de `u` alcança descendo pela árvore e usando **uma** aresta de
  volta (FEOFILOFF, s.d., *Algoritmos para grafos*).
- **Só dois tipos de aresta**: na DFS não dirigida há arestas da árvore e de
  volta (a um ancestral); nenhuma cruza para o lado (CORMEN et al., 2024, cap. 20).
- **As regras**, para `u - v` da árvore: **ponte** se `low[v] > tin[u]`;
  **articulação** se `low[v] >= tin[u]` e `u` não é a raiz; a **raiz** é
  articulação só com dois ou mais filhos na DFS (TARJAN, 1972).

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
