// 0175 · Conceitos e sucessor
// Exercício E1048 · ★★☆

#include <stdio.h>
#include "arvpai.h"

// sucessor sem usar o campo pai: desce da raiz e guarda o último nó em que
// virou à esquerda
const NoP *sucessor_sem_pai(const NoP *raiz, int chave) {
    const NoP *candidato = NULL;
    const NoP *x = raiz;
    while (x != NULL && x->chave != chave) {
        if (chave < x->chave) {
            candidato = x;
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    if (x == NULL) {
        return NULL; // a chave não está na árvore
    }
    if (x->dir != NULL) {
        x = x->dir;
        while (x->esq != NULL) {
            x = x->esq;
        }
        return x;
    }
    return candidato;
}

int main(void) {
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    NoP *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = ap_insere(raiz, codigos[i]);
    }
    int iguais = 0;
    for (NoP *x = ap_minimo(raiz); x != NULL; x = ap_sucessor(x)) {
        const NoP *a = ap_sucessor(x);
        const NoP *b = sucessor_sem_pai(raiz, x->chave);
        printf("%d -> %d\n", x->chave, b == NULL ? -1 : b->chave);
        iguais += (a == b);
    }
    printf("iguais ao ap_sucessor: %d de 10\n", iguais);
    raiz = ap_libera(raiz);
    return 0;
}
