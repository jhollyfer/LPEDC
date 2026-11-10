// 0040 · Caracteres
// Exercício E240 · ★★★
//
// Reescreva cinco funções do ctype.h usando só a tabela ASCII (nada de
// ctype.h dentro delas):
//
//   bool meu_isdigit(int c);
//   bool meu_isupper(int c);
//   bool meu_islower(int c);
//   bool meu_isalpha(int c);   use as duas anteriores
//   int meu_toupper(int c);    devolve c igual se não for minúscula
//
// Depois, prove que estão certas: para TODOS os códigos de 0 a 127, compare
// cada uma com a original do ctype.h e conte as diferenças. Atenção: a
// original devolve "diferente de zero" para verdadeiro, não 1. Compare a
// verdade, não o número.
//
//   Saída esperada:
//   meu_toupper('q') = Q
//   meu_toupper('7') = 7
//   Diferenças em 128 códigos: 0
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
