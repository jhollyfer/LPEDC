// 0064 · Union
// Exercício E379 · ★☆☆
//
// Escreva um programa que declare os três tipos abaixo e mostre o sizeof de
// cada um. Para a union Caixa e a struct Ficha, mostre também onde cada campo
// começa (offsetof): é a diferença entre as duas, em números.
//
//   union Caixa  { char c; int i; double d; };
//   struct Ficha { char c; int i; double d; };
//   union Nome   { char texto[10]; int codigo; };
//
//   Saída esperada (num PC de 64 bits):
//   union Caixa: 8 bytes, campos em 0, 0 e 0
//   struct Ficha: 16 bytes, campos em 0, 4 e 8
//   union Nome: 12 bytes
//
// Dicas:
// 1. offsetof(union Caixa, i) também funciona com union; está em
//    <stddef.h> e se mostra com %zu.
// 2. Union: o tamanho do maior campo, arredondado para um múltiplo do
//    alinhamento do campo mais exigente. Struct: os campos em sequência, com
//    sobras de alinhamento (assunto 0059).
// 3. Resposta esperada: a saída acima. A union Nome tem 12 bytes, não 10:
//    o int pede um tamanho múltiplo de 4.
//
// Escreva sua resposta abaixo:

#include <stddef.h>
#include <stdio.h>

int main(void) {

    return 0;
}
