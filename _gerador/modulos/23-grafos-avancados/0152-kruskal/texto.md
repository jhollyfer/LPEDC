## 0152 · Kruskal: árvore geradora mínima

A prefeitura quer asfaltar estradas entre seis vilas: Sede, Ponte, Brejo,
Serra, Lagoa e Vale. A engenharia orçou nove trechos, de R$ 2 mil a R$ 9 mil.
Depois da obra, deve dar para ir de qualquer vila a qualquer outra.

O pedido é um conjunto de estradas que **ligue todo mundo** com a **menor
soma**, não o caminho mais curto entre duas vilas. Esse conjunto nunca tem
ciclo: num ciclo, tirar a estrada mais cara mantém tudo ligado, por menos.
Um grafo conexo e sem ciclo é uma **árvore**, e uma árvore com V vértices
tem **V - 1 arestas**.

A **árvore geradora mínima** (MST, de *minimum spanning tree*) toca todos
os vértices com a menor soma de pesos, num grafo **não dirigido** e
ponderado.

O **Kruskal** é guloso (assunto 0133):

1. ordene as arestas da mais barata para a mais cara;
2. percorra a lista e **aceite** cada aresta que **não feche ciclo** com as
   já aceitas;
3. pare com V - 1 arestas.

O passo 2 usa o **union-find** do assunto 0148: cada grupo de vilas ligadas
é um conjunto. Se `acha(a)` e `acha(b)` dão o mesmo representante, a aresta
fecharia um ciclo; senão, `une` junta os grupos. A ordenação domina o custo:
O(E log E) = O(E log V), porque E < V². O union-find custa quase O(1) por
operação.

O guloso acerta pela **propriedade do corte**: toda árvore que liga tudo
cruza de um grupo ao outro, e cruzar pela aresta mais barata nunca é pior.
No Cormen, essa aresta **leve** é **segura**: entra sem estragar a MST.

No desenho, verde entrou, vermelho fecharia ciclo e cinza nem foi olhado,
porque as 5 arestas já tinham saído:

{{ideia}}

A lista de arestas é ordenada com o `qsort` (assunto 0096); o union-find usa
compressão de caminho e união por tamanho:

```c
#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo; // estrada entre a e b, em R$ mil
} Aresta;

const char *vilas[V] = {"Sede", "Ponte", "Brejo", "Serra", "Lagoa", "Vale"};
int pai[V], tamanho[V];

int acha(int x) { // representante do grupo de x, com compressão de caminho
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

void une(int ra, int rb) { // junta dois grupos: o menor pendura no maior
    if (tamanho[ra] < tamanho[rb]) {
        int t = ra;
        ra = rb;
        rb = t;
    }
    pai[rb] = ra;
    tamanho[ra] += tamanho[rb];
}

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    if (x->custo != y->custo) return x->custo - y->custo;
    return x->a - y->a; // empate: decide pelo primeiro vértice
}

int main(void) {
    Aresta estradas[E] = {{0, 2, 4}, {1, 2, 3}, {0, 1, 6}, {2, 3, 8}, {1, 3, 5},
                          {1, 4, 9}, {3, 4, 2}, {3, 5, 7}, {4, 5, 7}};
    qsort(estradas, E, sizeof(Aresta), compara); // 1) da mais barata à mais cara

    for (int v = 0; v < V; v++) { // 2) cada vila começa sozinha
        pai[v] = v;
        tamanho[v] = 1;
    }

    int total = 0, aceitas = 0;
    for (int k = 0; k < E && aceitas < V - 1; k++) { // 3) uma árvore tem V - 1 arestas
        Aresta e = estradas[k];
        int ra = acha(e.a), rb = acha(e.b);
        printf("%s-%s (%d): ", vilas[e.a], vilas[e.b], e.custo);
        if (ra == rb) {
            printf("fecha ciclo\n"); // as duas pontas já estão ligadas
            continue;
        }
        une(ra, rb);
        total += e.custo;
        aceitas++;
        printf("aceita\n");
    }
    printf("Total: R$ %d mil em %d estradas\n", total, aceitas);
    return 0;
}
// Saída:
// Serra-Lagoa (2): aceita
// Ponte-Brejo (3): aceita
// Sede-Brejo (4): aceita
// Ponte-Serra (5): aceita
// Sede-Ponte (6): fecha ciclo
// Serra-Vale (7): aceita
// Total: R$ 21 mil em 5 estradas
```

O laço do fluxograma sai ao acabar a lista ou ao completar V - 1 arestas; o
union-find decide cada aresta:

{{fluxograma}}

### Passo a passo

A Sede-Ponte chega quando as duas já estão no mesmo grupo, ligadas pelo
Brejo:

| Aresta | `acha` das pontas | Decisão | Grupos depois |
| --- | --- | --- | --- |
| (início) | | | {Sede} {Ponte} {Brejo} {Serra} {Lagoa} {Vale} |
| Serra-Lagoa 2 | diferentes | aceita | {Serra, Lagoa}, os outros sozinhos |
| Ponte-Brejo 3 | diferentes | aceita | {Ponte, Brejo} {Serra, Lagoa} {Sede} {Vale} |
| Sede-Brejo 4 | diferentes | aceita | {Sede, Ponte, Brejo} {Serra, Lagoa} {Vale} |
| Ponte-Serra 5 | diferentes | aceita | {Sede, Ponte, Brejo, Serra, Lagoa} {Vale} |
| Sede-Ponte 6 | **iguais** | ciclo | (igual) |
| Serra-Vale 7 | diferentes | aceita | todas juntas: 5 arestas, para |

Lagoa-Vale também custa 7: se viesse antes, entraria no lugar de Serra-Vale,
com **mesmo total**. Com empates, a MST pode não ser única; o custo mínimo é.

O A303 para o Kruskal antes do fim, para separar clientes em regiões. O A304
inverte a ordenação e acha a árvore de **maior** soma.

> [!WARNING]
> Testar `pai[a] != pai[b]` no lugar de `acha(a) != acha(b)` é o erro
> clássico: o `pai` não é o representante, e dois vértices do mesmo grupo
> podem ter pais diferentes. No `qsort`, a subtração `x->custo - y->custo`
> estoura perto de `INT_MAX`; use `(x->custo > y->custo) - (x->custo <
> y->custo)`.

> [!NOTE]
> **Pergunta para você:** se o trecho Ponte-Serra subir de 5 para 10 mil, qual
> estrada entra no lugar dele e qual passa a ser o total? Refaça a tabela
> antes de mudar o `{1, 3, 5}`.

{{pratique}}
