// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2914 · ★★☆ · Pontes com lista de adjacência

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 8
#define E 9

int *vizinho[V], grau[V], tin[V], low[V], relogio = 0;
bool corte[V];

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    int filhos = 0;
    for (int i = 0; i < grau[u]; i++) {
        int v = vizinho[u][i];
        if (v == pai) continue;
        if (tin[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        filhos++;
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) printf("Ponte: %d-%d\n", u, v);
        if (pai != -1 && low[v] >= tin[u]) corte[u] = true;
    }
    if (pai == -1 && filhos >= 2) corte[u] = true;
}

int main(void) {
    int c[E][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}, {6, 7}};
    for (int k = 0; k < E; k++) grau[c[k][0]]++, grau[c[k][1]]++;
    for (int u = 0; u < V; u++) {
        vizinho[u] = malloc(grau[u] * sizeof(int));
        if (vizinho[u] == NULL) return 1;
        grau[u] = 0; // volta a 0 para servir de posição de escrita
    }
    for (int k = 0; k < E; k++) {
        int a = c[k][0], b = c[k][1];
        vizinho[a][grau[a]++] = b;
        vizinho[b][grau[b]++] = a;
    }
    dfs(0, -1);
    printf("Articulações:");
    for (int u = 0; u < V; u++)
        if (corte[u]) printf(" %d", u);
    printf("\n");
    for (int u = 0; u < V; u++) free(vizinho[u]);
    return 0;
}
