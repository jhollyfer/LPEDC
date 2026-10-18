// 0056 · Matriz dinâmica
// Exercício E333 · ★★☆

#include <stdio.h>
#include <stdlib.h>

void liberar_matriz(int **m, int linhas) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < linhas; i++) {
        free(m[i]);
    }
    free(m);
}

int **criar_matriz(int linhas, int colunas) {
    int **m = malloc(linhas * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        m[i] = malloc(colunas * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar_matriz(m, i);
            return NULL;
        }
    }
    return m;
}

int **transpor(int **m, int linhas, int colunas) {
    int **t = criar_matriz(colunas, linhas);
    if (t == NULL) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            t[j][i] = m[i][j];
        }
    }
    return t;
}

int main(void) {
    int horas[2][3] = {{2, 5, 1}, {3, 4, 0}};
    int **m = criar_matriz(2, 3);
    if (m == NULL) {
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = horas[i][j];
        }
    }
    int **t = transpor(m, 2, 3);
    if (t == NULL) {
        liberar_matriz(m, 2);
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        printf("%d %d\n", t[i][0], t[i][1]);
    }
    liberar_matriz(m, 2); // a original tem 2 linhas
    liberar_matriz(t, 3); // a transposta tem 3
    return 0;
}
// Saída:
// 2 3
// 5 4
// 1 0
