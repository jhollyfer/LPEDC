// 0176 · AVL: remoção
// Exercício E1056 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include "avlrem.h"

static int proxima = 1; // a próxima chave a distribuir, em ordem

// árvore de Fibonacci de altura h: esquerda de altura h - 1, direita de
// altura h - 2 (todo nó com fator 1). As chaves saem em ordem.
NoA *fibonacci(int h) {
    if (h < 0) {
        return NULL;
    }
    NoA *n = malloc(sizeof(NoA));
    if (n == NULL) {
        exit(1);
    }
    n->esq = fibonacci(h - 1);
    n->chave = proxima++;
    n->dir = fibonacci(h - 2);
    n->altura = h;
    return n;
}

int conta(const NoA *r) {
    return r == NULL ? 0 : 1 + conta(r->esq) + conta(r->dir);
}

int main(void) {
    for (int h = 2; h <= 9; h++) {
        proxima = 1;
        NoA *r = fibonacci(h);
        int n = conta(r);
        int antes = avr_rotacoes();
        r = avr_remove(r, n); // a maior chave
        printf("altura %d: %3d nós | rotações %d | altura depois %d\n", h, n,
               avr_rotacoes() - antes, avr_altura(r));
        r = avr_libera(r);
    }
    return 0;
}
