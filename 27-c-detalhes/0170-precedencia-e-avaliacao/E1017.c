// 0170 · Precedência e ordem de avaliação
// Exercício E1017 · ★★☆
//
// Escreva as duas funções abaixo, que fazem o trabalho de x++ e ++x
// recebendo o endereço da variável:
//
//   int pos_incremento(int *p)  // devolve o valor antigo, depois soma 1
//   int pre_incremento(int *p)  // soma 1, depois devolve o valor novo
//
// No main, comece com a = 5, calcule b = a++ * 2 e c = ++a * 2 com os
// operadores e mostre a linha "com ++". Refaça as mesmas contas com as
// suas funções, em a2, b2 e c2, e mostre a linha "com funcoes".
//
//   Saída esperada:
//   com ++:      a = 7, b = 10, c = 14
//   com funcoes: a = 7, b = 10, c = 14
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int pos_incremento(int *p);
int pre_incremento(int *p);

int main(void) {

    return 0;
}
