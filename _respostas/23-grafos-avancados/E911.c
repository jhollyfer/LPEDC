// 0152 · Kruskal: árvore geradora mínima
// Exercício E911 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *atracoes[V] = {"Entrada", "Carrossel", "Roda", "Lago", "Castelo", "Montanha"};
int pai[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    return x->custo - y->custo;
}

int main(void) {
    Aresta t[E] = {{0, 1, 4}, {2, 3, 5}, {1, 3, 6}, {0, 2, 7}, {3, 4, 8},
                   {4, 5, 9}, {2, 5, 10}, {1, 4, 11}, {0, 5, 12}};
    qsort(t, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, usados = 0;
    for (int k = 0; k < E && usados < V - 1; k++) {
        int ra = acha(t[k].a), rb = acha(t[k].b);
        if (ra == rb) continue;
        pai[rb] = ra; // liga as RAÍZES; ligar t[k].b a t[k].a desmontava o grupo de b
        usados++;
        total += t[k].custo;
        printf("%s-%s (%d)\n", atracoes[t[k].a], atracoes[t[k].b], t[k].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
