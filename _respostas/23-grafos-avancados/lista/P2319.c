// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2319 · ★★☆ · A cerca que fecha o curral

#include <stdio.h>

#define V 7

const char *mouroes[V] = {"M0", "M1", "M2", "M3", "M4", "M5", "M6"};
int pai[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]); // compressão de caminho
    return pai[x];
}

int main(void) {
    for (int v = 0; v < V; v++) pai[v] = v;
    // as cercas, na ordem em que o vaqueiro estica o arame
    int cercas[][2] = {{0, 1}, {1, 2}, {3, 4}, {2, 3}, {4, 0}, {5, 6}, {2, 5}, {6, 1}, {3, 0}};
    int currais = 0;
    for (int k = 0; k < 9; k++) {
        int a = cercas[k][0], b = cercas[k][1];
        int ra = acha(a), rb = acha(b);
        if (ra == rb) {
            currais++;
            printf("cerca %d (%s-%s): fecha o curral %d\n", k + 1, mouroes[a], mouroes[b], currais);
        } else {
            pai[ra] = rb;
            printf("cerca %d (%s-%s): só estende o arame\n", k + 1, mouroes[a], mouroes[b]);
        }
    }
    printf("Currais fechados: %d\n", currais);
    return 0;
}
