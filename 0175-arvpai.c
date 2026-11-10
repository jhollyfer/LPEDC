// arvpai.c · implementação da BST com ponteiro para o pai
#include <stdio.h>
#include <stdlib.h>
#include "0175-arvpai.h"

NoP *ap_insere(NoP *raiz, int chave) {
    NoP *pai = NULL;
    NoP *x = raiz;
    while (x != NULL) { // desce como na busca, lembrando o pai
        pai = x;
        if (chave < x->chave) {
            x = x->esq;
        } else if (chave > x->chave) {
            x = x->dir;
        } else {
            return raiz; // repetida
        }
    }
    NoP *z = malloc(sizeof(NoP));
    if (z == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    z->chave = chave;
    z->esq = NULL;
    z->dir = NULL;
    z->pai = pai;
    if (pai == NULL) {
        return z; // árvore vazia: z é a raiz
    }
    if (chave < pai->chave) {
        pai->esq = z;
    } else {
        pai->dir = z;
    }
    return raiz;
}

NoP *ap_busca(NoP *raiz, int chave) {
    while (raiz != NULL && raiz->chave != chave) {
        raiz = chave < raiz->chave ? raiz->esq : raiz->dir;
    }
    return raiz;
}

NoP *ap_minimo(NoP *x) {
    while (x->esq != NULL) {
        x = x->esq;
    }
    return x;
}

NoP *ap_maximo(NoP *x) {
    while (x->dir != NULL) {
        x = x->dir;
    }
    return x;
}

NoP *ap_sucessor(NoP *x) {
    if (x->dir != NULL) {
        return ap_minimo(x->dir); // caso 1: o menor da subárvore direita
    }
    NoP *y = x->pai; // caso 2: sobe até chegar por um filho esquerdo
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

NoP *ap_antecessor(NoP *x) {
    if (x->esq != NULL) {
        return ap_maximo(x->esq); // o espelho do sucessor
    }
    NoP *y = x->pai;
    while (y != NULL && x == y->esq) {
        x = y;
        y = y->pai;
    }
    return y;
}

int ap_grau(const NoP *x) {
    return (x->esq != NULL) + (x->dir != NULL);
}

int ap_altura(const NoP *x) {
    if (x == NULL) {
        return -1;
    }
    int he = ap_altura(x->esq);
    int hd = ap_altura(x->dir);
    return 1 + (he > hd ? he : hd);
}

int ap_profundidade(const NoP *x) {
    int p = 0;
    while (x->pai != NULL) {
        x = x->pai;
        p++;
    }
    return p;
}

int ap_fator(const NoP *x) {
    return ap_altura(x->esq) - ap_altura(x->dir);
}

void ap_em_ordem(const NoP *raiz) {
    if (raiz != NULL) {
        ap_em_ordem(raiz->esq);
        printf(" %d", raiz->chave);
        ap_em_ordem(raiz->dir);
    }
}

NoP *ap_libera(NoP *raiz) {
    if (raiz != NULL) {
        ap_libera(raiz->esq);
        ap_libera(raiz->dir);
        free(raiz);
    }
    return NULL;
}
