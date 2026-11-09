// 0176 · AVL: remoção
// Exercício E1053 · ★★☆

#include <stdio.h>
#include "avlrem.h"

int menor(const NoA *r) {
    while (r->esq != NULL) {
        r = r->esq;
    }
    return r->chave;
}

int main(void) {
    NoA *raiz = NULL;
    for (int i = 0; i < 20; i++) {
        raiz = avr_insere(raiz, i * 7 % 20);
    }
    int antes = avr_rotacoes();
    int maior_altura = avr_altura(raiz);
    printf("Atendidos:");
    while (raiz != NULL) {
        int k = menor(raiz);
        printf(" %d", k);
        raiz = avr_remove(raiz, k);
    }
    printf("\nAltura no começo: %d | rotações para esvaziar: %d\n", maior_altura, avr_rotacoes() - antes);
    return 0;
}
