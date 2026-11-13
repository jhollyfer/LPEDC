## 0154 · Bellman-Ford: pesos negativos

O motoboy sai da Base e quer chegar em Casa gastando o mínimo. Alguns
trechos coincidem com uma corrida que paga mais do que a gasolina custa. Do
Shopping ao Centro, por exemplo, ele gasta R$ 2 e recebe R$ 6 de uma
entrega: o **custo líquido** desse trecho é **R$ -4**. O mapa vira um grafo
dirigido com **pesos negativos**, e um algoritmo que você conhece passa a
errar.

O Dijkstra (assunto 0112) fixa a cada passo o vértice mais perto da origem
e nunca mais mexe nele. Isso só é seguro se somar pesos nunca diminui um
custo, porque aí nenhum caminho que passa por um vértice mais distante pode
voltar mais barato (CORMEN et al., 2024, cap. 22). Com peso negativo, essa
premissa cai. No mapa do motoboy, o Dijkstra fixa o Centro com R$ 4, direto
da Base, antes de olhar o Shopping. Mas Base, Shopping, Centro custa
6 - 4 = **R$ 2**. O erro se propaga, e ele diz que Casa custa R$ 12, quando
custa R$ 10.

Para consertar, é preciso uma operação que você já usou sem nome. **Relaxar**
a aresta `u -> v` de custo `c` é perguntar: chegar a `v` passando por `u` é
melhor do que o que eu já sei? Se `dist[u] + c < dist[v]`, sim, e você
atualiza `dist[v]` com o valor novo e anota em `anterior[v]` que o melhor
caminho chega por `u`. No Cormen, esse teste se chama `RELAX`, e os dois
vetores são os atributos `v.d` e `v.π` (CORMEN et al., 2024, cap. 22).

O **algoritmo de Bellman-Ford** não fixa ninguém cedo. Ele começa com
`dist[origem] = 0` e INFINITO para todos os outros. Depois faz **V - 1
rodadas**, e em cada rodada relaxa **todas** as arestas do grafo, uma por
uma, sem escolher a menor nem seguir ordem especial (BELLMAN, 1958). Um
valor errado pode aparecer numa rodada e ser corrigido na seguinte; no
mapa, a Casa aparece com 12 na rodada 3 e cai para 10 na rodada 4.

Por que V - 1 rodadas bastam? Um caminho mínimo nunca repete vértice, então
tem no máximo V vértices e V - 1 arestas. Depois da primeira rodada, a
primeira aresta desse caminho já foi relaxada na ordem certa; depois da
segunda, a segunda; e assim por diante. Na rodada V - 1, o caminho inteiro
está acertado. Se uma rodada passa sem mudar nada, as seguintes também não
mudariam, e dá para parar antes.

Há um caso sem resposta. Um **ciclo negativo** é um circuito cuja soma de
pesos é menor que zero. Se ele é alcançável da origem, dar uma volta nele
diminui o custo, dar duas diminui mais, e o caminho mínimo deixa de existir
(CORMEN et al., 2024, cap. 22). O Bellman-Ford detecta isso com uma **rodada
extra**. Depois das V - 1 rodadas, todos os caminhos mínimos já estariam
certos; se alguma aresta ainda melhora, é porque há um ciclo negativo no
caminho.

O preço da robustez é o tempo. São V - 1 rodadas, cada uma olhando as E
arestas: **O(V · E)**, contra O((V + E) log V) do Dijkstra com heap. A regra
prática: com peso negativo, Bellman-Ford; sem ele, Dijkstra. Há um caso
especial mais barato. Num DAG (0151), basta relaxar cada aresta uma vez, na
ordem topológica, porque quando um vértice é processado tudo o que chega
nele já foi. Isso dá os caminhos mínimos em O(V + E), mesmo com pesos
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
