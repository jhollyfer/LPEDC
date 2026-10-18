// 0053 · Pilha e heap
// Exercício E317 · ★★★
//
// Preveja a saída SEM rodar. Depois rode e confira.
//
//   int contador = 100;
//   
//   int passo(int n) {
//       static int chamadas = 0;
//       int local = 0;
//       chamadas++;
//       local++;
//       contador--;
//       if (n > 0) {
//           passo(n - 1);
//       }
//       return chamadas * 10 + local;
//   }
//   
//   int main(void) {
//       printf("%d\n", passo(3));
//       printf("%d\n", passo(0));
//       printf("%d\n", contador);
//       return 0;
//   }
//
// Explique cada número pensando em onde mora cada variável.
//
// Dicas:
// 1. passo(3) gera 4 frames: n = 3, 2, 1 e 0. Cada um tem a sua local.
// 2. chamadas é uma só para todos os frames. Quando o primeiro frame chega ao
//    return, as chamadas de dentro já terminaram.
// 3. Resposta esperada: 41, 51 e 95. No return do primeiro passo(3),
//    chamadas já vale 4 e a local daquele frame vale 1 (cada frame tem a sua):
//    41. passo(0) é a 5ª chamada: 51. contador foi decrementado 5 vezes: 95.
//
// Escreva sua resposta abaixo (como comentário) e depois copie o código para
// conferir:

#include <stdio.h>

int main(void) {

    return 0;
}
