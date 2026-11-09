// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2310 · ★☆☆ · Quem recebe o recado

#include <stdio.h>

#define V 5

const char *pessoas[V] = {"Ana", "Bia", "Caio", "Davi", "Edu"};

int main(void) {
    int alcanca[V][V] = {0}; // alcanca[i][j] = 1: o recado de i chega em j
    int repasses[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {4, 3}};
    for (int k = 0; k < 5; k++) alcanca[repasses[k][0]][repasses[k][1]] = 1;

    // Warshall: libera um intermediário k por vez
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (alcanca[i][k] && alcanca[k][j]) alcanca[i][j] = 1;

    printf("      Ana Bia Caio Davi Edu\n");
    for (int i = 0; i < V; i++) {
        int quantos = 0;
        printf("%-5s", pessoas[i]);
        for (int j = 0; j < V; j++) {
            printf(" %*d", j == 2 || j == 3 ? 4 : 3, alcanca[i][j]);
            if (j != i) quantos += alcanca[i][j];
        }
        printf("   chega em %d\n", quantos);
    }
    return 0;
}
