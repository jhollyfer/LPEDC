// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2814 · ★★☆ · Do maior para o menor com o antecessor

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

No *maximo(No *x) {
    while (x->dir != NULL) {
        x = x->dir;
    }
    return x;
}

No *antecessor(No *x) {
    if (x->esq != NULL) {
        return maximo(x->esq);
    }
    No *y = x->pai;
    while (y != NULL && x == y->esq) {
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
    int v[] = {5200, 3100, 8800, 2500, 4700, 7600, 9900, 4100};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = insere(raiz, v[i]);
    }
    printf("ranking:");
    for (No *x = maximo(raiz); x != NULL; x = antecessor(x)) {
        printf(" %d", x->chave);
    }
    No *a = antecessor(busca(raiz, 4700));
    No *b = antecessor(busca(raiz, 2500));
    printf("\nantes de 4700: %d | antes de 2500: %s\n", a->chave, b == NULL ? "nenhum" : "?");
    libera(raiz);
    return 0;
}
