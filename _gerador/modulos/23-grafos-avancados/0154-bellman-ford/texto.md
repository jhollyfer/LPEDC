## 0154 · Bellman-Ford: pesos negativos

- **Peso negativo**: o Dijkstra (0112) quebra, porque fixa um vértice cedo
  supondo que somar pesos só aumenta (CORMEN et al., 2024, cap. 22).
- **Relaxar** a aresta `u -> v` de custo `c`: se `dist[u] + c < dist[v]`,
  atualize `dist[v]` e `anterior[v]` (no Cormen, `RELAX`, com `v.d` e `v.π`)
  (CORMEN et al., 2024, cap. 22).
- **Bellman-Ford**: `dist[origem] = 0`, INFINITO no resto, e **V - 1 rodadas**
  relaxando **todas** as arestas, sem escolher o menor (BELLMAN, 1958).
- **Por que V - 1**: um caminho mínimo não repete vértice, tem até V - 1
  arestas, e a rodada `i` acerta a `i`-ésima. Rodada sem mudança permite parar.
- **Ciclo negativo**: circuito de soma menor que zero; acaba com o caminho
  mínimo. Uma **rodada extra** que ainda melhora alguma aresta o detecta
  (CORMEN et al., 2024, cap. 22).
- **Custo**: O(V · E), contra O((V + E) log V) do Dijkstra com heap. Num DAG,
  relaxar cada aresta uma vez na ordem topológica (0151) dá O(V + E), mesmo com
  negativos (CORMEN et al., 2024, cap. 22).

> [!WARNING]
> O teste `dist[u] != INFINITO` é obrigatório: `INT_MAX + (-4)` **não** estoura,
> e um vértice inalcançável "melhora" outro com distância falsa. Em grafo **não
> dirigido**, uma aresta negativa já é um ciclo negativo (ir e voltar).

{{exemplo}}

Um motoboy vai da Base para Casa, e alguns trechos pagam mais que a gasolina:
do Shopping ao Centro o **custo líquido** é R$ -4. O Dijkstra diria R$ 12 até
Casa; o certo é R$ 10. As setas mostram o custo, cada lugar a `dist` final, e
embaixo o vetor `dist` a cada rodada:

{{ideia}}

A lista de arestas começa de propósito pelas que chegam em Casa, para as
rodadas aparecerem.

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define E 9
#define INFINITO 1000000000 // folgado: INFINITO + peso ainda cabe num int

typedef struct {
    int de, para, custo; // custo líquido em R$: gasolina menos o que a corrida paga
} Trecho;

const char *lugares[V] = {"Base", "Shopping", "Centro", "Faculdade", "Hospital", "Casa"};

int main(void) {
    Trecho t[E] = {{4, 5, 3}, {3, 5, 6}, {3, 4, -2}, {2, 3, 9}, {2, 4, 5},
                   {1, 3, 7}, {1, 2, -4}, {0, 2, 4}, {0, 1, 6}};
    int dist[V], anterior[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
    }
    dist[0] = 0;

    for (int rodada = 1; rodada <= V - 1; rodada++) { // no máximo V - 1 rodadas
        bool mudou = false;
        for (int k = 0; k < E; k++) { // relaxa TODAS as arestas, em qualquer ordem
            int u = t[k].de, v = t[k].para;
            if (dist[u] != INFINITO && dist[u] + t[k].custo < dist[v]) {
                dist[v] = dist[u] + t[k].custo;
                anterior[v] = u;
                mudou = true;
            }
        }
        printf("rodada %d:", rodada);
        for (int v = 0; v < V; v++) {
            if (dist[v] == INFINITO) printf(" ∞");
            else printf(" %d", dist[v]);
        }
        printf("\n");
        if (!mudou) break; // nada mudou: as próximas rodadas também não mudariam
    }

    for (int k = 0; k < E; k++) // rodada extra: se ainda melhora, há ciclo negativo
        if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].custo < dist[t[k].para]) {
            printf("Ciclo negativo: dá para lucrar sem fim\n");
            return 0;
        }

    int rota[V], n = 0;
    for (int v = 5; v != -1; v = anterior[v]) rota[n++] = v;
    printf("Até Casa (R$ %d):", dist[5]);
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", lugares[rota[i]], i > 0 ? " ->" : "");
    printf("\n");
    return 0;
}
// Saída:
// rodada 1: 0 6 4 ∞ ∞ ∞
// rodada 2: 0 6 2 13 9 ∞
// rodada 3: 0 6 2 11 7 12
// rodada 4: 0 6 2 11 7 10
// rodada 5: 0 6 2 11 7 10
// Até Casa (R$ 10): Base -> Shopping -> Centro -> Hospital -> Casa
```

O fluxograma não escolhe o menor: rodadas por fora, arestas por dentro, com
saída sem mudança ou após V - 1 rodadas. Depois vem a rodada extra:

{{fluxograma}}

### Passo a passo

A Casa aparece com 12 na rodada 3 (o valor errado do Dijkstra) e cai para 10
na rodada 4, quando a melhora do Centro chega até ela:

| Rodada | O que muda | Base | Shopping | Centro | Faculdade | Hospital | Casa |
| --- | --- | --- | --- | --- | --- | --- | --- |
| início | | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |
| 1 | só as arestas que saem da Base | 0 | 6 | 4 | ∞ | ∞ | ∞ |
| 2 | Centro cai para 6 - 4 = 2 | 0 | 6 | 2 | 13 | 9 | ∞ |
| 3 | o 2 do Centro chega em Faculdade e Hospital | 0 | 6 | 2 | 11 | 7 | 12 |
| 4 | Casa via Hospital: 7 + 3 | 0 | 6 | 2 | 11 | 7 | 10 |
| 5 | nada muda: para | 0 | 6 | 2 | 11 | 7 | 10 |

Com as arestas da Base primeiro na lista, uma rodada já bastaria (A308).
