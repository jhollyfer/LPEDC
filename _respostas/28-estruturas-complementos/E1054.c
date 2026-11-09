// 0176 · AVL: remoção
// Exercício E1054 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, altura;
    struct No *esq, *dir;
} No;

int alt(const No *r) {
    return r == NULL ? -1 : r->altura;
}

void atualiza(No *r) {
    r->altura = 1 + (alt(r->esq) > alt(r->dir) ? alt(r->esq) : alt(r->dir));
}

No *gira_dir(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

No *gira_esq(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

No *equilibra(No *r) {
    atualiza(r);
    int fb = alt(r->esq) - alt(r->dir);
    if (fb > 1) {
        if (alt(r->esq->esq) < alt(r->esq->dir)) {
            r->esq = gira_esq(r->esq);
        }
        return gira_dir(r);
    }
    if (fb < -1) {
        if (alt(r->dir->dir) < alt(r->dir->esq)) {
            r->dir = gira_dir(r->dir);
        }
        return gira_esq(r);
    }
    return r;
}

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *n = malloc(sizeof(No));
        if (n == NULL) {
            exit(1);
        }
        n->chave = chave;
        n->altura = 0;
        n->esq = n->dir = NULL;
        return n;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return equilibra(r);
}

No *remove_chave(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_chave(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_chave(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        No *a = r->esq; // o antecessor: o maior da esquerda
        while (a->dir != NULL) {
            a = a->dir;
        }
        r->chave = a->chave;
        r->esq = remove_chave(r->esq, a->chave);
    }
    return equilibra(r);
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
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
    int v[] = {40, 20, 60, 10, 30, 50, 70, 25, 35};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, v[i]);
    }
    printf("início:  pré");
    pre(raiz);
    raiz = remove_chave(raiz, 40);
    printf("\ntira 40: pré");
    pre(raiz);
    raiz = remove_chave(raiz, 20);
    printf("\ntira 20: pré");
    pre(raiz);
    printf("\naltura final: %d\n", alt(raiz));
    libera(raiz);
    return 0;
}
