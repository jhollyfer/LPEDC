// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2306 · ★☆☆ · Fibra nas escolas rurais

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 10

typedef struct {
    int a, b, km;
} Aresta;

const char *escolas[V] = {"Sede", "Vila Amazônia", "Caburi", "Mocambo", "Tracajá", "Zé Açu"};
int pai[V];

int acha(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    return x->km - y->km;
}

int main(void) {
    Aresta trechos[E] = {{0, 1, 7}, {0, 2, 12}, {1, 2, 2}, {1, 3, 9}, {2, 3, 6},
                         {2, 4, 10}, {3, 4, 3}, {3, 5, 4}, {4, 5, 5}, {0, 5, 15}};
    qsort(trechos, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int aceitas = 0, total = 0;
    for (int i = 0; i < E && aceitas < V - 1; i++) {
        Aresta t = trechos[i];
        int ra = acha(t.a), rb = acha(t.b);
        if (ra == rb) {
            printf("recusa %s-%s (%d km): fecharia ciclo\n", escolas[t.a], escolas[t.b], t.km);
            continue;
        }
        pai[ra] = rb;
        aceitas++;
        total += t.km;
        printf("aceita %s-%s (%d km)\n", escolas[t.a], escolas[t.b], t.km);
    }
    printf("Total: %d km\n", total);
    return 0;
}
