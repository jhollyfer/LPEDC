// 0170 · Precedência e ordem de avaliação
// Exercício E1016 · ★☆☆
//
// Escreva um programa que mostre, para cada expressão abaixo, o valor dela
// como está e o valor da mesma conta com todos os parênteses no jeito que o
// C agrupa. Os dois números de cada linha têm que bater. Para as duas
// últimas, que são atribuições, mostre as variáveis depois da instrução.
//
//   100 / 10 / 5      2 - 3 - 4      2 * 3 % 4
//   a = b = c = 7     x = 5; x -= 1 + 2
//
//   Saída esperada:
//   100 / 10 / 5 = 2   ((100 / 10) / 5) = 2
//   2 - 3 - 4 = -5   ((2 - 3) - 4) = -5
//   2 * 3 % 4 = 2   ((2 * 3) % 4) = 2
//   a = b = c = 7 -> a = 7, b = 7, c = 7
//   x -= 1 + 2 -> x = 2
//
// Dicas:
// 1. *, / e % estão no mesmo nível e agrupam da esquerda para a direita.
// 2. A atribuição agrupa da direita: a = (b = (c = 7)).
// 3. x -= 1 + 2 é x = x - (1 + 2), não x = x - 1 + 2.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
