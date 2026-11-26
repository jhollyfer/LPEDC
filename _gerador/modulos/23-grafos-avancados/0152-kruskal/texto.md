## 0152 · Kruskal: árvore geradora mínima

A prefeitura quer asfaltar estradas entre seis vilas: Sede, Ponte, Brejo,
Serra, Lagoa e Vale. A engenharia orçou nove trechos possíveis, de R$ 2 mil
a R$ 9 mil cada. Depois da obra, deve dar para ir de qualquer vila a
qualquer outra pelo asfalto, e a prefeitura quer gastar o mínimo. Repare no
pedido: não é o caminho mais curto entre duas vilas, é um conjunto de
estradas que **ligue todo mundo** com a **menor soma**.

Esse conjunto nunca tem ciclo. Se três estradas formassem um triângulo,
dava para tirar a mais cara delas e as vilas continuariam ligadas pelas
outras duas, gastando menos. Um grafo conexo e sem ciclo se chama
**árvore**, e uma árvore com V vértices tem sempre **V - 1 arestas**: menos
que isso deixa alguém de fora, mais que isso fecha um ciclo. As seis vilas
ficam ligadas com exatamente cinco estradas.

O problema tem nome. Uma **árvore geradora** de um grafo é uma árvore que
usa arestas do grafo e toca todos os vértices dele. A **árvore geradora
mínima** (MST, de *minimum spanning tree*) é a de menor soma de pesos, num
grafo **não dirigido** e ponderado, em que cada aresta tem um peso (CORMEN et
al., 2024, cap. 21). Redes elétricas, de água e de cabos se planejam assim.

O **algoritmo de Kruskal** é um guloso (assunto 0133) com uma regra só.
Ordene as arestas da mais barata para a mais cara. Percorra a lista e
**aceite** cada aresta que **não feche ciclo** com as já aceitas; recuse as
que fecham. Pare quando tiver V - 1 arestas (KRUSKAL, 1956). Nas vilas, a
Serra-Lagoa (2) entra, a Ponte-Brejo (3) entra, e assim por diante, até que
a Sede-Ponte (6) aparece quando Sede e Ponte já estão ligadas pelo Brejo, e
é recusada.

O passo delicado é saber se uma aresta fecha ciclo. Ela fecha quando as
duas pontas já estão ligadas por arestas aceitas, ou seja, no mesmo grupo.
Grupos que se juntam e nunca se separam são o caso exato do **union-find**
(assunto 0148). Cada grupo de vilas já ligadas é um conjunto. Para a aresta
`a-b`, se `acha(a)` e `acha(b)` dão o mesmo representante, ela fecharia um
ciclo; se não, ela entra e `une` junta os dois grupos (SEDGEWICK; WAYNE,
2011).

O custo é dominado pela ordenação das arestas, O(E log E). Como um grafo
simples tem E < V², log E < 2 log V, e o custo também se escreve O(E log V).
As operações do union-find, com os dois truques do 0148, custam quase O(1)
cada (CORMEN et al., 2024, cap. 21).

Por que o guloso acerta? Divida os vértices em dois grupos quaisquer, um
**corte**. Toda árvore que liga tudo precisa de pelo menos uma aresta
cruzando de um grupo ao outro. A aresta mais barata que cruza o corte se
chama **leve**, e a **propriedade do corte** garante que ela é **segura**:
sempre existe uma MST que a contém, então aceitá-la não estraga nada (CORMEN
et al., 2024, cap. 21). Quando o Kruskal aceita uma aresta, ela é a mais
barata que liga o grupo de uma ponta ao resto, porque todas as mais baratas
já foram vistas antes.

Com pesos repetidos, pode haver mais de uma MST. Nas vilas, a Lagoa-Vale
também custa 7; se viesse antes da Serra-Vale na lista ordenada, entraria no
lugar dela. A árvore muda, mas o custo mínimo, R$ 21 mil, é o mesmo: a MST
pode não ser única, o custo mínimo é.

> [!WARNING]
> Testar `pai[a] != pai[b]` no lugar de `acha(a) != acha(b)` é o erro clássico:
> `pai` não é o representante. E no `qsort`, `x->custo - y->custo` estoura perto
> de `INT_MAX`; use `(x->custo > y->custo) - (x->custo < y->custo)`.

{{exemplo}}

A prefeitura quer asfaltar estradas entre seis vilas com o menor custo, a partir
de nove trechos orçados. Verde entrou, vermelho fecharia ciclo e cinza nem foi
olhado, porque as 5 arestas já tinham saído:

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
com o **mesmo total**.
