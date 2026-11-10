// Lista · Módulo 12 · Pilhas e filas
// Exercício P1228 · ★★★ · A calculadora da HP (RPN com comandos)
//
// As calculadoras HP usam notação pós-fixa (RPN) e alguns comandos de
// pilha. Escreva
//
//   int executa(const char *programa, double *resultado, char *erro)
//
// que lê os itens separados por espaço (números reais, + - * / e os
// comandos dup, swap e drop), usa uma pilha de double sobre vetor e, no
// fim, exige que sobre exatamente um número. Devolve 1 se deu certo, ou 0
// e uma mensagem em erro.
//
//   dup: duplica o topo     swap: troca os dois de cima     drop: descarta o topo
//
//   Saída esperada:
//   3 4 + 2 * => 14
//   5 dup * => 25
//   10 2 swap - => -8
//   1 2 3 drop + => 3
//   1.5 2.5 + 2 / => 2
//   4 0 / => erro: divisão por zero
//   2 + => erro: faltam operandos
//   7 8 => erro: sobraram 2 números
//
// Dicas:
// 1. Separe os itens com um laço que copia os caracteres até o próximo
//    espaço (ou o '\0') para um vetor char item[32].
// 2. É número se começa com dígito, ou com '-' ou '.' seguido de dígito;
//    converta com atof. Compare os comandos com strcmp.
// 3. Antes de cada operação, confira se a pilha tem itens suficientes: 2
//    para + - * / e swap, 1 para dup e drop.
// 4. Mostre o resultado com "%g". Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
