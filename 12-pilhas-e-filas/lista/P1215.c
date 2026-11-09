// Lista · Módulo 12 · Pilhas e filas
// Exercício P1215 · ★★☆ · Avaliar a notação PREfixa
//
// Na notação prefixa (a polonesa original), o operador vem ANTES dos
// operandos: "+ 9 * 2 3" é 9 + (2 * 3). Ela também dispensa parênteses e
// também se avalia com uma pilha, só que lendo a expressão da DIREITA para
// a ESQUERDA. Escreva
//
//   int avalia_prefixa(const char *s, int *resultado)
//
// para operandos de um dígito, operadores + - * / e espaços entre os
// itens. Devolve 1 se deu certo ou 0 se a expressão é inválida (faltou
// operando, sobrou operando ou divisão por zero).
//
//   Saída esperada:
//   + 9 * 2 3 = 15
//   - * 5 6 / 8 2 = 26
//   * + 1 2 + 3 4 = 21
//   - 8 3 = 5
//   + 1: inválida
//   / 7 0: inválida
//
// Dicas:
// 1. Da direita para a esquerda: dígito, empilha. Operador: desempilha a
//    (o PRIMEIRO a sair é o operando da esquerda!) e depois b, e empilha
//    a op b.
// 2. É o contrário da pós-fixa, onde o primeiro que sai é o da direita.
//    Com "- 8 3", o 3 é empilhado antes do 8, então o 8 sai primeiro.
// 3. No fim, a expressão é válida se sobrou exatamente 1 item.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
