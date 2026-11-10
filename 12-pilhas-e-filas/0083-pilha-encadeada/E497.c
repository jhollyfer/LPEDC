// 0083 · Pilha encadeada
// Exercício E497 · ★★★
//
// Os pedidos da cozinha chegaram empilhados fora de ordem: 5, 3, 8, 1 e 4 (o
// 4 no topo). Escreva void ordena(Pilha *p), que deixa a pilha ordenada com o
// MENOR no topo, usando só as funções do pilha.h e no máximo UMA pilha
// auxiliar (nada de vetor). Depois o main desempilha e mostra tudo.
//
//   Saída esperada:
//   1 3 4 5 8
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int pedidos[] = {5, 3, 8, 1, 4};
    for (int i = 0; i < 5; i++) {
        pilha_empilha(p, pedidos[i]);
    }

    // ordena(p);

    int x;
    while (pilha_desempilha(p, &x)) {
        printf("%d ", x);
    }
    printf("\n");
    pilha_libera(p);
    return 0;
}
