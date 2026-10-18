// 0103 · Árvore binária e percursos
// Exercício E615 · ★★☆
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
// Dicas:
// 1. Árvore vazia: nada a fazer.
// 2. Troque r->esq com r->dir usando um ponteiro auxiliar e chame espelha
//    nas duas subárvores (antes ou depois da troca, tanto faz).
// 3. Resposta esperada: Antes: 8 - 3 * 4 + 2 e Depois: 2 + 4 * 3 - 8. Repare
//    que a em ordem do espelho é a em ordem original de trás para frente.
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
