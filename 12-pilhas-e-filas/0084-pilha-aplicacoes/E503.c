// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E503 · ★★★
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
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pilha.h"

int main(void) {

    return 0;
}
