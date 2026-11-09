// Lista · Módulo 13 · Busca e ordenação
// Exercício P1323 · ★★★ · Mediana de três contra o vetor ordenado

#include <stdio.h>
#include <stdbool.h>

int comparacoes;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particiona(int v[], int p, int r) {
    int pivo = v[r], i = p - 1;
    for (int j = p; j < r; j++) {
        comparacoes++;
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[r]);
    return i + 1;
}

// leva para v[r] a mediana de v[p], v[m] e v[r]
void mediana_de_tres(int v[], int p, int r) {
    int m = p + (r - p) / 2;
    if (v[m] < v[p]) {
        troca(&v[m], &v[p]);
    }
    if (v[r] < v[p]) {
        troca(&v[r], &v[p]);
    }
    if (v[r] < v[m]) {
        troca(&v[r], &v[m]);
    }
    // agora v[p] <= v[m] <= v[r]: a mediana está em m
    troca(&v[m], &v[r]);
}

void quick(int v[], int p, int r, bool mediana) {
    if (p < r) {
        if (mediana && r - p >= 2) {
            mediana_de_tres(v, p, r);
        }
        int q = particiona(v, p, r);
        quick(v, p, q - 1, mediana);
        quick(v, q + 1, r, mediana);
    }
}

void testa(const char *nome, const int orig[], int n) {
    int a[16], b[16];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = orig[i];
    }
    comparacoes = 0;
    quick(a, 0, n - 1, false);
    int simples = comparacoes;
    comparacoes = 0;
    quick(b, 0, n - 1, true);
    printf("%-11s pivô no fim: %3d   mediana de três: %3d\n", nome, simples, comparacoes);
}

int main(void) {
    int crescente[15], decrescente[15];
    int misturado[15] = {8, 14, 3, 11, 1, 6, 15, 9, 2, 12, 5, 13, 7, 4, 10};
    for (int i = 0; i < 15; i++) {
        crescente[i] = i + 1;
        decrescente[i] = 15 - i;
    }

    testa("crescente", crescente, 15);
    testa("decrescente", decrescente, 15);
    testa("misturado", misturado, 15);
    return 0;
}
