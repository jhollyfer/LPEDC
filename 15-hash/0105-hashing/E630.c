// 0105 · A ideia e a função hash
// Exercício E630 · ★★★
//
// O compilador precisa reconhecer as palavras reservadas o tempo todo. Para
// um conjunto fixo de chaves, dá para achar uma tabela sem nenhuma colisão:
// um hash "perfeito". Com o hash polinomial de base 31 (h = h * 31 + byte,
// em unsigned), descubra o MENOR m, a partir de 8, em que as 8 palavras
// abaixo caem em baldes todos diferentes:
//
//   int  char  if  else  for  while  return  void
//
// Mostre o m encontrado e o balde de cada palavra.
//
//   Saída esperada (formato):
//   m = ...
//   int -> ...
//   char -> ...
//
// Dicas:
// 1. Calcule o hash polinomial completo uma vez (sem o resto) e guarde num
//    vetor de unsigned; o resto por m muda a cada tentativa.
// 2. Para testar um m: um vetor "bool usado[64]" zerado; se algum balde já
//    estiver usado, esse m não serve.
// 3. Resposta esperada: m = 14, com int -> 5, char -> 10, if -> 11,
//    else -> 1, for -> 7, while -> 13, return -> 4, void -> 8. (Com a soma
//    dos códigos, o menor m seria 18.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
