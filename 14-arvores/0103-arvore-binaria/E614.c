// 0103 · Árvore binária e percursos
// Exercício E614 · ★☆☆
//
// Complete as funções conta_folhas e conta_internos. Na árvore da conta do
// churrasco, (8 - 3) * (4 + 2), as folhas são os números e os nós internos
// são os operadores.
//
//   Saída esperada:
//   Números: 4
//   Operadores: 3
//
// Dicas:
// 1. Árvore vazia: 0. Folha: esq e dir são NULL.
// 2. conta_internos pode ser arv_conta(r) - conta_folhas(r), mas tente
//    escrever a versão recursiva também.
// 3. Resposta esperada: Números: 4 e Operadores: 3.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdio.h>
#include "arvore.h"

int conta_folhas(const No *r) {
    (void)r; // apague esta linha
    return 0;
}

int conta_internos(const No *r) {
    (void)r; // apague esta linha
    return 0;
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    printf("Números: %d\n", conta_folhas(raiz));
    printf("Operadores: %d\n", conta_internos(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
