// 0112 · Dijkstra: caminho mínimo
// Exercício E667 · ★☆☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"CD", "A", "B", "C", "D"};
    int km[V][V] = {0};
    int ruas[][3] = {{0, 1, 7}, {0, 2, 2}, {2, 1, 3}, {2, 3, 8}, {1, 3, 1}, {1, 4, 6}, {3, 4, 2}};
    for (int k = 0; k < 7; k++) {
        km[ruas[k][0]][ruas[k][1]] = ruas[k][2];
        km[ruas[k][1]][ruas[k][0]] = ruas[k][2];
    }

    int dist[V], anterior[V];
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
    }
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (km[u][v] && !fixo[v] && dist[u] + km[u][v] < dist[v]) {
                dist[v] = dist[u] + km[u][v];
                anterior[v] = u;
            }
        printf("Fixa %s: dist =", nomes[u]);
        for (int v = 0; v < V; v++) {
            if (dist[v] == INFINITO) printf(" -");
            else printf(" %d", dist[v]);
        }
        printf("\n");
    }

    int destino = 4, rota[V], n = 0;
    for (int v = destino; v != -1; v = anterior[v]) rota[n++] = v;
    printf("Caminho até %s:", nomes[destino]);
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", nomes[rota[i]], i > 0 ? " ->" : "");
    printf(" (%d km)\n", dist[destino]);
    return 0;
}
