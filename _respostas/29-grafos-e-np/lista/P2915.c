// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2915 · ★★☆ · A rede é robusta?

#include <stdbool.h>
#include <stdio.h>

#define MAXV 8

int g[MAXV][MAXV], tin[MAXV], low[MAXV], relogio, pontes, n;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < n; v++) {
        if (!g[u][v] || v == pai) continue;
        if (tin[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) pontes++;
    }
}

void avalia(const char *nome, int nv, int ne, int c[][2]) {
    n = nv, relogio = 0, pontes = 0;
    for (int u = 0; u < n; u++) {
        tin[u] = 0;
        for (int v = 0; v < n; v++) g[u][v] = 0;
    }
    for (int k = 0; k < ne; k++) g[c[k][0]][c[k][1]] = g[c[k][1]][c[k][0]] = 1;
    int comp = 0;
    for (int u = 0; u < n; u++)
        if (!tin[u]) comp++, dfs(u, -1);
    printf("%s: %d componente(s), %d ponte(s): %s\n", nome, comp, pontes,
           comp == 1 && pontes == 0 ? "robusta" : "frágil");
}

int main(void) {
    int r1[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
    int r2[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3}};
    int r3[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {0, 3}};
    avalia("R1", 6, 6, r1);
    avalia("R2", 6, 7, r2);
    avalia("R3", 6, 7, r3);
    return 0;
}
