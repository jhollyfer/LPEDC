// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2806 · ★☆☆ · Mínimo, máximo e sucessor

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

No *insere(No *raiz, int chave) {
    No *pai = NULL, *x = raiz;
    while (x != NULL) {
        pai = x;
        x = chave < x->chave ? x->esq : x->dir;
    }
    No *z = malloc(sizeof(No));
    if (z == NULL) {
        exit(1);
    }
    z->chave = chave;
    z->esq = z->dir = NULL;
    z->pai = pai;
    if (pai == NULL) {
        return z;
    }
    if (chave < pai->chave) {
        pai->esq = z;
    } else {
        pai->dir = z;
    }
    return raiz;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

No *minimo(No *x) {
    while (x->esq != NULL) {
        x = x->esq;
    }
    return x;
}

No *maximo(No *x) {
    while (x->dir != NULL) {
        x = x->dir;
    }
    return x;
}

No *sucessor(No *x) {
    if (x->dir != NULL) {
        return minimo(x->dir);
    }
    No *y = x->pai;
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

No *busca(No *r, int k) {
    while (r != NULL && r->chave != k) {
        r = k < r->chave ? r->esq : r->dir;
    }
    return r;
}

int main(void) {
    int v[] = {1210, 830, 1545, 700, 945, 1400, 1700, 900};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = insere(raiz, v[i]);
    }
    printf("primeiro: %d | último: %d\n", minimo(raiz)->chave, maximo(raiz)->chave);
    int q[] = {945, 1210, 1700};
    for (int i = 0; i < 3; i++) {
        No *s = sucessor(busca(raiz, q[i]));
        if (s == NULL) {
            printf("depois de %d: nenhum\n", q[i]);
        } else {
            printf("depois de %d: %d\n", q[i], s->chave);
        }
    }
    libera(raiz);
    return 0;
}
