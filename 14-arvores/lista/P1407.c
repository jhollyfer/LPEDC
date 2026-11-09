// Lista · Módulo 14 · Árvores
// Exercício P1407 · ★☆☆ · O fator de cada nó
//
// Insira os pedidos 40, 20, 60, 10, 30, 25, 35, 70, 27 numa BST comum (sem
// balancear). Escreva bool fatores(const No *r), que percorre a árvore EM
// ORDEM mostrando o fator de balanceamento de cada nó,
// altura(esq) - altura(dir), e devolve true se todos os fatores estão entre
// -1 e 1. No fim, diga se a árvore poderia ser uma AVL.
//
//   Saída esperada:
//   10: fator 0
//   20: fator -2
//   25: fator -1
//   27: fator 0
//   30: fator 1
//   35: fator 0
//   40: fator 2
//   60: fator -1
//   70: fator 0
//   é AVL? não
//
// Dicas:
// 1. Altura em arestas, árvore vazia = -1: a folha tem fator -1 - (-1) = 0.
// 2. Chame fatores(r->esq) ANTES de imprimir e fatores(r->dir) depois, e
//    guarde os resultados em variáveis (não use && direto, senão a recursão
//    da direita pode nem rodar).
// 3. Sem o 27, a árvore seria AVL. Ele pendura o 25 e desequilibra o 20 e a
//    raiz ao mesmo tempo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
