// 0132 · Inversões e subvetor de soma máxima
// Exercício E792 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define N 100000

long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    long long esq = conta(v, w, p, q);
    long long dir = conta(v, w, q, r);
    return esq + dir + intercala(v, w, p, q, r);
}

int main(void) {
    int *v = malloc(N * sizeof *v);
    int *w = malloc(N * sizeof *w);
    if (v == NULL || w == NULL) {
        free(v);
        free(w);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        v[i] = N - i; // 100000, 99999, ..., 1: o pior caso
    }
    long long total = conta(v, w, 0, N);
    printf("Inversões: %lld\n", total);
    printf("Fórmula:   %lld\n", (long long)N * (N - 1) / 2);
    free(v);
    free(w);
    return 0;
}
