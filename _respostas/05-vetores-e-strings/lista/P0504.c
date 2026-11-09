// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0504 · ★☆☆ · O estoque das duas lojas

#include <stdio.h>

#define L 2
#define C 3

void mostrar(const char titulo[], int m[L][C]) {
    printf("%s\n", titulo);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int centro[L][C] = {{12, 20, 8}, {5, 9, 14}};
    int bairro[L][C] = {{7, 3, 10}, {11, 6, 2}};
    int total[L][C];

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            total[i][j] = centro[i][j] + bairro[i][j];
        }
    }

    mostrar("Centro:", centro);
    mostrar("Bairro:", bairro);
    mostrar("Total:", total);
    return 0;
}
