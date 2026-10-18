// 0103 · Árvore binária e percursos
// Exercício E617 · ★★★
//
// Resposta: fila[--fim] tira do fim, e o vetor vira uma pilha. A saída
// errada é uma pré-ordem espelhada (raiz, direita, esquerda). Com
// fila[ini++] a função vira uma fila de verdade: * - + 8 3 4 2.

#include <stdio.h>
#include "arvore.h"

void por_nivel(const No *r) {
    const No *fila[16];
    int ini = 0, fim = 0;
    fila[fim++] = r;
    while (ini < fim) {
        const No *atual = fila[ini++]; // tira da FRENTE
        printf("%c ", atual->info);
        if (atual->esq != NULL) {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL) {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    por_nivel(raiz);

    raiz = arv_libera(raiz);
    return 0;
}
