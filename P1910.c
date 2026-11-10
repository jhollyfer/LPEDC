// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1910 · ★☆☆ · Três dígitos que somam 15
//
// No kakuro da revista de passatempos, uma faixa de 3 casas precisa somar
// 15 com dígitos de 1 a 9, todos diferentes. Que trincas servem? Escreva do
// zero um backtracking que escolhe os dígitos em ordem crescente (cada um
// maior que o anterior, assim a mesma trinca não aparece duas vezes) e
// corta o ramo quando a soma passa de 15. Mostre as trincas e o total.
//
//   Saída esperada:
//   1 5 9
//   1 6 8
//   2 4 9
//   2 5 8
//   2 6 7
//   3 4 8
//   3 5 7
//   4 5 6
//   Total: 8 trincas
//
// Dicas:
// 1. escolhe(menor, k, soma): tenta os dígitos d de menor a 9; se soma + d
//    > 15, pode dar break (os próximos são maiores ainda).
// 2. Com k == 3, só mostre se soma == 15.
// 3. Resposta esperada: 8 trincas, de 1 5 9 até 4 5 6.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
