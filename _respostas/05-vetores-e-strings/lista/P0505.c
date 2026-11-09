// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0505 · ★☆☆ · A grade de horários deitada

#include <stdio.h>

int main(void) {
    int aulas[3][4] = {{2, 4, 0, 3}, {1, 1, 5, 2}, {3, 0, 2, 4}};
    int t[4][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            t[j][i] = aulas[i][j]; // linha vira coluna
        }
    }

    printf("Por professor (3x4):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d", aulas[i][j]);
        }
        printf("\n");
    }
    printf("Por dia (4x3):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
