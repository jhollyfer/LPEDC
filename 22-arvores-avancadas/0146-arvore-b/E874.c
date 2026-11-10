// 0146 · Árvore B
// Exercício E874 · ★★☆
//
// A contabilidade quer as notas fiscais de uma faixa de números. Escreva
// intervalo(r, a, b, &visitados): mostra, em ordem crescente, as chaves de
// a até b e conta quantos nós foram lidos. Não leia subárvores que não podem
// ter chave na faixa. A árvore é a mesma do exemplo A292 (9 nós).
//
//   Saída esperada:
//   notas de 300 a 700: 340 401 445 512 610 678 (7 nós lidos de 9)
//   notas de 100 a 160: 118 150 (3 nós lidos de 9)
//   notas de 970 a 999: (3 nós lidos de 9)
//
// Escreva sua resposta abaixo (escreva intervalo e complete o main):

#include <stdio.h>
#include "arvoreb.h"

int main(void) {
    int notas[] = {512, 87, 340, 905, 23, 678, 150, 401, 799, 266, 33, 960, 610, 445, 118};
    NoB *r = NULL;
    for (int i = 0; i < 15; i++) {
        r = ab_insere(r, notas[i]);
    }

    r = ab_libera(r);
    return 0;
}
