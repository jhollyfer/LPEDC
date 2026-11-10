## 0154 · Bellman-Ford: pesos negativos

O motoboy sai da Base para chegar em Casa gastando o mínimo. Alguns trechos
coincidem com uma corrida que paga mais que a gasolina: do Shopping ao
Centro ele gasta R$ 2 e recebe R$ 6, um **custo líquido** de **R$ -4**.

O grafo é dirigido e tem **pesos negativos**, onde o Dijkstra (assunto 0112)
quebra. Ele fixa o Centro com R$ 4 (direto da Base) antes de olhar o
Shopping, mas Base, Shopping, Centro custa 6 - 4 = **R$ 2**. A premissa
"somar pesos só aumenta" falha, e ele diz que Casa custa R$ 12, quando custa
R$ 10.

O **Bellman-Ford** não fixa ninguém cedo. Ele **relaxa todas as arestas**,
uma rodada inteira por vez, sem escolher o menor:

- `dist[origem] = 0` e INFINITO no resto;
- repita V - 1 vezes: para cada aresta `u -> v` com custo `c`, se
  `dist[u] + c < dist[v]`, atualize `dist[v]` e `anterior[v]` (no Cormen,
  `v.d` e `v.π`; esse teste é o `RELAX`).

V - 1 rodadas bastam: um caminho mínimo não repete vértice e tem no máximo
V - 1 arestas, e a rodada `i` acerta a `i`-ésima. Uma rodada sem mudança
permite parar antes.

Um **ciclo negativo** (circuito de soma menor que zero) elimina o caminho
mínimo: cada volta diminui o custo. Uma rodada extra **detecta** o ciclo: se
depois das V - 1 rodadas alguma aresta ainda melhora, há ciclo negativo
alcançável.

O custo é **O(V · E)**, contra O((V + E) log V) do Dijkstra com heap: com
peso negativo, Bellman-Ford; sem ele, Dijkstra. Num DAG, relaxar cada aresta
uma vez na ordem topológica (0151) dá os mínimos em O(V + E), mesmo com
pesos negativos.

No desenho, as setas mostram o custo líquido, cada lugar mostra a `dist`
final, e a rota até Casa é verde. Embaixo, o vetor `dist` a cada rodada:

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

Com a lista na ordem "natural" (arestas da Base primeiro), uma rodada já
bastaria; o A308 mede isso. O A307 caça um ciclo negativo numa tabela de
câmbio.

> [!WARNING]
> Com `INT_MAX` como INFINITO, o teste `dist[u] != INFINITO` é obrigatório:
> `INT_MAX + (-4)` **não** estoura, dá `INT_MAX - 4`, e um vértice
> inalcançável "melhora" outro com uma distância gigante e falsa. Em grafo
> **não dirigido**, uma aresta negativa já é um ciclo negativo (ir e voltar).

> [!NOTE]
> **Pergunta para você:** se a corrida da Faculdade para o Hospital passar a
> pagar mais (custo -6 em vez de -2), qual a nova rota até Casa e quanto ela
> custa? E se, além disso, existir um trecho Hospital -> Faculdade de custo
> 3, o que o programa mostra?

{{pratique}}
