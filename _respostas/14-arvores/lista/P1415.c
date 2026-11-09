// Lista · Módulo 14 · Árvores
// Exercício P1415 · ★★☆ · A AVL contando as rotações

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, alt;
    struct No *esq, *dir;
} No;

const char *ultima_rotacao = "";

int alt(const No *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(No *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const No *p) {
    return alt(p->esq) - alt(p->dir);
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

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->alt = 0;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    } else {
        return r;
    }
    atualiza(r);
    if (fator(r) > 1) {
        if (fator(r->esq) < 0) {
            ultima_rotacao = "dupla esquerda-direita (LR)";
            r->esq = gira_esq(r->esq);
        } else {
            ultima_rotacao = "simples à direita (LL)";
        }
        return gira_dir(r);
    }
    if (fator(r) < -1) {
        if (fator(r->dir) > 0) {
            ultima_rotacao = "dupla direita-esquerda (RL)";
            r->dir = gira_dir(r->dir);
        } else {
            ultima_rotacao = "simples à esquerda (RR)";
        }
        return gira_esq(r);
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

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int pedidos[] = {10, 30, 20, 5, 4, 40, 50, 45, 8, 9};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        ultima_rotacao = "";
        raiz = insere(raiz, pedidos[i]);
        printf("+%d:", pedidos[i]);
        pre(raiz);
        if (ultima_rotacao[0] != '\0') {
            printf("   <- rotação %s", ultima_rotacao);
        }
        printf("\n");
    }
    printf("altura final: %d\n", raiz->alt);
    libera(raiz);
    return 0;
}
