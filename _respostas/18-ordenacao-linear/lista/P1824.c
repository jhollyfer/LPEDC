// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1824 · ★★★ · Por dentro da análise do bucket sort

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

typedef struct No {
    double x;
    struct No *prox;
} No;

unsigned semente = 2026;
long comparacoes;

unsigned sorteia(void) { // 32 bits pseudoaleatórios
    semente ^= semente << 13;
    semente ^= semente >> 17;
    semente ^= semente << 5;
    return semente;
}

void insere_ordenado(No **p, double x) {
    while (*p) {
        comparacoes++;
        if ((*p)->x >= x) break;
        p = &(*p)->prox;
    }
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->x = x;
    novo->prox = *p;
    *p = novo;
}

int main(void) {
    static double v[N];
    static No *balde[N];
    static int ocup[N];
    for (int i = 0; i < N; i++) v[i] = sorteia() / 4294967296.0;

    for (int i = 0; i < N; i++) {
        int b = (int)(v[i] * N);
        insere_ordenado(&balde[b], v[i]);
        ocup[b]++;
    }
    int k = 0;
    for (int b = 0; b < N; b++)
        while (balde[b]) {
            No *p = balde[b];
            v[k++] = p->x;
            balde[b] = p->prox;
            free(p);
        }

    int hist[16] = {0};
    long soma2 = 0, pior = 0;
    for (int b = 0; b < N; b++) {
        hist[ocup[b] < 15 ? ocup[b] : 15]++;
        soma2 += (long)ocup[b] * ocup[b];
        pior += (long)ocup[b] * (ocup[b] - 1) / 2;
    }
    printf("itens  baldes  esperado\n");
    double fat = 1;
    for (int j = 0; j < 16; j++) {
        if (j > 0) fat *= j;
        if (hist[j] == 0 && j > 3) break;
        printf("%5d %7d %9.0f\n", j, hist[j], N * exp(-1.0) / fat);
    }
    printf("Soma dos n_i²: %ld (esperado n(2 - 1/n) = %d)\n", soma2, 2 * N - 1);
    printf("Comparações: %ld (pior caso nos baldes: %ld; n = %d)\n", comparacoes, pior, N);
    int ok = 1;
    for (int i = 1; i < N; i++)
        if (v[i - 1] > v[i]) ok = 0;
    printf("Ordenado: %s\n", ok ? "sim" : "não");
    return 0;
}
