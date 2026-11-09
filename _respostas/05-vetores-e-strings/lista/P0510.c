// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0510 · ★☆☆ · Quantos de cada número

#include <stdio.h>

#define MENOR 34
#define MAIOR 44

int main(void) {
    int vendidos[14] = {38, 40, 37, 42, 40, 39, 40, 35, 38, 41, 40, 44, 38, 37};
    int cont[MAIOR - MENOR + 1] = {0};

    for (int i = 0; i < 14; i++) {
        cont[vendidos[i] - MENOR]++; // o número vira índice
    }

    for (int k = 0; k <= MAIOR - MENOR; k++) {
        if (cont[k] == 0) {
            continue;
        }
        printf("%d: ", k + MENOR);
        for (int j = 0; j < cont[k]; j++) {
            printf("#");
        }
        printf(" (%d)\n", cont[k]);
    }
    return 0;
}
