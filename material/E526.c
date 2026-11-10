// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E526 · ★★☆
//
// Calculadora enxuta (operandos de um dígito, + - * /, sem parênteses). Com uma
// pilha do pilha.h e uma fila do fila.h, escreva void converte(const char *s,
// Fila *saida), que passa a infixa para a pós-fixa (guardando os caracteres na
// fila), e int avalia(Fila *posfixa), que consome a fila, mostra cada item
// seguido de um espaço e devolve o resultado. Operadores de mesma precedência
// associam à esquerda. No main, para "2+3*4", "8-3-2" e "9/3/3", mostre a conta,
// a pós-fixa e o resultado.
//
//   Saída esperada:
//   2+3*4 -> 2 3 4 * + = 14
//   8-3-2 -> 8 3 - 2 - = 3
//   9/3/3 -> 9 3 / 3 / = 1
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0088-fila.h"
#include "0088-pilha.h"

int main(void) {

    return 0;
}
