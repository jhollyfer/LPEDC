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
