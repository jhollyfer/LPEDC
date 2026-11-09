// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2921 · ★★★ · A raiz que não é articulação

#include <stdbool.h>
#include <stdio.h>

#define V 7

int g[V][V], tin[V], low[V], relogio = 0;
bool corte[V];

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    int filhos = 0;
    for (int v = 0; v < V; v++) {
        if (!g[u][v] || v == pai) continue;
        if (tin[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        filhos++;
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (pai != -1 && low[v] >= tin[u]) corte[u] = true; // fora a raiz
    }
    if (pai == -1 && filhos >= 2) corte[u] = true; // raiz: 2 ou mais filhos
}

int main(void) {
    int e[][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 1}, {4, 5}, {5, 6}};
    for (int k = 0; k < 8; k++) g[e[k][0]][e[k][1]] = g[e[k][1]][e[k][0]] = 1;
    dfs(0, -1);
    printf("Articulações:");
    for (int u = 0; u < V; u++)
        if (corte[u]) printf(" %d", u);
    printf("\n");
    return 0;
}
