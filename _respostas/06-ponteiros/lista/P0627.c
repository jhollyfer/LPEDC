// Lista · Módulo 06 · Ponteiros
// Exercício P0627 · ★★★ · Multiplicar matrizes guardadas em fila

#include <stdio.h>
#include <stdbool.h>

void multiplicar(const int *a, const int *b, int *c, int l, int m, int n) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            int soma = 0;
            for (int k = 0; k < m; k++) {
                soma += a[i * m + k] * b[k * n + j];
            }
            c[i * n + j] = soma;
        }
    }
}

void mostrar(const int *v, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d", v[i * c + j]);
        }
        printf("\n");
    }
}

bool identidade(const int *v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i * n + j] != (i == j)) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int a[2 * 3] = {1, 2, 3,
                    4, 5, 6};
    int b[3 * 4] = {2, 0, 1, 3,
                    1, 4, 0, 2,
                    0, 1, 5, 1};
    int c[2 * 4];
    int id[3 * 3];
    int ai[2 * 3];

    multiplicar(a, b, c, 2, 3, 4);
    printf("a x b (2x4):\n");
    mostrar(c, 2, 4);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            id[i * 3 + j] = (i == j);
        }
    }
    printf("id é identidade? %s\n", identidade(id, 3) ? "sim" : "não");
    multiplicar(a, id, ai, 2, 3, 3);
    bool igual = true;
    for (int k = 0; k < 6; k++) {
        if (ai[k] != a[k]) {
            igual = false;
        }
    }
    printf("a x I == a? %s\n", igual ? "sim" : "não");
    return 0;
}
