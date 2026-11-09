// Lista · Módulo 13 · Busca e ordenação
// Exercício P1318 · ★★☆ · O pior caso do quick sort, medido

#include <stdio.h>

int comparacoes, profundidade_max;

int particiona(int v[], int p, int r) {
    int pivo = v[r], i = p - 1;
    for (int j = p; j < r; j++) {
        comparacoes++;
        if (v[j] <= pivo) {
            i++;
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    int t = v[i + 1];
    v[i + 1] = v[r];
    v[r] = t;
    return i + 1;
}

void quick(int v[], int p, int r, int prof) {
    if (prof > profundidade_max) {
        profundidade_max = prof;
    }
    if (p < r) {
        int q = particiona(v, p, r);
        quick(v, p, q - 1, prof + 1);
        quick(v, q + 1, r, prof + 1);
    }
}

void testa(const char *nome, int v[], int n) {
    comparacoes = profundidade_max = 0;
    quick(v, 0, n - 1, 0);
    printf("%-10s comparações %2d, profundidade %d\n", nome, comparacoes, profundidade_max);
}

int main(void) {
    int crescente[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int misturado[] = {6, 3, 9, 1, 8, 2, 10, 5, 7, 4};

    testa("crescente", crescente, 10);
    testa("misturado", misturado, 10);
    printf("n(n-1)/2 = %d\n", 10 * 9 / 2);
    return 0;
}
