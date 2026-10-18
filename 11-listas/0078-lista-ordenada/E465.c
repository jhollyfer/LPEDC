// 0078 · Lista ordenada
// Exercício E465 · ★★☆
//
// O entregador anotou os números das casas da rua, com repetidos: 5, 3, 5,
// 8, 3, 3, 1. Insira tudo em ordem e escreva
//
//   int remove_repetidos(No *inicio)
//
// que deixa um só de cada número e devolve quantos nós tirou.
//
//   Saída esperada:
//   antes:  1 -> 3 -> 3 -> 3 -> 5 -> 5 -> 8 -> NULL
//   depois: 1 -> 3 -> 5 -> 8 -> NULL
//   3 repetidos removidos
//
// Dicas:
// 1. Na lista ordenada, os repetidos ficam VIZINHOS: basta comparar p com
//    p->prox.
// 2. Se p->valor == p->prox->valor, tire o p->prox (religue e dê free) e NÃO
//    avance o p: pode haver um terceiro igual.
// 3. Por que a função não precisa de No **? O primeiro nó nunca sai: quando
//    há repetidos, sai sempre o de trás.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {

    return 0;
}
