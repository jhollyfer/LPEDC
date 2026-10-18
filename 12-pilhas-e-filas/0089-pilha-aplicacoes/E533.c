// 0089 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E533 · ★★★
//
// Escreva void para_posfixa(const char *in, char *out), que converte uma
// expressão infixa com operandos de UM dígito, + - * / e parênteses para a
// notação pós-fixa, com um espaço entre os símbolos. Use a pilha do pilha.h
// para guardar os operadores e os "(". As regras (o algoritmo do
// "pátio de manobras", de Dijkstra):
//
// - dígito: vai direto para a saída;
// - "(": empilha;
// - ")": desempilha para a saída até achar o "(", que é descartado;
// - operador: enquanto o topo for um operador de precedência MAIOR OU IGUAL,
// desempilha para a saída; depois empilha o operador;
// - fim da entrada: desempilha tudo o que sobrou para a saída.
//
//   Saída esperada:
//   1+2*3 -> 1 2 3 * +
//   (6+2)*5-8/4 -> 6 2 + 5 * 8 4 / -
//   (1+2)*(3-4) -> 1 2 + 3 4 - *
//   9-4-2 -> 9 4 - 2 -
//
// Dicas:
// 1. Uma função int precedencia(int op): 2 para * e /, 1 para + e -, 0 para
//    "(" (assim o "(" nunca sai por causa de um operador).
// 2. Monte a saída com um índice: out[k++] = c; out[k++] = ' '; e no fim
//    troque o último espaço por '\0'.
// 3. O "maior ou igual" é o que faz 9-4-2 virar (9-4)-2, e não 9-(4-2).
// 4. Resposta esperada: as quatro linhas acima. Confira a segunda no A178
//    (troque os números): o valor de (6+2)*5-8/4 é 38.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pilha.h"

int main(void) {

    return 0;
}
