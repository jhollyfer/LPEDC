// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2802 · ★☆☆ · A chave guardada na sentinela

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *ant, *prox;
} No;

typedef struct {
    No nil;
} Lista;

void insere_fim(Lista *L, int chave) {
    No *x = malloc(sizeof(No));
    if (x == NULL) {
        exit(1);
    }
    x->chave = chave;
    x->prox = &L->nil;
    x->ant = L->nil.ant;
    L->nil.ant->prox = x;
    L->nil.ant = x;
}

No *busca(Lista *L, int k, int *comparacoes) {
    L->nil.chave = k;
    No *x = L->nil.prox;
    *comparacoes = 1;
    while (x->chave != k) {
        x = x->prox;
        (*comparacoes)++;
    }
    return x;
}

int main(void) {
    Lista L;
    L.nil.prox = L.nil.ant = &L.nil;
    int v[] = {4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 6; i++) {
        insere_fim(&L, v[i]);
    }
    int procura[] = {15, 42, 99};
    for (int i = 0; i < 3; i++) {
        int c;
        No *x = busca(&L, procura[i], &c);
        printf("%2d: %s, %d comparações\n", procura[i], x == &L.nil ? "não está" : "achou", c);
    }
    No *x = L.nil.prox;
    while (x != &L.nil) {
        No *s = x->prox;
        free(x);
        x = s;
    }
    return 0;
}
