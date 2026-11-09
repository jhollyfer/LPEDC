// Lista · Módulo 16 · Grafos
// Exercício P1616 · ★★☆ · Conserte o Dijkstra das balsas

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INF 1000000

const char *nomes[V] = {"Manaus", "Manacapuru", "Itacoatiara", "Parintins", "Coari", "Tefe"};
int peso[V][V];

int main(void) {
    int trechos[][3] = {{0, 1, 3}, {0, 2, 6}, {2, 3, 10}, {0, 3, 18}, {1, 4, 20}, {4, 5, 12}, {0, 4, 30}};
    for (int k = 0; k < 7; k++) peso[trechos[k][0]][trechos[k][1]] = peso[trechos[k][1]][trechos[k][0]] = trechos[k][2];

    int dist[V];
    bool fechado[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int rodada = 0; rodada < V; rodada++) {
        int u = -1;
        for (int v = 0; v < V; v++) // erro 1: só os vértices ainda abertos concorrem
            if (!fechado[v] && (u == -1 || dist[v] < dist[u])) u = v;
        fechado[u] = true;
        for (int v = 0; v < V; v++) // erro 2: peso 0 é "sem aresta", não "custo 0"
            if (peso[u][v] && !fechado[v] && dist[u] + peso[u][v] < dist[v]) dist[v] = dist[u] + peso[u][v];
    }
    for (int v = 1; v < V; v++) printf("%-11s %2d h\n", nomes[v], dist[v]);
    return 0;
}
