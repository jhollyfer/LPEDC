// Lista · Módulo 16 · Grafos
// Exercício P1615 · ★★☆ · Dijkstra do centro de distribuição, com a rota

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define V 7
#define INF INT_MAX

const char *nomes[V] = {"CD", "Japiim", "Coroado", "Aleixo", "Centro", "Flores", "Ponta Negra"};
int peso[V][V];

void dijkstra(int s, int dist[], int pi[]) {
    bool fechado[V] = {false};
    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        pi[v] = -1;
    }
    dist[s] = 0;
    for (int rodada = 0; rodada < V; rodada++) {
        int u = -1;
        for (int v = 0; v < V; v++) // o aberto de menor dist: O(V) por rodada
            if (!fechado[v] && dist[v] != INF && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break; // o resto é inalcançável
        fechado[u] = true;
        for (int v = 0; v < V; v++)
            if (peso[u][v] && !fechado[v] && dist[u] + peso[u][v] < dist[v]) {
                dist[v] = dist[u] + peso[u][v];
                pi[v] = u;
            }
    }
}

void rota(const int pi[], int v) {
    if (pi[v] != -1) {
        rota(pi, pi[v]); // primeiro o caminho até o predecessor
        printf(" -> ");
    }
    printf("%s", nomes[v]);
}

int main(void) {
    int ruas[][3] = {{0, 1, 4}, {0, 2, 7}, {1, 2, 2}, {1, 4, 9}, {2, 3, 3}, {3, 4, 5},
                     {3, 5, 6}, {4, 6, 14}, {5, 6, 10}, {4, 5, 4}};
    for (int k = 0; k < 10; k++) peso[ruas[k][0]][ruas[k][1]] = peso[ruas[k][1]][ruas[k][0]] = ruas[k][2];

    int dist[V], pi[V];
    dijkstra(0, dist, pi);
    for (int v = 1; v < V; v++) {
        printf("%-12s %2d km: ", nomes[v], dist[v]);
        rota(pi, v);
        printf("\n");
    }
    return 0;
}
