// 0170 · Precedência e ordem de avaliação
// Exercício E1017 · ★★☆
//
// Para entender de vez o x++ e o ++x, escreva duas funções que fazem o
// mesmo trabalho que eles, recebendo o endereço da variável:
//
//   int pos_incremento(int *p)  // devolve o valor antigo, depois soma 1
//   int pre_incremento(int *p)  // soma 1, depois devolve o valor novo
//
// O main já calcula b e c com os operadores. Refaça as mesmas contas com as
// suas funções, em variáveis a2, b2 e c2, e mostre as duas linhas.
//
//   Saída esperada:
//   com ++:      a = 7, b = 10, c = 14
//   com funcoes: a = 7, b = 10, c = 14
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int a = 5;
    int b = a++ * 2;
    int c = ++a * 2;
    printf("com ++:      a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
