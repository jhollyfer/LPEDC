// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2218 · ★★☆ · Rotações com ponteiro para o pai

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){chave, esq, dir, NULL};
    if (esq != NULL) {
        esq->pai = n;
    }
    if (dir != NULL) {
        dir->pai = n;
    }
    return n;
}

No *rot_esq(No *raiz, No *x) {
    No *y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
    return raiz;
}

No *rot_dir(No *raiz, No *y) {
    No *x = y->esq;
    y->esq = x->dir;
    if (x->dir != NULL) {
        x->dir->pai = y;
    }
    x->pai = y->pai;
    if (y->pai == NULL) {
        raiz = x;
    } else if (y == y->pai->dir) {
        y->pai->dir = x;
    } else {
        y->pai->esq = x;
    }
    x->dir = y;
    y->pai = x;
    return raiz;
}

void em_ordem(const No *r) {
    if (r != NULL) {
        em_ordem(r->esq);
        printf(" %d", r->chave);
        em_ordem(r->dir);
    }
}

bool pais_ok(const No *r) {
    if (r == NULL) {
        return true;
    }
    if (r->esq != NULL && r->esq->pai != r) {
        return false;
    }
    if (r->dir != NULL && r->dir->pai != r) {
        return false;
    }
    return pais_ok(r->esq) && pais_ok(r->dir);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void confere(const char *passo, const No *raiz) {
    printf("%s: raiz %d, em ordem", passo, raiz->chave);
    em_ordem(raiz);
    printf(", pais %s\n", pais_ok(raiz) && raiz->pai == NULL ? "OK" : "errados");
}

int main(void) {
    No *raiz = no(10, no(5, NULL, NULL), no(20, no(15, NULL, NULL), no(30, NULL, NULL)));
    No *n10 = raiz, *n20 = raiz->dir;
    confere("Início", raiz);
    raiz = rot_esq(raiz, n10);
    confere("rot_esq(10)", raiz);
    raiz = rot_dir(raiz, n20);
    confere("rot_dir(20)", raiz);
    libera(raiz);
    return 0;
}
