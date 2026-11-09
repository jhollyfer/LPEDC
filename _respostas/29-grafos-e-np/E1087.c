// 0182 · Caminhos e ciclos
// Exercício E1087 · ★☆☆

#include <stdio.h>

#define V 6

const char *pontos[V] = {"Bosque", "Lago", "Mirante", "Ponte", "Quiosque", "Trilha"};
int ciclovia[V][V];

int main(void) {
    int trechos[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    int e = 7;
    for (int k = 0; k < e; k++) {
        ciclovia[trechos[k][0]][trechos[k][1]] = 1;
        ciclovia[trechos[k][1]][trechos[k][0]] = 1;
    }
    int soma = 0, impares = 0;
    for (int u = 0; u < V; u++) {
        int g = 0;
        for (int v = 0; v < V; v++) g += ciclovia[u][v];
        printf("%s: %d\n", pontos[u], g);
        soma += g;
        if (g % 2 != 0) impares++;
    }
    printf("Soma dos graus: %d (2 x %d trechos)\n", soma, e);
    printf("Pontos de grau ímpar: %d\n", impares);
    return 0;
}
