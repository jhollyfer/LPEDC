// 0118 · Juntando tudo
// Exercício E707 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 200000

long comparacoes = 0;
int limiar = 1; // pedaços com menos que isso vão para o insertion

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

// insertion sort em v[p..r-1]
void insertion_trecho(int v[], int p, int r) {
    for (int i = p + 1; i < r; i++) {
        int x = v[i], j = i - 1;
        while (j >= p && menor(x, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void hibrido(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    if (r - p < limiar) {
        insertion_trecho(v, p, r);      // pedaço pequeno: sem recursão
        return;
    }
    int q = p + (r - p) / 2;
    hibrido(v, w, p, q);
    hibrido(v, w, q, r);
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = menor(v[j], v[i]) ? v[j++] : v[i++];
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    memcpy(v + p, w, (r - p) * sizeof *v);
}

int main(void) {
    int *original = malloc(N * sizeof *original), *v = malloc(N * sizeof *v), *w = malloc(N * sizeof *w);
    if (original == NULL || v == NULL || w == NULL) {
        return 1;
    }
    unsigned s = 11;
    for (int i = 0; i < N; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }
    int limiares[] = {1, 8, 16, 32, 64, 256};
    for (int t = 0; t < 6; t++) {
        limiar = limiares[t];
        memcpy(v, original, N * sizeof *v);
        comparacoes = 0;
        clock_t ini = clock();
        hibrido(v, w, 0, N);
        double ms = 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
        int ok = 1;
        for (int i = 1; i < N; i++) {
            if (v[i] < v[i - 1]) {
                ok = 0;
            }
        }
        printf("L = %3d: %8ld comparações, %6.1f ms%s\n", limiar, comparacoes, ms, ok ? "" : " ERRADO");
    }
    free(original);
    free(v);
    free(w);
    return 0;
}
