// 0152 · Kruskal: árvore geradora mínima
// Exercício E910 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define V 8
#define E 10

typedef struct {
    int a, b, km;
} Aresta;

const char *sitios[V] = {"Ipê", "Buriti", "Jatobá", "Pequi", "Aroeira", "Babaçu", "Cedro", "Juçara"};
int pai[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    return x->km - y->km;
}

int main(void) {
    Aresta cabos[E] = {{0, 2, 3}, {2, 4, 4}, {0, 4, 6}, {4, 6, 2}, {2, 6, 5},
                       {1, 3, 7}, {3, 5, 1}, {5, 7, 3}, {1, 7, 4}, {3, 7, 2}};
    qsort(cabos, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int aceito[E] = {0}, usados = 0, total = 0;
    for (int k = 0; k < E; k++) { // sem parar em V - 1: o grafo pode ser desconexo
        int ra = acha(cabos[k].a), rb = acha(cabos[k].b);
        if (ra == rb) continue;
        pai[rb] = ra;
        aceito[k] = 1;
        usados++;
        total += cabos[k].km;
    }

    int redes = 0;
    for (int u = 0; u < V; u++) {
        int r = acha(u), novo = 1;
        for (int w = 0; w < u; w++)
            if (acha(w) == r) novo = 0;
        if (!novo) continue; // a rede de u já foi mostrada por um sítio anterior
        int km = 0;
        for (int k = 0; k < E; k++)
            if (aceito[k] && acha(cabos[k].a) == r) km += cabos[k].km;
        printf("Rede %d (", ++redes);
        int primeiro = 1;
        for (int v = 0; v < V; v++)
            if (acha(v) == r) {
                printf("%s%s", primeiro ? "" : " ", sitios[v]);
                primeiro = 0;
            }
        printf("): %d km\n", km);
    }
    printf("Sem travessia: %d redes separadas, %d cabos, %d km\n", redes, usados, total);
    return 0;
}
