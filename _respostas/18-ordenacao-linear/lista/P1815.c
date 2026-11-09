// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1815 · ★★☆ · Bucket sort fora de [0, 1): as temperaturas de Manaus

#include <stdio.h>
#include <stdlib.h>

#define N 12

typedef struct No {
    double x;
    struct No *prox;
} No;

void insere_ordenado(No **p, double x) {
    while (*p && (*p)->x < x) p = &(*p)->prox;
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->x = x;
    novo->prox = *p;
    *p = novo;
}

int main(void) {
    double temp[N] = {31.2, 33.8, 29.5, 36.4, 22.9, 34.1, 38.1, 30.7, 27.3, 35.0, 37.6, 32.4};
    No *balde[N] = {NULL};

    double min = temp[0], max = temp[0];
    for (int i = 1; i < N; i++) {
        if (temp[i] < min) min = temp[i];
        if (temp[i] > max) max = temp[i];
    }
    for (int i = 0; i < N; i++) {
        int b = max > min ? (int)((temp[i] - min) / (max - min) * N) : 0;
        if (b >= N) b = N - 1; // o máximo daria b == N
        insere_ordenado(&balde[b], temp[i]);
    }

    int k = 0;
    for (int b = 0; b < N; b++) {
        if (balde[b] == NULL) continue;
        printf("balde %2d:", b);
        while (balde[b]) {
            No *p = balde[b];
            printf(" %.1f", p->x);
            temp[k++] = p->x;
            balde[b] = p->prox;
            free(p);
        }
        printf("\n");
    }
    printf("ordenado:");
    for (int i = 0; i < N; i++) printf(" %.1f", temp[i]);
    printf("\n");
    return 0;
}
