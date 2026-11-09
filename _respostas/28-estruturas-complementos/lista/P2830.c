// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2830 · ★★★ · O painel de voos

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

No *busca(No *r, int k) {
    while (r != NULL && r->chave != k) {
        r = k < r->chave ? r->esq : r->dir;
    }
    return r;
}

No *teto(No *r, int h) {
    No *c = NULL;
    while (r != NULL) {
        if (r->chave >= h) {
            c = r;
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return c;
}

No *piso(No *r, int h) {
    No *c = NULL;
    while (r != NULL) {
        if (r->chave <= h) {
            c = r;
            r = r->dir;
        } else {
            r = r->esq;
        }
    }
    return c;
}

// põe a subárvore v no lugar de u; devolve a raiz
No *transplanta(No *raiz, No *u, No *v) {
    if (u->pai == NULL) {
        raiz = v;
    } else if (u == u->pai->esq) {
        u->pai->esq = v;
    } else {
        u->pai->dir = v;
    }
    if (v != NULL) {
        v->pai = u->pai;
    }
    return raiz;
}

No *remove_no(No *raiz, No *z) {
    if (z->esq == NULL) {
        raiz = transplanta(raiz, z, z->dir);
    } else if (z->dir == NULL) {
        raiz = transplanta(raiz, z, z->esq);
    } else {
        No *y = minimo(z->dir);
        if (y != z->dir) {
            raiz = transplanta(raiz, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        raiz = transplanta(raiz, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    free(z);
    return raiz;
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

void consulta(No *raiz) {
    int horas[] = {1130, 1415};
    for (int i = 0; i < 2; i++) {
        No *a = piso(raiz, horas[i]), *b = teto(raiz, horas[i]);
        printf("  %d: antes %d, depois %d\n", horas[i], a ? a->chave : -1, b ? b->chave : -1);
    }
}

int main(void) {
    int v[] = {1415, 905, 1830, 640, 1120, 1600, 2210, 1000};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = insere(raiz, v[i]);
    }
    printf("pré:");
    pre(raiz);
    printf("\n");
    consulta(raiz);
    raiz = remove_no(raiz, busca(raiz, 1415));
    raiz = remove_no(raiz, busca(raiz, 640));
    printf("sem 1415 e 640: pré");
    pre(raiz);
    printf("\n");
    consulta(raiz);
    libera(raiz);
    return 0;
}
