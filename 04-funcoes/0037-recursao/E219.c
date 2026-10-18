// 0037 · Recursão
// Exercício E219 · ★★☆
//
// Preveja a saída, linha por linha:
//
//   void eco(int n) {
//       if (n == 0) {
//           printf("fundo\n");
//           return;
//       }
//       printf("ida %d\n", n);
//       eco(n - 1);
//       printf("volta %d\n", n);
//   }
//
//   int main(void) {
//       eco(3);
//       return 0;
//   }
//
// Dicas:
// 1. O printf da volta só roda depois que a chamada de dentro terminou.
// 2. Cada quadro lembra o seu n: o de eco(3) ainda vale 3 na volta.
// 3. Resposta esperada: ida 3 / ida 2 / ida 1 / fundo / volta 1 / volta 2 /
//    volta 3.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
