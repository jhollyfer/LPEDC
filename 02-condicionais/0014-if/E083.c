// 0014 · if
// Exercício E083 · ★★★
//
// Preveja a saída deste trecho. O recuo foi feito para enganar: o compilador
// não olha os espaços. Escreva a resposta e só depois teste (vão aparecer
// avisos, e eles dão pistas).
//
//   int n = 7;
//   if (n > 10)
//       printf("grande ");
//       printf("sete ");
//   if (n % 2)
//       printf("ímpar ");
//   if (!(n - 7))
//       printf("igual ");
//   if (n & 1 == 0)
//       printf("par ");
//   printf("fim\n");
//
// Dicas:
// 1. Sem chaves, cada if manda só na primeira instrução depois dele.
// 2. n % 2 vale 1 (verdade). n - 7 vale 0, e !0 vale 1. E o == vem antes
//    do & (reveja o WARNING do 0013).
// 3. Resposta esperada: sete ímpar igual fim
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
