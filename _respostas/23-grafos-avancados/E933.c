// 0156 · Juntando tudo: o assistente do calouro
// Exercício E933 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7
#define INFINITO 1000000000

typedef struct {
    int a, b, km;
} Estrada;

const char *cidades[V] = {"Capital", "Agreste", "Sertão", "Litoral", "Serra"};
int pai[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

int compara(const void *p, const void *q) {
    const Estrada *x = p, *y = q;
    return x->km - y->km;
}

void floyd(int d[V][V]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    Estrada e[E] = {{0, 3, 3}, {0, 1, 7}, {3, 1, 5}, {1, 2, 6}, {3, 4, 9}, {4, 2, 4}, {0, 4, 10}};
    int todas[V][V], arvore[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) todas[i][j] = arvore[i][j] = (i == j) ? 0 : INFINITO;
    for (int k = 0; k < E; k++) todas[e[k].a][e[k].b] = todas[e[k].b][e[k].a] = e[k].km;

    qsort(e, E, sizeof(Estrada), compara);
    for (int v = 0; v < V; v++) pai[v] = v;
    int total = 0, usadas = 0;
    printf("Rede mínima:");
    for (int k = 0; k < E && usadas < V - 1; k++) {
        int ra = acha(e[k].a), rb = acha(e[k].b);
        if (ra == rb) continue;
        pai[rb] = ra;
        usadas++;
        total += e[k].km;
        arvore[e[k].a][e[k].b] = arvore[e[k].b][e[k].a] = e[k].km; // só as estradas da árvore
        printf("%s %s-%s", usadas > 1 ? "," : "", cidades[e[k].a], cidades[e[k].b]);
    }
    printf(" (%d km)\n", total);

    floyd(todas);
    floyd(arvore);
    printf("Capital -> Serra pela rede mínima: %d km\n", arvore[0][4]);
    printf("Capital -> Serra pelo melhor caminho: %d km\n", todas[0][4]);
    return 0;
}
