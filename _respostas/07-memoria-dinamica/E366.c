// 0061 · Matriz dinâmica
// Exercício E366 · ★★★

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

int **multiplicar(int **a, int la, int ca, int **b, int lb, int cb) {
    if (ca != lb) {
        return NULL;
    }
    int **c = criar_matriz(la, cb);
    if (c == NULL) {
        return NULL;
    }
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            c[i][j] = 0;
            for (int k = 0; k < ca; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(void) {
    int fa[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int fb[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int **a = criar_matriz(2, 3);
    int **b = criar_matriz(3, 2);
    if (a == NULL || b == NULL) {
        liberar_matriz(a, 2);
        liberar_matriz(b, 3);
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = fa[i][j];
            b[j][i] = fb[j][i];
        }
    }

    int **c = multiplicar(a, 2, 3, b, 3, 2);
    if (c != NULL) {
        for (int i = 0; i < 2; i++) {
            printf("%d %d\n", c[i][0], c[i][1]);
        }
        liberar_matriz(c, 2);
    }

    int **aa = multiplicar(a, 2, 3, a, 2, 3);
    if (aa == NULL) {
        printf("A * A: dimensões incompatíveis\n");
    }

    liberar_matriz(a, 2);
    liberar_matriz(b, 3);
    return 0;
}
// Saída:
// 58 64
// 139 154
// A * A: dimensões incompatíveis
