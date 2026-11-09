// 0184 · Pontes e articulações
// Exercício E1103 · ★★★

#include <stdio.h>

#define V 8

const char *subestacoes[V] = {"Usina", "Norte", "Sul", "Leste", "Oeste", "Porto", "Vila", "Serra"};
int linha[V][V];
int tin[V], low[V], relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!linha[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) printf("Linha crítica: %s - %s\n", subestacoes[u], subestacoes[v]);
    }
}

int main(void) {
    int linhas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}, {2, 5}, {5, 6}, {5, 7}};
    for (int k = 0; k < 9; k++) linha[linhas[k][0]][linhas[k][1]] = linha[linhas[k][1]][linhas[k][0]] = 1;
    dfs(0, -1);
    return 0;
}
