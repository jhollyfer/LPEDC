// Lista · Módulo 07 · Memória dinâmica
// Exercício P0708 · ★☆☆ · A transposta numa matriz nova

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

int **transposta(int **m, int l, int c) {
    int **t = criar(c, l);
    if (t == NULL) {
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = m[i][j];
        }
    }
    return t;
}

void mostrar(const char *titulo, int **m, int l, int c) {
    printf("%s (%dx%d):\n", titulo, l, c);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d%s", m[i][j], j < c - 1 ? " " : "\n");
        }
    }
}

int main(void) {
    int dados[2][3] = {{2, 5, 1}, {4, 0, 3}};
    int **m = criar(2, 3);
    if (m == NULL) {
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = dados[i][j];
        }
    }

    int **t = transposta(m, 2, 3);
    if (t == NULL) {
        liberar(m, 2);
        return 1;
    }
    mostrar("Original", m, 2, 3);
    mostrar("Transposta", t, 3, 2);
    liberar(m, 2);
    liberar(t, 3);
    return 0;
}
