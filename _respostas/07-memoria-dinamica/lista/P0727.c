// Lista · Módulo 07 · Memória dinâmica
// Exercício P0727 · ★★★ · O determinante por Laplace

#include <stdio.h>
#include <stdlib.h>

int menores = 0; // quantas matrizes menores foram alocadas

void liberar(double **m, int n) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

double **criar(int n) {
    double **m = malloc(n * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        m[i] = malloc(n * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
    }
    return m;
}

double det(double **m, int n) {
    if (n == 1) {
        return m[0][0];
    }
    double total = 0;
    for (int j = 0; j < n; j++) {
        if (m[0][j] == 0) {
            continue; // termo nulo: nem monta o menor
        }
        double **sub = criar(n - 1);
        if (sub == NULL) {
            return 0;
        }
        menores++;
        for (int i = 1; i < n; i++) {
            int d = 0;
            for (int k = 0; k < n; k++) {
                if (k != j) {
                    sub[i - 1][d++] = m[i][k];
                }
            }
        }
        double sinal = (j % 2 == 0) ? 1 : -1;
        total += sinal * m[0][j] * det(sub, n - 1);
        liberar(sub, n - 1);
    }
    return total;
}

double **de_vetor(const double *v, int n) {
    double **m = criar(n);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = v[i * n + j];
        }
    }
    return m;
}

void calcular(const char *nome, const double *v, int n) {
    double **m = de_vetor(v, n);
    if (m == NULL) {
        return;
    }
    menores = 0;
    double d = det(m, n);
    printf("det %s (%dx%d) = %.0f, com %d menores alocados\n", nome, n, n, d, menores);
    liberar(m, n);
}

int main(void) {
    double a[9] = {2, -1, 0,
                   1, 3, 2,
                   0, 1, 4};
    double b[16] = {1, 0, 2, -1,
                    3, 0, 0, 5,
                    2, 1, 4, -3,
                    1, 0, 5, 0};
    double id[16] = {1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1};

    calcular("A", a, 3);
    calcular("B", b, 4);
    calcular("I", id, 4);
    return 0;
}
