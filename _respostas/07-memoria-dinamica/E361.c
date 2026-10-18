// 0061 · Matriz dinâmica
// Exercício E361 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Tamanho: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    int **t = malloc(n * sizeof *t);
    if (t == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        t[i] = malloc(n * sizeof *t[i]);
        if (t[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(t[k]);
            }
            free(t);
            return 1;
        }
        for (int j = 0; j < n; j++) {
            t[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", t[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);
    return 0;
}
// Exemplo de uso:
// Tamanho: 4
//    1   2   3   4
//    2   4   6   8
//    3   6   9  12
//    4   8  12  16
