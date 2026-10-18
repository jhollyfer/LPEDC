// 0098 · Árvore binária e percursos
// Exercício E583 · ★☆☆
//
// No papel, escreva os quatro percursos desta árvore (pré-ordem, em ordem,
// pós-ordem e por nível):
//
//   M
//   ├── esq: G
//   │   ├── esq: C
//   │   └── dir: J
//   └── dir: T
//       └── dir: X
//
// O programa abaixo monta essa árvore e imprime os percursos. Só rode DEPOIS
// de escrever as suas respostas, para conferir.
//
// Dicas:
// 1. Pré-ordem: anote a raiz ao chegar nela. Pós-ordem: ao sair dela.
// 2. Em ordem: tudo da esquerda, a raiz, tudo da direita. T não tem filho
//    esquerdo, então T vem antes de X.
// 3. Resposta esperada: pré M G C J T X; em C G J M T X; pós C J G X T M;
//    por nível M G T C J X.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "arvore.h"

int main(void) {
    No *raiz = arv_cria('M',
                        arv_cria('G', arv_cria('C', NULL, NULL), arv_cria('J', NULL, NULL)),
                        arv_cria('T', NULL, arv_cria('X', NULL, NULL)));

    printf("Pré-ordem:");
    arv_pre_ordem(raiz);
    printf("\nEm ordem: ");
    arv_em_ordem(raiz);
    printf("\nPós-ordem:");
    arv_pos_ordem(raiz);
    printf("\nPor nível:");
    arv_por_nivel(raiz);
    printf("\n");

    raiz = arv_libera(raiz);
    return 0;
}
