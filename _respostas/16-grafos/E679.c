// 0114 · Grafos
// Exercício E679 · ★☆☆

#include <stdio.h>

#define V 4

int main(void) {
    int adj[V][V] = {0};
    int voos[][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 3}};

    for (int k = 0; k < 4; k++) {
        adj[voos[k][0]][voos[k][1]] = 1;
        adj[voos[k][1]][voos[k][0]] = 1;
    }

    printf("     0 1 2 3\n");
    int arestas = 0;
    for (int i = 0; i < V; i++) {
        printf("  %d ", i);
        for (int j = 0; j < V; j++) {
            printf(" %d", adj[i][j]);
            if (j > i) arestas += adj[i][j]; // só acima da diagonal
        }
        printf("\n");
    }
    printf("Voos diretos: %d\n", arestas);
    return 0;
}
