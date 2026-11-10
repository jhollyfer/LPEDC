// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E499 · ★☆☆
//
// Escreva bool avalia(const char *expr, int *resultado), que calcula uma
// expressão pós-fixa (inteiros não negativos e + - * /, separados por espaço)
// com uma pilha do pilha.h; devolve false se a expressão for inválida (faltam
// operandos, sobram valores ou divide por zero). Traduza à mão para pós-fixa
// a) (7 + 3) * 2, b) 7 + 3 * 2, c) 100 / (2 + 3) - 4 e d) (6 / 2) * (3 - 1).
// No main, avalie cada uma e mostre o resultado ao lado do valor da mesma conta
// escrita direto em C, com "confere" ou "NÃO confere".
//
//   Saída esperada:
//   7 3 + 2 * = 20 (em C: 20) confere
//   7 3 2 * + = 13 (em C: 13) confere
//   100 2 3 + / 4 - = 16 (em C: 16) confere
//   6 2 / 3 1 - * = 6 (em C: 6) confere
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

int main(void) {

    return 0;
}
