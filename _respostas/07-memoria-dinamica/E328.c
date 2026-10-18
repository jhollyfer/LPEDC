// 0055 · calloc e realloc
// Exercício E328 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int recebidas[] = {12, -1, 15, 14, -1, -1, 13, 16, -1, 11};
    int n = 10;
    int *v = malloc(n * sizeof *v);
    if (v == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        v[i] = recebidas[i];
    }

    int j = 0; // onde escrever a próxima válida
    for (int i = 0; i < n; i++) {
        if (v[i] != -1) {
            v[j] = v[i];
            j++;
        }
    }

    int *menor = realloc(v, j * sizeof *v);
    if (menor == NULL) {
        free(v);
        return 1;
    }
    v = menor;

    printf("%d leituras válidas:", j);
    for (int i = 0; i < j; i++) {
        printf(" %d", v[i]);
    }
    printf("\nBloco encolheu de %zu para %zu bytes\n", n * sizeof *v, j * sizeof *v);
    free(v);
    return 0;
}
// Saída:
// 6 leituras válidas: 12 15 14 13 16 11
// Bloco encolheu de 40 para 24 bytes
