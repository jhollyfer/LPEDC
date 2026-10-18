// 0101 · AVL: balanceamento e rotações
// Exercício E605 · ★★★
//
// Ache o bug. Esta é uma AVL escrita do zero (sem o avl.h), com UM erro
// numa das rotações. Ela insere os pedidos de 1 a 15, em ordem. Uma AVL
// certa termina perfeita, com altura 3, e a altura guardada na raiz bate
// com a altura de verdade (contada percorrendo a árvore):
//
//   Saída esperada:
//   pré: 8 4 2 1 3 6 5 7 12 10 9 11 14 13 15
//   altura guardada na raiz: 3, altura real: 3
//
// Rode e compare. O programa não quebra; o erro é de lógica. Ache a linha,
// conserte e explique por que a ordem dessas duas linhas importa.
//
// Dicas:
// 1. A altura de um nó é calculada a partir das alturas dos filhos. Depois
//    da rotação, quem é filho de quem?
// 2. Compare gira_esq com gira_dir, linha por linha.
// 3. Resposta esperada: em gira_esq, "atualiza(d);" vem antes de
//    "atualiza(r);". Mas r virou filho de d: d é recalculado com a altura
//    VELHA de r, e a altura de d fica errada. Os fatores dos ancestrais saem
//    errados, e a árvore deixa de girar quando devia. Trocando as duas
//    linhas, a saída fica igual à esperada.
//
// Escreva sua resposta abaixo (conserte o código):

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
    atualiza(d);
    atualiza(r);
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
