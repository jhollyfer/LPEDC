## 0184 · Pontes e articulações

A operadora de internet ligou sete bairros de Manaus com fibra óptica. Uma
retroescavadora corta um cabo na obra da avenida: quais cabos, se cortados,
deixam bairros sem sinal? E se a central de um bairro pegar fogo, quais
centrais derrubam a rede dos outros?

Essas são as duas perguntas de **conectividade** que o edital pede pelo nome:

- **ponte** (ou aresta de corte): uma aresta cuja remoção aumenta o número de
  componentes conexos (0150);
- **vértice de articulação** (ou ponto de corte): um vértice cuja remoção,
  junto com as arestas dele, aumenta o número de componentes.

O jeito ingênuo é tirar cada cabo, rodar uma DFS e ver se a rede partiu:
O(E · (V + E)). O A368 faz isso para conferir. O jeito bom faz **uma DFS
só**, O(V + E), e anota dois números por vértice.

**tin[u]** é o tempo de descoberta: o relógio da DFS no momento em que ela
entra em `u` (a ordem de visita). **low[u]** é o menor `tin` que a
subárvore de `u` consegue alcançar usando arestas da árvore para descer e
**uma** aresta de volta (para um ancestral) para subir.

Numa DFS de grafo não dirigido só existem dois tipos de aresta: as da
**árvore** (levam a um vértice novo) e as de **volta** (levam a um ancestral
já visitado). Nenhuma aresta "cruza" para o lado. Por isso `low` mede
quanto a subárvore consegue escapar para cima sem passar pelo pai.

As duas regras, para uma aresta da árvore `u - v` (v filho de u):

- **ponte** se `low[v] > tin[u]`: nada abaixo de `v` volta a `u` ou acima.
  Cortar `u - v` isola a subárvore de `v`.
- **articulação** se `low[v] >= tin[u]`, com `u` diferente da raiz: a
  subárvore de `v` consegue no máximo voltar ao próprio `u`. Sem `u`, ela
  fica sozinha.
- **raiz**: a regra acima vale para ela sempre (nada tem `tin` menor que o
  dela), então não serve. A raiz é articulação **só se tiver dois ou mais
  filhos** na árvore da DFS: sem ela, os filhos não têm como se falar.

Do Centro, a DFS desce em ordem de índice. Ao lado de
cada bairro, `tin/low`. As arestas verdes são as pontes; os bairros em
amarelo, as articulações:

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

No fluxograma, as duas perguntas acontecem **na volta** da recursão,
depois de `dfs(v, u)`. Só então `low[v]` está completo, porque a subárvore
inteira de `v` já foi explorada:

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

Flores é articulação sem ser ponta de nenhuma ponte (o triângulo dela tem
dois caminhos), e Flores - Cidade Nova não é ponte. As duas perguntas
parecem iguais; o que as separa é o `>` contra o `>=`.

> [!WARNING]
> Dois erros clássicos. Primeiro: usar a regra `low[v] >= tin[u]` também na
> raiz. Ela sempre dá verdadeiro lá, e o Centro apareceria como articulação
> sem ser (tire o Centro e o resto continua ligado). O A367 mostra o
> estrago. Segundo: trocar `>` por `>=` na ponte; aí toda aresta que sai da
> raiz para um ciclo vira ponte falsa. É o bug do E1103.

> [!TIP]
> **Por dentro do C:** `tin`, `low` e `corte` são vetores globais, zerados
> antes do `main`, e por isso `tin[v] == 0` serve de "não visitado". A
> variável `filhos` é **local**: cada frame de `dfs` na pilha tem a sua, e
> por isso a contagem da raiz não se mistura com a dos outros vértices.

> A recursão pode descer V níveis; numa rede com um milhão de bairros em fila
> isso estoura a pilha (8 MB por padrão no Linux), e a versão de produção
> troca a recursão por uma pilha explícita.

> [!NOTE]
> **Pergunta para você:** a operadora vai passar um cabo novo entre Ponta
> Negra e o Centro (`{6, 0}`). Quais pontes e articulações sobram? Responda
> antes de rodar.

{{pratique}}
