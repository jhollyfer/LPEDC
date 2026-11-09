// 0175 · Conceitos e sucessor
// Exercício E1046 · ★☆☆

#include <stdio.h>
#include "arvpai.h"

// mostra, da esquerda para a direita, os nós de profundidade k
void mostra_nivel(const NoP *r, int k) {
    if (r == NULL) {
        return;
    }
    mostra_nivel(r->esq, k);
    if (ap_profundidade(r) == k) {
        printf(" %d", r->chave);
    }
    mostra_nivel(r->dir, k);
}

int main(void) {
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    NoP *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = ap_insere(raiz, codigos[i]);
    }
    int h = ap_altura(raiz);
    for (int k = 0; k <= h; k++) {
        printf("nível %d:", k);
        mostra_nivel(raiz, k);
        printf("\n");
    }
    printf("altura da árvore: %d\n", h);
    raiz = ap_libera(raiz);
    return 0;
}
