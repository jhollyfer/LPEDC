// A349 · Em ordem sem recursão e sem pilha

#include <stdio.h>
#include "0175-arvpai.h"

static int passos = 0; // quantos ponteiros (esq, dir ou pai) foram seguidos

static NoP *minimo_contando(NoP *x) {
    while (x->esq != NULL) {
        x = x->esq;
        passos++;
    }
    return x;
}

// o mesmo TREE-SUCCESSOR do arvpai.c, contando cada ponteiro seguido
static NoP *sucessor_contando(NoP *x) {
    if (x->dir != NULL) {
        passos++;
        return minimo_contando(x->dir);
    }
    NoP *y = x->pai;
    passos++;
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
        passos++;
    }
    return y;
}

int main(void) {
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    int n = 10;
    NoP *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = ap_insere(raiz, codigos[i]);
    }
    printf("Em ordem:");
    for (NoP *x = minimo_contando(raiz); x != NULL; x = sucessor_contando(x)) {
        printf(" %d", x->chave);
    }
    printf("\n%d nós, %d ponteiros seguidos: cada aresta 2 vezes (%d) + o pai NULL da raiz\n",
           n, passos, 2 * (n - 1));
    printf("Média por sucessor: %.1f, embora um só possa custar a altura (%d)\n",
           (double)passos / n, ap_altura(raiz));

    raiz = ap_libera(raiz);
    return 0;
}
// Saída:
// Em ordem: 20 30 35 40 45 50 60 65 70 80
// 10 nós, 19 ponteiros seguidos: cada aresta 2 vezes (18) + o pai NULL da raiz
// Média por sucessor: 1.9, embora um só possa custar a altura (3)
