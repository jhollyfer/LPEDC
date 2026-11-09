// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2327 · ★★★ · O Prim que virou Dijkstra

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF INT_MAX

const char *torres[V] = {"Central", "Morro", "Vila", "Usina", "Sítio"};
int km[V][V];

int main(void) {
    int cabos[][3] = {{0, 1, 5}, {1, 2, 2}, {0, 2, 6}, {2, 3, 3}, {1, 3, 7}, {3, 4, 1}, {0, 4, 9}};
    for (int k = 0; k < 7; k++) {
        km[cabos[k][0]][cabos[k][1]] = cabos[k][2];
        km[cabos[k][1]][cabos[k][0]] = cabos[k][2];
    }
    int chave[V], pai[V];
    bool dentro[V];
    for (int v = 0; v < V; v++) {
        chave[v] = INF;
        pai[v] = -1;
        dentro[v] = false;
    }
    chave[0] = 0;
    int total = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!dentro[v] && chave[v] != INF && (u == -1 || chave[v] < chave[u])) u = v;
        dentro[u] = true;
        if (pai[u] != -1) {
            printf("%s - %s: %d km\n", torres[pai[u]], torres[u], km[pai[u]][u]);
            total += km[pai[u]][u];
        }
        for (int v = 0; v < V; v++)
            if (km[u][v] && !dentro[v] && km[u][v] < chave[v]) { // o conserto: só o cabo, sem somar chave[u]
                chave[v] = km[u][v];
                pai[v] = u;
            }
    }
    printf("Total: %d km\n", total);
    return 0;
}
