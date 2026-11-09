// Lista · Módulo 07 · Memória dinâmica
// Exercício P0710 · ★☆☆ · Somar duas matrizes dinâmicas

#include <stdio.h>
#include <stdlib.h>

void liberar(int **m, int l) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

int **criar(int l, int c) {
    int **m = malloc(l * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        m[i] = malloc(c * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
    }
    return m;
}

int **somar(int **a, int **b, int l, int c) {
    int **s = criar(l, c);
    if (s == NULL) {
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
    return s;
}

int main(void) {
    int l = 3, c = 2;
    int va[6] = {14, 9, 6, 11, 20, 17};
    int vb[6] = {8, 12, 3, 5, 15, 22};
    int **a = criar(l, c);
    int **b = criar(l, c);
    if (a == NULL || b == NULL) {
        liberar(a, l);
        liberar(b, l);
        return 1;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = va[i * c + j];
            b[i][j] = vb[i * c + j];
        }
    }

    int **s = somar(a, b, l, c);
    if (s != NULL) {
        printf("Total das filiais:\n");
        for (int i = 0; i < l; i++) {
            printf("Modelo %d: %3d %3d\n", i + 1, s[i][0], s[i][1]);
        }
    }
    liberar(a, l);
    liberar(b, l);
    liberar(s, l);
    return 0;
}
