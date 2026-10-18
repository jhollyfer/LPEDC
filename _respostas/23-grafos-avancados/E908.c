// 0152 · Kruskal: árvore geradora mínima
// Exercício E908 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

#define V 7
#define E 11

typedef struct {
    int a, b, custo;
} Aresta;

const char *predios[V] = {"Reitoria", "Biblioteca", "Lab", "Ginásio", "Cantina", "Auditório", "Portaria"};
int pai[V];

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    return x->custo - y->custo;
}

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]); // sobe até a raiz e pendura x direto nela
    return pai[x];
}

int main(void) {
    Aresta fibras[E] = {{0, 1, 12}, {0, 6, 5}, {1, 2, 7}, {2, 3, 15}, {1, 4, 6}, {4, 5, 9},
                        {5, 3, 8}, {2, 5, 10}, {6, 4, 11}, {3, 6, 20}, {0, 4, 4}};
    qsort(fibras, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, usadas = 0;
    for (int k = 0; k < E && usadas < V - 1; k++) {
        int ra = acha(fibras[k].a), rb = acha(fibras[k].b);
        if (ra == rb) continue;
        pai[rb] = ra;
        usadas++;
        total += fibras[k].custo;
        printf("%s-%s: R$ %d mil\n", predios[fibras[k].a], predios[fibras[k].b], fibras[k].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
