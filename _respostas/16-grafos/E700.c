// 0117 · Dijkstra: caminho mínimo
// Exercício E700 · ★★☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Hospital", "Norte", "Sul", "Leste", "Oeste"};
    int rua[V][V] = {0};
    int ruas[][3] = {{1, 0, 9}, {1, 3, 2}, {3, 0, 4}, {3, 4, 1},
                     {2, 4, 3}, {2, 1, 1}, {4, 0, 5}, {0, 2, 1}};
    for (int k = 0; k < 8; k++) rua[ruas[k][0]][ruas[k][1]] = ruas[k][2];

    // grafo transposto: toda seta i -> j vira j -> i
    int inv[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) inv[j][i] = rua[i][j];

    int dist[V];
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0; // a partir do Hospital, no grafo invertido
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (inv[u][v] && !fixo[v] && dist[u] + inv[u][v] < dist[v]) dist[v] = dist[u] + inv[u][v];
    }

    for (int v = 1; v < V; v++) printf("%s: %d min\n", nomes[v], dist[v]);
    return 0;
}
