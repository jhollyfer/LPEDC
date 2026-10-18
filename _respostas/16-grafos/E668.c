// 0112 · Dijkstra: caminho mínimo
// Exercício E668 · ★☆☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int tempo[V][V]; // minutos; 0 = sem trilho direto

int main(void) {
    const char *nomes[V] = {"Sé", "Luz", "República", "Paulista", "Pinheiros"};
    int trilhos[][3] = {{0, 1, 3}, {0, 2, 4}, {1, 2, 2}, {2, 3, 6}, {0, 3, 11}, {3, 4, 7}, {2, 4, 15}};
    for (int k = 0; k < 7; k++) {
        tempo[trilhos[k][0]][trilhos[k][1]] = trilhos[k][2];
        tempo[trilhos[k][1]][trilhos[k][0]] = trilhos[k][2];
    }

    int dist[V];
    bool fixo[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        fixo[v] = false;
    }
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++) {
            if (tempo[u][v] && !fixo[v] && dist[u] + tempo[u][v] < dist[v])
                dist[v] = dist[u] + tempo[u][v];
        }
    }

    for (int v = 0; v < V; v++) {
        if (dist[v] == INFINITO) printf("%s: inalcançável\n", nomes[v]);
        else printf("%s: %d min\n", nomes[v], dist[v]);
    }
    return 0;
}
