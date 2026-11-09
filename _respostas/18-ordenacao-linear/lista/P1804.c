// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1804 · ★☆☆ · Bucket sort da ocupação dos voos

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct No {
    double x;
    struct No *prox;
} No;

void insere_ordenado(No **p, double x) {
    while (*p && (*p)->x < x) p = &(*p)->prox; // acha onde x se encaixa
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->x = x;
    novo->prox = *p;
    *p = novo;
}

int main(void) {
    double ocup[N] = {0.87, 0.31, 0.79, 0.05, 0.84, 0.52, 0.99, 0.12, 0.88, 0.36};
    No *balde[N] = {NULL};

    for (int i = 0; i < N; i++) insere_ordenado(&balde[(int)(ocup[i] * N)], ocup[i]);

    int k = 0;
    for (int b = 0; b < N; b++) {
        if (balde[b] == NULL) continue;
        printf("balde %d:", b);
        while (balde[b]) { // mostra, copia para o vetor e libera
            No *p = balde[b];
            printf(" %.2f", p->x);
            ocup[k++] = p->x;
            balde[b] = p->prox;
            free(p);
        }
        printf("\n");
    }
    printf("ordenado:");
    for (int i = 0; i < N; i++) printf(" %.2f", ocup[i]);
    printf("\n");
    return 0;
}
