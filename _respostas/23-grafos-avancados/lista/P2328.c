// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2328 · ★★★ · Três zonas de entrega

#include <stdio.h>
#include <stdlib.h>

#define V 9
#define K 3
#define MAXE (V * (V - 1) / 2)

typedef struct {
    int a, b, dist;
} Aresta;

const char *bairros[V] = {"Aleixo", "Flores", "Parque 10", "Compensa", "Glória",
                          "Santo Antônio", "Japiim", "Coroado", "Distrito"};
int x[V] = {2, 3, 2, 10, 11, 9, 6, 7, 6};
int y[V] = {9, 8, 7, 2, 3, 1, 9, 10, 11};
int pai[V];

int acha(int v) {
    if (pai[v] != v) pai[v] = acha(pai[v]);
    return pai[v];
}

int compara(const void *p, const void *q) {
    const Aresta *u = p, *w = q;
    if (u->dist != w->dist) return u->dist - w->dist;
    if (u->a != w->a) return u->a - w->a; // desempate fixo: a saída não muda
    return u->b - w->b;
}

int main(void) {
    Aresta e[MAXE];
    int n = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) e[n++] = (Aresta){i, j, abs(x[i] - x[j]) + abs(y[i] - y[j])};
    qsort(e, n, sizeof(Aresta), compara);

    for (int v = 0; v < V; v++) pai[v] = v;
    int grupos = V, i = 0;
    for (; i < n && grupos > K; i++) { // Kruskal que para com K grupos
        int ra = acha(e[i].a), rb = acha(e[i].b);
        if (ra == rb) continue;
        pai[ra] = rb;
        grupos--;
    }
    // a próxima aresta entre grupos diferentes é o espaçamento
    while (acha(e[i].a) == acha(e[i].b)) i++;

    int zona[V], z = 0;
    for (int v = 0; v < V; v++) zona[v] = -1;
    for (int v = 0; v < V; v++) {
        if (zona[v] != -1) continue;
        z++;
        printf("Zona %d:", z);
        for (int w = v; w < V; w++)
            if (acha(w) == acha(v)) {
                zona[w] = z;
                printf(" %s", bairros[w]);
            }
        printf("\n");
    }
    printf("Espaçamento: %d km (%s-%s)\n", e[i].dist, bairros[e[i].a], bairros[e[i].b]);
    return 0;
}
