// 0123 · Quickselect
// Exercício E737 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define N 10001

static long separacoes;
static unsigned semente = 2025;

int sorteia(int p, int r) {
    semente = semente * 1103515245u + 12345u;
    return p + (int) ((semente >> 16) % (unsigned) (r - p + 1));
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Lomuto: o pivô é SEMPRE o v[r]
int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    separacoes++;
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
        troca(&v[sorteia(p, r)], &v[r]);    // o sorteado vai para o fim
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

int main(void) {
    // números de matrícula 1 a 10001, já em ordem: a mediana é 5001
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
    int m = quickselect(v, N, N / 2);       // posição 5000: a do meio
    printf("mediana: %d (%ld separações)\n", m, separacoes);
    free(v);
    return 0;
}
