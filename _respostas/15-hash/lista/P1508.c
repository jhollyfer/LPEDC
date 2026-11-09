// Lista · Módulo 15 · Tabelas hash
// Exercício P1508 · ★☆☆ · Quanto custa procurar na corrente

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int chave;
    struct No *prox;
} No;

void insere(No *t[], int k) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->chave = k;
    novo->prox = t[k % M];
    t[k % M] = novo;
}

// devolve 1 se achou; *comp conta as chaves comparadas
int busca(No *t[], int k, int *comp) {
    *comp = 0;
    for (No *p = t[k % M]; p != NULL; p = p->prox) {
        (*comp)++;
        if (p->chave == k) {
            return 1;
        }
    }
    return 0;
}

void libera(No *t[]) {
    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
}

int main(void) {
    No *t[M] = {NULL};
    int ra[] = {21, 6, 11, 33, 18, 40, 16, 3};
    for (int i = 0; i < 8; i++) {
        insere(t, ra[i]);
    }

    int procura[] = {21, 16, 33, 40, 26, 8};
    for (int i = 0; i < 6; i++) {
        int c;
        int achou = busca(t, procura[i], &c);
        printf("%d: %s (comparações: %d)\n", procura[i], achou ? "achou" : "não achou", c);
    }
    libera(t);
    return 0;
}
