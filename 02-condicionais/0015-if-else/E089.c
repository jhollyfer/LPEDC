// 0015 · if/else e o = no lugar do ==
// Exercício E089 · ★★★
//
// Preveja a saída deste trecho. Depois troque "b = 2" por "b == 2" e preveja
// de novo. Só então rode as duas versões.
//
//   int a = 3, b = 0;
//   if (b = 2) {
//       if (a == 2) {
//           printf("X ");
//       } else {
//           printf("Y ");
//       }
//   } else {
//       printf("Z ");
//   }
//   printf("%d %d\n", a, b);
//
// Dicas:
// 1. Com um sinal só, b recebe 2 e o if testa o 2.
// 2. Com dois sinais, o if compara 0 com 2 e b não muda.
// 3. Resposta esperada: com "b = 2" mostra "Y 3 2"; com "b == 2" mostra
//    "Z 3 0".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
