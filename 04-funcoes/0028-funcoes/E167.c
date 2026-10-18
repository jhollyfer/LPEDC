// 0028 · Funções
// Exercício E167 · ★★★
//
// Sem rodar, preveja a saída. Depois rode e confira.
//
//   int dobro(int n) {
//       return 2 * n;
//       printf("nunca aparece\n");
//   }
//
//   int ajusta(int n) {
//       if (n > 10) {
//           return n - 10;
//       }
//       if (n % 2 == 0) {
//           return n / 2;
//       }
//       return n + 1;
//   }
//
//   int main(void) {
//       printf("%d\n", ajusta(7));
//       printf("%d\n", ajusta(dobro(7)));
//       printf("%d\n", dobro(ajusta(8)) + ajusta(dobro(3)));
//       printf("%d\n", ajusta(ajusta(ajusta(30))));
//       return 0;
//   }
//
// Dicas:
// 1. Resolva de dentro para fora: ajusta(dobro(7)) é ajusta(14).
// 2. Em ajusta, o primeiro return que for alcançado encerra a função: os
//    testes de baixo nem são feitos.
// 3. Resposta esperada: 8, 4, 11 e 5. (ajusta(8) = 4 e dobro(4) = 8;
//    dobro(3) = 6 e ajusta(6) = 3; 8 + 3 = 11. ajusta(30) = 20,
//    ajusta(20) = 10, ajusta(10) = 5.) O printf depois do return nunca roda.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
