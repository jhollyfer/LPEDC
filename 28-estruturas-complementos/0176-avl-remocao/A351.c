// A351 · Esvaziando pela esquerda

#include <stdio.h>
#include "avlrem.h"

int main(void) {
    NoA *raiz = NULL;
    for (int k = 1; k <= 15; k++) { // 15 chaves: árvore perfeita de altura 3
        raiz = avr_insere(raiz, k);
    }
    printf("Cheia: pré");
    avr_pre_ordem(raiz);
    printf("\n");
    for (int k = 1; k <= 10; k++) { // tira sempre o menor
        int antes = avr_rotacoes();
        raiz = avr_remove(raiz, k);
        printf("tira %2d: rotações %d | altura %d | raiz %2d\n", k,
               avr_rotacoes() - antes, avr_altura(raiz), raiz->chave);
    }
    printf("Sobrou: pré");
    avr_pre_ordem(raiz);
    printf("\n");
    raiz = avr_libera(raiz);
    return 0;
}
// Saída:
// Cheia: pré 8 4 2 1 3 6 5 7 12 10 9 11 14 13 15
// tira  1: rotações 0 | altura 3 | raiz  8
// tira  2: rotações 0 | altura 3 | raiz  8
// tira  3: rotações 1 | altura 3 | raiz  8
// tira  4: rotações 0 | altura 3 | raiz  8
// tira  5: rotações 0 | altura 3 | raiz  8
// tira  6: rotações 1 | altura 3 | raiz 12
// tira  7: rotações 1 | altura 3 | raiz 12
// tira  8: rotações 0 | altura 2 | raiz 12
// tira  9: rotações 0 | altura 2 | raiz 12
// tira 10: rotações 0 | altura 2 | raiz 12
// Sobrou: pré 12 11 14 13 15
