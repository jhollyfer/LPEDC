// 0113 · Juntando tudo: a central de entregas
// Exercício E675 · ★★☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INFINITO INT_MAX

const char *nomes[V] = {"CD", "Centro", "Feira", "Porto", "Morro", "Vila"};
int km[V][V];

void dijkstra(int origem, int dist[]) {
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[origem] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (km[u][v] && !fixo[v] && dist[u] + km[u][v] < dist[v]) dist[v] = dist[u] + km[u][v];
    }
}

int main(void) {
    int estradas[][3] = {{0, 1, 4}, {0, 2, 2}, {2, 1, 1}, {1, 3, 7}, {2, 4, 3}, {4, 3, 2}, {3, 5, 3}, {1, 5, 12}};
    for (int k = 0; k < 8; k++) {
        km[estradas[k][0]][estradas[k][1]] = estradas[k][2];
        km[estradas[k][1]][estradas[k][0]] = estradas[k][2];
    }

    int melhor = -1, melhor_pior = INFINITO;
    for (int s = 0; s < V; s++) {
        int dist[V], pior = 0, quem = s;
        dijkstra(s, dist);
        for (int v = 0; v < V; v++)
            if (dist[v] > pior) {
                pior = dist[v];
                quem = v;
            }
        printf("%-6s pior caso: %2d km (até %s)\n", nomes[s], pior, nomes[quem]);
        if (pior < melhor_pior) {
            melhor_pior = pior;
            melhor = s;
        }
    }
    printf("Melhor lugar para o hospital: %s (ninguém a mais de %d km)\n", nomes[melhor], melhor_pior);
    return 0;
}
