// 0039 · Matrizes
// Exercício E231 · ★★☆

#include <stdio.h>

#define DIAS 2
#define TURNOS 3

int main(void) {
    int m[DIAS][TURNOS] = {
        {40, 25, 60},
        {35, 30, 55},
    };
    int t[TURNOS][DIAS];

    for (int l = 0; l < DIAS; l++) {
        for (int c = 0; c < TURNOS; c++) {
            t[c][l] = m[l][c];
        }
    }

    printf("Original (2x3):\n");
    for (int l = 0; l < DIAS; l++) {
        for (int c = 0; c < TURNOS; c++) {
            printf(c == 0 ? "%d" : " %d", m[l][c]);
        }
        printf("\n");
    }

    printf("Transposta (3x2):\n");
    for (int l = 0; l < TURNOS; l++) {
        for (int c = 0; c < DIAS; c++) {
            printf(c == 0 ? "%d" : " %d", t[l][c]);
        }
        printf("\n");
    }
    return 0;
}
