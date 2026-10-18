// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E865 · ★☆☆

#include <stdio.h>
#include "rubronegra.h"

int conta_vermelhos(const NoRN *r) {
    if (r == NULL) {
        return 0;
    }
    return (r->vermelho ? 1 : 0) + conta_vermelhos(r->esq) + conta_vermelhos(r->dir);
}

int conta_nos(const NoRN *r) {
    if (r == NULL) {
        return 0;
    }
    return 1 + conta_nos(r->esq) + conta_nos(r->dir);
}

int main(void) {
    NoRN *raiz = NULL;
    for (int c = 1; c <= 10; c++) {
        raiz = rn_insere(raiz, c);
    }
    printf("pré:");
    rn_pre_ordem(raiz);
    int n = conta_nos(raiz), v = conta_vermelhos(raiz);
    printf("\nnós: %d | vermelhos: %d | pretos: %d\n", n, v, n - v);
    raiz = rn_libera(raiz);
    return 0;
}
