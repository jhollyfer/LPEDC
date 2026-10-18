// 0101 · AVL: balanceamento e rotações
// Exercício E605 · ★★★
//
// Resposta: em gira_esq, d era atualizado antes de r. Só que r virou filho de
// d, e a altura de d depende da altura NOVA de r. Com a ordem trocada, d fica
// com altura errada, os fatores dos ancestrais saem errados e algumas
// rotações deixam de acontecer (a raiz chegava a dizer altura 9 com altura
// real 5).

#include <stdio.h>
#include <stdlib.h>

typedef struct Pedido {
    int num;
    int alt;
    struct Pedido *esq, *dir;
} Pedido;

int alt(const Pedido *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(Pedido *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const Pedido *p) {
    return alt(p->esq) - alt(p->dir);
}

Pedido *gira_dir(Pedido *r) {
    Pedido *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

Pedido *gira_esq(Pedido *r) {
    Pedido *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r); // r agora é filho de d: atualiza ele primeiro
    atualiza(d);
    return d;
}

Pedido *insere(Pedido *r, int num) {
    if (r == NULL) {
        Pedido *p = malloc(sizeof(Pedido));
        if (p == NULL) {
            exit(1);
        }
        p->num = num;
        p->alt = 0;
        p->esq = p->dir = NULL;
        return p;
    }
    if (num < r->num) {
        r->esq = insere(r->esq, num);
    } else if (num > r->num) {
        r->dir = insere(r->dir, num);
    } else {
        return r;
    }
    atualiza(r);
    if (fator(r) > 1) {
        if (fator(r->esq) < 0) {
            r->esq = gira_esq(r->esq);
        }
        return gira_dir(r);
    }
    if (fator(r) < -1) {
        if (fator(r->dir) > 0) {
            r->dir = gira_dir(r->dir);
        }
        return gira_esq(r);
    }
    return r;
}

int altura_real(const Pedido *p) {
    if (p == NULL) {
        return -1;
    }
    int he = altura_real(p->esq), hd = altura_real(p->dir);
    return 1 + (he > hd ? he : hd);
}

void pre(const Pedido *p) {
    if (p != NULL) {
        printf(" %d", p->num);
        pre(p->esq);
        pre(p->dir);
    }
}

void libera(Pedido *p) {
    if (p != NULL) {
        libera(p->esq);
        libera(p->dir);
        free(p);
    }
}

int main(void) {
    Pedido *raiz = NULL;
    for (int i = 1; i <= 15; i++) {
        raiz = insere(raiz, i);
    }
    printf("pré:");
    pre(raiz);
    printf("\naltura guardada na raiz: %d, altura real: %d\n", raiz->alt, altura_real(raiz));
    libera(raiz);
    return 0;
}
