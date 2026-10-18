// 0123 · Quickselect
// Exercício E736 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define N 50

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

// percentil pelo "posto mais próximo": o menor valor que deixa pelo menos
// pct% dos valores abaixo ou iguais. Posição = teto(pct * n / 100) - 1
int percentil(int v[], int n, int pct) {
    int k = (pct * n + 99) / 100 - 1;
    return quickselect(v, n, k);
}

int compara(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

int main(void) {
    int t[N]; // tempo de resposta do site, em milissegundos
    for (int i = 0; i < N; i++) {
        t[i] = 30 + (i * 37) % 50 * 4 + (i % 9 == 0 ? 600 : 0); // alguns picos
    }
    int pcts[] = {50, 90, 99};
    for (int i = 0; i < 3; i++) {
        printf("p%d: %d ms\n", pcts[i], percentil(t, N, pcts[i]));
    }

    qsort(t, N, sizeof(int), compara);
    printf("conferindo: %d, %d e %d\n", t[24], t[44], t[49]);
    return 0;
}
