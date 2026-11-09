// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2620 · ★★☆ · A tabela de distâncias pela metade

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

double *v;

long pos(long i, long j) {
    return i * N - i * (i + 1) / 2 + (j - i - 1);
}

double distancia(long i, long j) {
    if (i == j) {
        return 0.0;
    }
    if (i > j) {
        long t = i;
        i = j;
        j = t;
    }
    return v[pos(i, j)];
}

int main(void) {
    size_t tam = (size_t)N * (N - 1) / 2;
    v = malloc(tam * sizeof(double));
    if (v == NULL) {
        return 1;
    }
    for (long i = 0; i < N; i++) {
        for (long j = i + 1; j < N; j++) {
            v[pos(i, j)] = 2.5 * (i + j) + 1;
        }
    }
    int erros = 0;
    for (long i = 0; i < N; i++) {
        for (long j = 0; j < N; j++) {
            double esperado = (i == j) ? 0.0 : 2.5 * (i + j) + 1;
            if (fabs(distancia(i, j) - esperado) > 1e-9) {
                erros++;
            }
        }
    }
    printf("matriz: %zu bytes\n", (size_t)N * N * sizeof(double));
    printf("vetor:  %zu bytes\n", tam * sizeof(double));
    printf("pares conferidos: %d, erros: %d\n", N * N, erros);
    printf("distancia(7, 3) = %.1f\n", distancia(7, 3));
    free(v);
    return 0;
}
