// 0184 · Pontes e articulações
// Exercício E1100 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *cidades[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airão", "Rio Preto da Eva", "Itacoatiara"};
int estrada[V][V];
int tin[V], low[V], relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!estrada[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v]; // aresta de volta
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v]; // o que o filho alcança, u alcança
        if (low[v] > tin[u]) printf("Ponte: %s - %s\n", cidades[u], cidades[v]);
    }
}

int main(void) {
    int rodovias[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {0, 4}, {4, 5}};
    for (int k = 0; k < 6; k++) estrada[rodovias[k][0]][rodovias[k][1]] = estrada[rodovias[k][1]][rodovias[k][0]] = 1;

    dfs(0, -1);
    for (int u = 0; u < V; u++) printf("%s: tin %d, low %d\n", cidades[u], tin[u], low[u]);
    return 0;
}
