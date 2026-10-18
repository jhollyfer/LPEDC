// 0152 · Kruskal: árvore geradora mínima
// Exercício E909 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *vilas[V] = {"Sede", "Ponte", "Brejo", "Serra", "Lagoa", "Vale"};
int pai[V], tamanho[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

void une(int ra, int rb) {
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
    return x->a - y->a;
}

// Kruskal; se obrigatoria >= 0, essa aresta (índice no vetor original) entra primeiro
int kruskal(const Aresta original[], int obrigatoria, int mostrar) {
    Aresta e[E];
    for (int k = 0; k < E; k++) e[k] = original[k];
    for (int v = 0; v < V; v++) {
        pai[v] = v;
        tamanho[v] = 1;
    }
    int total = 0, aceitas = 0;
    if (obrigatoria >= 0) {
        Aresta o = e[obrigatoria];
        une(acha(o.a), acha(o.b));
        total += o.custo;
        aceitas++;
        if (mostrar) printf("%s-%s (%d) obrigatória\n", vilas[o.a], vilas[o.b], o.custo);
    }
    qsort(e, E, sizeof(Aresta), compara);
    for (int k = 0; k < E && aceitas < V - 1; k++) {
        int ra = acha(e[k].a), rb = acha(e[k].b);
        if (ra == rb) continue;
        une(ra, rb);
        total += e[k].custo;
        aceitas++;
        if (mostrar) printf("%s-%s (%d)\n", vilas[e[k].a], vilas[e[k].b], e[k].custo);
    }
    return total;
}

int main(void) {
    Aresta estradas[E] = {{0, 2, 4}, {1, 2, 3}, {0, 1, 6}, {2, 3, 8}, {1, 3, 5},
                          {1, 4, 9}, {3, 4, 2}, {3, 5, 7}, {4, 5, 7}};
    int livre = kruskal(estradas, -1, 0);
    int com_exigencia = kruskal(estradas, 2, 1); // estradas[2] é Sede-Ponte
    printf("Total: R$ %d mil\n", com_exigencia);
    printf("Custo extra da exigência: R$ %d mil\n", com_exigencia - livre);
    return 0;
}
