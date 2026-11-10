// 0098 · Árvore binária e percursos
// Exercício E585 · ★★☆
//
// Escreva a função espelha(r), que transforma a árvore na sua imagem no
// espelho: em todo nó, a subárvore da esquerda troca de lugar com a da
// direita. Não crie nós novos; só troque ponteiros. O main imprime a em
// ordem antes e depois:
//
//   Saída esperada:
//   Antes:  8 - 3 * 4 + 2
//   Depois: 2 + 4 * 3 - 8
//
// Escreva sua resposta abaixo (complete espelha):

#include <stdio.h>
#include "arvore.h"

void espelha(No *r) {
    (void)r; // apague esta linha
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    printf("Antes: ");
    arv_em_ordem(raiz);
    espelha(raiz);
    printf("\nDepois:");
    arv_em_ordem(raiz);
    printf("\n");

    raiz = arv_libera(raiz);
    return 0;
}
