// 0069 · Union
// Exercício E409 · ★☆☆
//
// Num PC de 64 bits, preveja os três sizeof e depois confira com um
// programa:
//
//   union Caixa  { char c; int i; double d; };
//   struct Ficha { char c; int i; double d; };
//   union Nome   { char texto[10]; int codigo; };
//
// Dicas:
// 1. Union: o tamanho do maior campo, arredondado para um múltiplo do
//    alinhamento do campo mais exigente.
// 2. Struct: os campos em sequência, com sobras de alinhamento (assunto 0064).
// 3. Resposta esperada: union Caixa = 8; struct Ficha = 16 (c em 0, i em 4,
//    d em 8); union Nome = 12 (10 bytes de texto, arredondados para múltiplo
//    de 4 por causa do int).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
