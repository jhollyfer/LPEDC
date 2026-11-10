// 0118 · Juntando tudo
// Exercício E705 · ★★☆
//
// O cadastro de 10 mil clientes está em ordem de código, mas poucas
// alterações bagunçam alguns vizinhos. Com o ordena.h, descubra qual das
// quatro ordenações é a melhor para esse vetor quase ordenado: base[i] = i (0
// a 9999); 50 trocas de base[i] com base[i + 1], i = sorteia() % (N - 1);
// para cada algoritmo, copie base para v, zere a contagem, ordene, confira
// com ord_confere e mostre as comparações. No fim, diga qual comparou menos.
//
//   Saída esperada:
//   insertion   10049 comparações
//   merge       64644 comparações
//   heap       244460 comparações
//   quick      113650 comparações
//   vencedor: insertion
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "ordena.h"

#define N 10000

unsigned semente = 3;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8);
}

int main(void) {

    return 0;
}
