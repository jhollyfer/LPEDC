// 0112 · Dijkstra: caminho mínimo
// Exercício E672 · ★★★

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 4
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Base", "A", "B", "C"};
    int custo[V][V] = {0};
    int trechos[][3] = {{0, 1, 5}, {0, 2, 6}, {2, 1, -3}, {1, 3, 1}};
    for (int k = 0; k < 4; k++) custo[trechos[k][0]][trechos[k][1]] = trechos[k][2];

    int dist[V];
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
            if (custo[u][v] && !fixo[v] && dist[u] + custo[u][v] < dist[v])
                dist[v] = dist[u] + custo[u][v];
    }

    for (int v = 1; v < V; v++) printf("%s: R$ %d\n", nomes[v], dist[v]);

    // conferência: num resultado certo, nenhuma aresta consegue encurtar mais nada
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (custo[u][v] && dist[u] != INFINITO && dist[u] + custo[u][v] < dist[v])
                printf("Ainda encurta: %s -> %s (%d + %d = %d < %d)\n", nomes[u], nomes[v], dist[u],
                       custo[u][v], dist[u] + custo[u][v], dist[v]);

    // Bellman-Ford: relaxa TODAS as arestas, V - 1 vezes, sem fixar ninguém
    int certo[V];
    for (int v = 0; v < V; v++) certo[v] = INFINITO;
    certo[0] = 0;
    for (int volta = 0; volta < V - 1; volta++)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                if (custo[u][v] && certo[u] != INFINITO && certo[u] + custo[u][v] < certo[v])
                    certo[v] = certo[u] + custo[u][v];

    printf("Com Bellman-Ford:\n");
    for (int v = 1; v < V; v++) printf("%s: R$ %d\n", nomes[v], certo[v]);
    return 0;
}
