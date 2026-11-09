// 0184 · Pontes e articulações
// Exercício E1104 · ★★★

#include <stdio.h>

#define V 7
#define E 9

const char *bairros[V] = {"Centro", "Aleixo", "Adrianópolis", "Flores", "Cidade Nova", "Tarumã", "Ponta Negra"};
// lista de cabos: o último é o cabo reserva, paralelo a Tarumã - Ponta Negra
int cabo[E][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}, {5, 6}};
int tin[V], low[V], relogio = 0;

void dfs(int u, int cabo_pai) { // cabo_pai: índice do cabo da chegada
    tin[u] = low[u] = ++relogio;
    for (int k = 0; k < E; k++) {
        if (cabo[k][0] != u && cabo[k][1] != u) continue;
        int v = cabo[k][0] == u ? cabo[k][1] : cabo[k][0]; // a outra ponta
        if (k == cabo_pai) continue; // pula só o cabo de chegada, não o reserva
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, k);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) printf("Ponte: %s - %s\n", bairros[u], bairros[v]);
    }
}

int main(void) {
    dfs(0, -1);
    return 0;
}
