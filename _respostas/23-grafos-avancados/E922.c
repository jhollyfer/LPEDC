// 0154 · Bellman-Ford: pesos negativos
// Exercício E922 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

const char *salas[V] = {"Início", "Floresta", "Caverna", "Castelo", "Saída"};
int custo[V][V]; // créditos para passar de uma sala a outra; 0 = sem portal

void dijkstra(int dist[]) {
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (custo[u][v] && !fixo[v] && dist[u] + custo[u][v] < dist[v]) dist[v] = dist[u] + custo[u][v];
    }
}

void bellman_ford(int dist[]) {
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;
    for (int rodada = 1; rodada <= V - 1; rodada++)
        for (int u = 0; u < V; u++) // as arestas saem da própria matriz
            for (int v = 0; v < V; v++)
                if (custo[u][v] && dist[u] != INFINITO && dist[u] + custo[u][v] < dist[v])
                    dist[v] = dist[u] + custo[u][v];
}

int main(void) {
    int portais[][3] = {{0, 1, 2}, {0, 2, 5}, {2, 1, -4}, {1, 3, 6}, {3, 4, 1}, {2, 3, 9}};
    for (int k = 0; k < 6; k++) custo[portais[k][0]][portais[k][1]] = portais[k][2];

    int d[V], b[V];
    dijkstra(d);
    bellman_ford(b);
    for (int v = 1; v < V; v++)
        printf("%s: Dijkstra %d, Bellman-Ford %d%s\n", salas[v], d[v], b[v],
               d[v] != b[v] ? " (Dijkstra errou)" : "");
    return 0;
}
