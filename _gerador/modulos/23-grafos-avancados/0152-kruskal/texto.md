## 0152 · Kruskal: árvore geradora mínima

A prefeitura tem verba para asfaltar estradas de terra entre seis vilas:
Sede, Ponte, Brejo, Serra, Lagoa e Vale. A engenharia orçou nove trechos
possíveis, de R$ 2 mil a R$ 9 mil. A exigência é uma só: depois da obra, dá
para ir de qualquer vila a qualquer outra pelo asfalto. E o prefeito quer
gastar o mínimo.

Repare que ninguém pediu o caminho mais curto entre duas vilas. Pediu um
conjunto de estradas que **ligue todo mundo** com a **menor soma**. Esse
conjunto nunca tem ciclo: num ciclo, dá para tirar a estrada mais cara e
todo mundo continua ligado, mais barato. Um grafo conexo e sem ciclo é uma
**árvore**, e uma árvore com V vértices tem exatamente **V - 1 arestas**.

O que se procura, então, é a **árvore geradora mínima** (MST, de *minimum
spanning tree*): uma árvore que "gera", ou seja, toca todos os vértices, com
a menor soma de pesos possível. O grafo é **não dirigido** e ponderado.

O algoritmo de **Kruskal** é guloso (assunto 0133) e quase óbvio:

1. ordene as arestas da mais barata para a mais cara;
2. percorra a lista e **aceite** cada aresta que **não feche ciclo** com as
   já aceitas;
3. pare quando tiver V - 1 arestas.

A única parte difícil é o passo 2: como saber, rápido, se `a` e `b` já estão
ligados pelas arestas aceitas? É a pergunta que o **union-find** do assunto
0148 responde. Cada grupo de vilas já ligadas é um conjunto. Se `acha(a)` e
`acha(b)` devolvem o mesmo representante, a aresta fecharia um ciclo. Se
não, ela junta dois grupos: `une`.

Por que o guloso acerta aqui? Pegue a aresta mais barata entre dois grupos
quaisquer. Toda árvore que liga tudo precisa atravessar de um grupo para o
outro em algum ponto, e atravessar pela mais barata nunca é pior. Esse
argumento tem nome nos livros: **propriedade do corte**.

Vamos ver na prática. As arestas verdes são as aceitas. Embaixo, a lista
ordenada: verde entrou, vermelho fecharia ciclo, cinza nem foi olhado porque
as 5 arestas já tinham saído:

{{ideia}}

O código guarda as estradas numa lista de arestas (Kruskal não precisa de
matriz), ordena com o `qsort` do assunto 0096 e usa o union-find com
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

Repara no fluxograma: o laço tem duas saídas, acabar a lista ou completar
V - 1 arestas. A pergunta do meio é a do union-find, e ela decide tudo:

{{fluxograma}}

### Passo a passo

Os grupos depois de cada aresta. A Sede-Ponte chega quando Sede e Ponte já
estão no mesmo grupo, ligadas pelo Brejo:

| Aresta | `acha` das pontas | Decisão | Grupos depois |
| --- | --- | --- | --- |
| (início) | | | {Sede} {Ponte} {Brejo} {Serra} {Lagoa} {Vale} |
| Serra-Lagoa 2 | diferentes | aceita | {Serra, Lagoa}, os outros sozinhos |
| Ponte-Brejo 3 | diferentes | aceita | {Ponte, Brejo} {Serra, Lagoa} {Sede} {Vale} |
| Sede-Brejo 4 | diferentes | aceita | {Sede, Ponte, Brejo} {Serra, Lagoa} {Vale} |
| Ponte-Serra 5 | diferentes | aceita | {Sede, Ponte, Brejo, Serra, Lagoa} {Vale} |
| Sede-Ponte 6 | **iguais** | ciclo | (igual) |
| Serra-Vale 7 | diferentes | aceita | todas juntas: 5 arestas, para |

Lagoa-Vale também custa 7. Se ela viesse antes na lista, entraria no lugar
de Serra-Vale: outra árvore, **mesmo total**. Com empates, a MST pode não ser
única; o custo mínimo é.

O A303 usa o Kruskal parado antes do fim para separar clientes em regiões
de entrega. O A304 inverte a ordenação e acha a árvore de **maior** soma, a
das melhores conexões de uma rede Wi-Fi.

> [!WARNING]
> Testar `pai[a] != pai[b]` no lugar de `acha(a) != acha(b)` é o erro clássico.
> O `pai` de um vértice é só o próximo passo rumo ao representante, não o
> representante. Dois vértices do mesmo grupo podem ter pais diferentes, e
> aí a aresta entre eles é aceita, fechando um ciclo e estragando o total. E
> o comparador do `qsort` com `x->custo - y->custo` só é seguro porque os
> custos são pequenos; com valores perto de `INT_MAX`, a subtração estoura.
> Nesse caso, devolva `(x->custo > y->custo) - (x->custo < y->custo)`.

> [!TIP]
> **Por dentro do C:** o `qsort` não conhece `Aresta`. Ele recebe o vetor como
> bytes (`void *`), o tamanho de cada elemento (`sizeof(Aresta)`, 12 bytes) e
> troca blocos de 12 bytes de lugar, chamando `compara` com ponteiros para
> dois blocos. Dentro de `compara`, a conversão de `const void *` para
> `const Aresta *` devolve o tipo. O custo do Kruskal é dominado pela
> ordenação, O(E log E); o union-find, com os dois truques, custa quase O(1)
> por operação. Para mil vilas e 100 mil trechos, uns 1,7 milhão de
> comparações.

> [!NOTE]
> **Pergunta para você:** se o trecho Ponte-Serra subir de 5 para 10 mil, qual
> estrada entra no lugar dele e qual passa a ser o total? Refaça a tabela
> antes de mudar o `{1, 3, 5}`.

{{pratique}}
