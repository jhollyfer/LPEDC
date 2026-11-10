// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E523 · ★☆☆
//
// Uma calculadora de expressões em duas etapas. Etapa 1, à mão: converta 2 * (3 + 4)
// e 2 * 3 + 4 para pós-fixa e insira os itens em duas filas do fila.h (operadores
// como códigos negativos do enum abaixo). Etapa 2: escreva bool avalia(Fila
// *posfixa, int *resultado), que consome a fila com uma pilha do pilha.h,
// mostrando cada item seguido de um espaço, e devolve false se a fila for
// inválida. No main, mostre a infixa, a pós-fixa e o resultado de cada conta.
//
//   Saída esperada:
//   2 * (3 + 4) -> 2 3 4 + * = 14
//   2 * 3 + 4 -> 2 3 * 4 + = 10
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4 };

int main(void) {

    return 0;
}
