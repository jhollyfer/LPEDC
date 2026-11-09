// Lista · Módulo 14 · Árvores
// Exercício P1402 · ★☆☆ · A BST das senhas e os três percursos

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

void em(const No *r) {
    if (r != NULL) {
        em(r->esq);
        printf(" %d", r->chave);
        em(r->dir);
    }
}

void pos(const No *r) {
    if (r != NULL) {
        pos(r->esq);
        pos(r->dir);
        printf(" %d", r->chave);
    }
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int senhas[] = {50, 30, 70, 20, 40, 60, 80, 35, 65};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, senhas[i]);
    }

    printf("pré:");
    pre(raiz);
    printf("\nem: ");
    em(raiz);
    printf("\npós:");
    pos(raiz);
    printf("\n");
    libera(raiz);
    return 0;
}
