// Lista · Módulo 07 · Memória dinâmica
// Exercício P0704 · ★☆☆ · A identidade do tamanho que pedirem

#include <stdio.h>
#include <stdlib.h>

void liberar(int **m, int n) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int **identidade(int n) {
    int **m = malloc(n * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        m[i] = calloc(n, sizeof *m[i]); // linha já zerada
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
        m[i][i] = 1;
    }
    return m;
}

void mostrar(int **m, int n) {
    printf("Identidade %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%s", m[i][j], j < n - 1 ? " " : "\n");
        }
    }
}

int main(void) {
    int tamanhos[2] = {2, 4};

    for (int k = 0; k < 2; k++) {
        int **m = identidade(tamanhos[k]);
        if (m == NULL) {
            return 1;
        }
        mostrar(m, tamanhos[k]);
        liberar(m, tamanhos[k]);
    }
    return 0;
}
