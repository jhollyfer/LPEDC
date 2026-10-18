// 0103 · Árvore binária e percursos
// Exercício E617 · ★★★
//
// Ache o bug. A função por_nivel deveria mostrar a árvore do churrasco nível
// por nível, mas mostra outra ordem:
//
//   Saída esperada:
//   * - + 8 3 4 2
//
//   Saída que aparece:
//   * + 2 4 - 3 8
//
// O programa não quebra e o AddressSanitizer não reclama: o erro é de
// lógica. Ache a linha errada, conserte, e responda: que estrutura de dados
// a função está usando sem querer? E que percurso é esse que aparece?
//
// Dicas:
// 1. Uma fila tira da frente e põe no fim. Olhe de onde sai o "atual".
// 2. Com ini sempre em 0 e fila[--fim], o último que entrou é o primeiro que
//    sai.
// 3. Resposta esperada: a linha "const No *atual = fila[--fim];" deveria ser
//    "fila[ini++]". Do jeito errado, o vetor vira uma PILHA, e a saída é uma
//    pré-ordem espelhada (raiz, direita, esquerda), porque o filho direito
//    entra por último e sai primeiro. Consertado: * - + 8 3 4 2.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include "arvore.h"

void por_nivel(const No *r) {
    const No *fila[16];
    int ini = 0, fim = 0;
    fila[fim++] = r;
    while (ini < fim) {
        const No *atual = fila[--fim];
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
