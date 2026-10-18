// 0099 · BST: busca e inserção
// Exercício E591 · ★★☆
//
// A loja guarda os preços dos produtos (em reais, inteiros) numa BST. O
// cliente quer ver só o que custa entre R$ 35 e R$ 65. Escreva
// faixa(r, min, max, &visitados), que imprime em ordem crescente as chaves
// no intervalo [min, max] e conta quantos nós a função visitou.
//
// O desafio: não entre numa subárvore que não pode ter resposta. Se a chave
// do nó já é menor que min, nada à esquerda dele serve.
//
//   Saída esperada:
//   Entre 35 e 65: 40 50 60
//   Nós visitados: 5 de 9
//
// Dicas:
// 1. Comece como uma em ordem e conte cada chamada com r != NULL.
// 2. Só desça para a esquerda se r->chave > min; só desça para a direita se
//    r->chave < max; só imprima se min <= r->chave <= max.
// 3. Resposta esperada: 40 50 60, com 5 nós visitados (50, 30, 40, 70, 60).
//    Os nós 20, 80, 10 e 90 nunca são tocados.
//
// Escreva sua resposta abaixo (complete faixa):

#include <stdio.h>
#include "bst.h"

void faixa(const No *r, int min, int max, int *visitados) {
    (void)r; // apague estas quatro linhas
    (void)min;
    (void)max;
    (void)visitados;
}

int main(void) {
    int precos[] = {50, 30, 70, 20, 40, 60, 80, 10, 90};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, precos[i]);
    }

    int visitados = 0;
    printf("Entre 35 e 65:");
    faixa(raiz, 35, 65, &visitados);
    printf("\nNós visitados: %d de 9\n", visitados);

    raiz = bst_libera(raiz);
    return 0;
}
