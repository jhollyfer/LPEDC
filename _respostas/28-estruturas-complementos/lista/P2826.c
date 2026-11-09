// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2826 · ★★★ · Relatório por intervalo

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

No *sucessor(No *x) {
    if (x->dir != NULL) {
        x = x->dir;
        while (x->esq != NULL) {
            x = x->esq;
        }
        return x;
    }
    No *y = x->pai;
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

No *teto(No *r, int a) {
    No *candidato = NULL;
    while (r != NULL) {
        if (r->chave >= a) {
            candidato = r;
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return candidato;
}

void relatorio(No *raiz, int a, int b) {
    int chamadas = 0;
    printf("[%d, %d]:", a, b);
    for (No *x = teto(raiz, a); x != NULL && x->chave <= b; x = sucessor(x)) {
        printf(" %d", x->chave);
        chamadas++;
    }
    printf(" (%d sucessores)\n", chamadas);
}

int main(void) {
    int v[] = {412, 157, 890, 233, 501, 678, 120, 345, 999, 460};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, v[i]);
    }
    relatorio(raiz, 200, 500);
    relatorio(raiz, 0, 150);
    relatorio(raiz, 900, 2000);
    relatorio(raiz, 600, 650);
    libera(raiz);
    return 0;
}
