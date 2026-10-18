// 0117 · Dijkstra: caminho mínimo
// Exercício E699 · ★★☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INFINITO INT_MAX

const char *nomes[V] = {"R", "Ana", "Beto", "Caio", "Dani", "Eva"};
int km[V][V];

void imprimir_rota(const int anterior[], int v) {
    if (anterior[v] != -1) {
        imprimir_rota(anterior, anterior[v]);
        printf(" -> ");
    }
    printf("%s", nomes[v]);
}

int main(void) {
    int ruas[][3] = {{0, 1, 2}, {0, 2, 6}, {1, 2, 3}, {1, 3, 7}, {2, 3, 2},
                     {2, 4, 9}, {3, 4, 3}, {3, 5, 8}, {4, 5, 1}};
    for (int k = 0; k < 9; k++) {
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
    }

    int longe = 1;
    for (int v = 1; v < V; v++) {
        printf("%s: %d km  ", nomes[v], dist[v]);
        imprimir_rota(anterior, v);
        printf("\n");
        if (dist[v] > dist[longe]) longe = v;
    }
    printf("Mais longe: %s (%d km)\n", nomes[longe], dist[longe]);
    return 0;
}
