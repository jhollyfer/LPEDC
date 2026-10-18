// 0155 · Floyd-Warshall: todos os pares
// Exercício E925 · ★☆☆

#include <stdio.h>

#define V 4
#define INFINITO 1000000000

int main(void) {
    const char *galpoes[V] = {"Milho", "Leite", "Frutas", "Mel"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int estradas[][3] = {{0, 1, 8}, {1, 2, 3}, {2, 0, 4}, {0, 3, 15}, {2, 3, 5}, {3, 1, 2}};
    for (int e = 0; e < 6; e++) d[estradas[e][0]][estradas[e][1]] = estradas[e][2];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j]; // INFINITO folgado: a soma não estoura

    for (int i = 0; i < V; i++) {
        printf("%-7s", galpoes[i]);
        for (int j = 0; j < V; j++) printf("%4d", d[i][j]);
        printf("\n");
    }
    return 0;
}
