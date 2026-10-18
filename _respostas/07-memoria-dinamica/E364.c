// 0061 · Matriz dinâmica
// Exercício E364 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 6;
    int **p = malloc(n * sizeof *p);
    if (p == NULL) {
        return 1;
    }
    int guardados = 0;
    for (int i = 0; i < n; i++) {
        p[i] = malloc((i + 1) * sizeof *p[i]); // a linha i tem i + 1 números
        if (p[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(p[k]);
            }
            free(p);
            return 1;
        }
        guardados += i + 1;
        p[i][0] = 1;
        p[i][i] = 1;
        for (int j = 1; j < i; j++) {
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf(j == 0 ? "%d" : " %d", p[i][j]);
        }
        printf("\n");
    }
    printf("Elementos guardados: %d\n", guardados);
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
    return 0;
}
// Saída:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// Elementos guardados: 21
