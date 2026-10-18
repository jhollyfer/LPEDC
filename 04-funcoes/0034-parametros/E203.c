// 0034 · Parâmetros e passagem por valor
// Exercício E203 · ★★★
//
// Preveja a saída. Atenção às conversões: cada argumento é convertido para o
// tipo do parâmetro, e o valor do return é convertido para o tipo da função.
//
//   int metade(int x) {
//       return x / 2;
//   }
//
//   double media(int a, int b) {
//       return (a + b) / 2;
//   }
//
//   double media_certa(double a, double b) {
//       return (a + b) / 2;
//   }
//
//   int main(void) {
//       printf("%d\n", metade(7.9));
//       printf("%.1f\n", media(7, 8));
//       printf("%.1f\n", media_certa(7, 8));
//       printf("%d\n", metade(metade(31) + 1));
//       return 0;
//   }
//
// Dicas:
// 1. 7.9 entra num parâmetro int: a parte decimal é cortada antes da conta.
// 2. Em media, a e b são int: a divisão (a + b) / 2 é inteira. Só depois o
//    resultado vira double.
// 3. Resposta esperada: 3, 7.0, 7.5 e 8. (metade(31) = 15; 15 + 1 = 16;
//    metade(16) = 8.)
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
