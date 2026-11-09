// 0175 · Conceitos e sucessor
// Exercício E1047 · ★★☆

#include <stdio.h>
#include "arvpai.h"

int main(void) {
    int precos[] = {1890, 990, 2450, 1290, 3100, 750, 2100};
    NoP *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = ap_insere(raiz, precos[i]);
    }
    printf("Do mais caro ao mais barato:");
    for (NoP *x = ap_maximo(raiz); x != NULL; x = ap_antecessor(x)) {
        printf(" %d.%02d", x->chave / 100, x->chave % 100);
    }
    printf("\n");
    NoP *x = ap_busca(raiz, 1290);
    NoP *antes = ap_antecessor(x);
    NoP *depois = ap_sucessor(x);
    printf("Vizinhos de 12.90: %d.%02d e %d.%02d\n", antes->chave / 100, antes->chave % 100,
           depois->chave / 100, depois->chave % 100);
    raiz = ap_libera(raiz);
    return 0;
}
