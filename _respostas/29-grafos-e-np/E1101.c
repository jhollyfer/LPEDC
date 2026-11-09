// 0184 · Pontes e articulações
// Exercício E1101 · ★★☆

#include <stdio.h>

#define V 7

const char *bairros[V] = {"Centro", "Aleixo", "Adrianópolis", "Flores", "Cidade Nova", "Tarumã", "Ponta Negra"};
int fibra[V][V];
int tin[V], low[V], relogio = 0;

// devolve quantos vértices tem a subárvore de u
int dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    int tamanho = 1;
    for (int v = 0; v < V; v++) {
        if (!fibra[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        int sub = dfs(v, u);
        tamanho += sub;
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u])
            printf("Cortar %s - %s isola %d bairro(s)\n", bairros[u], bairros[v], sub);
    }
    return tamanho;
}

int main(void) {
    int cabos[][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    for (int k = 0; k < 8; k++) fibra[cabos[k][0]][cabos[k][1]] = fibra[cabos[k][1]][cabos[k][0]] = 1;
    printf("Bairros alcançados: %d\n", dfs(0, -1));
    return 0;
}
