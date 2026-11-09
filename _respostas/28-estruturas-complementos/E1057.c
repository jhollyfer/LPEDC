// 0177 · Rubro-negra clássica
// Exercício E1057 · ★☆☆

#include <stdio.h>
#include "vermelhopreto.h"

int conta_vermelhos(const ArvVP *T, const NoVP *x) {
    if (x == &T->nil) {
        return 0;
    }
    return (x->cor == VERMELHO) + conta_vermelhos(T, x->esq) + conta_vermelhos(T, x->dir);
}

int main(void) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    for (int k = 1; k <= 10; k++) {
        vp_insere(T, k);
    }
    printf("pré:");
    vp_pre_ordem(T);
    int v = conta_vermelhos(T, T->raiz);
    printf("\nvermelhos: %d | pretos: %d | altura negra: %d\n", v, 10 - v, vp_altura_negra(T));
    vp_libera(T);
    return 0;
}
