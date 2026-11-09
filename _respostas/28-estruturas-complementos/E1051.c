// 0176 · AVL: remoção
// Exercício E1051 · ★☆☆

#include <stdio.h>
#include "avlrem.h"

int main(void) {
    int matriculas[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 1};
    NoA *raiz = NULL;
    for (int i = 0; i < 12; i++) {
        raiz = avr_insere(raiz, matriculas[i]);
    }
    printf("início:  pré");
    avr_pre_ordem(raiz);
    printf(" | altura %d\n", avr_altura(raiz));
    int saem[] = {80, 75, 60};
    for (int i = 0; i < 3; i++) {
        int antes = avr_rotacoes();
        raiz = avr_remove(raiz, saem[i]);
        printf("tira %d: pré", saem[i]);
        avr_pre_ordem(raiz);
        printf(" | altura %d | rotações %d\n", avr_altura(raiz), avr_rotacoes() - antes);
    }
    raiz = avr_libera(raiz);
    return 0;
}
