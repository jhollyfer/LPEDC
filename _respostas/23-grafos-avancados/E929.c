// 0155 · Floyd-Warshall: todos os pares
// Exercício E929 · ★★★

#include <stdio.h>

#define V 5
#define INFINITO 1000000000

int main(void) {
    const char *pontos[V] = {"Escola", "Parque", "Museu", "Praça", "Estação"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int ciclovias[][3] = {{0, 3, 2}, {3, 1, 3}, {1, 4, 2}, {4, 2, 1}, {0, 2, 15}, {2, 0, 4}, {0, 1, 9}};
    for (int c = 0; c < 7; c++) d[ciclovias[c][0]][ciclovias[c][1]] = ciclovias[c][2];

    // o bug: o k estava no laço de dentro. Ele é a rodada e tem que ficar por fora
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

    for (int i = 0; i < V; i++) {
        printf("%d. ", i);
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INFINITO) printf("%4s", "-");
            else printf("%4d", d[i][j]);
        }
        printf("   (%s)\n", pontos[i]);
    }
    return 0;
}
