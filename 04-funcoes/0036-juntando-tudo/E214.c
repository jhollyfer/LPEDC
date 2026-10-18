// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E214 · ★★☆
//
// Tudo do módulo num programa só. Preveja a saída:
//
//   #define DOBRO(x) ((x) * 2)
//
//   int total = 0;
//
//   int proximo_id(void) {
//       static int id = 10;
//       id++;
//       return id;
//   }
//
//   int soma_ate(int n) {
//       total++;
//       if (n == 0) {
//           return 0;
//       }
//       return n + soma_ate(n - 1);
//   }
//
//   int altera(int total) {
//       total = 99;
//       return total;
//   }
//
//   int main(void) {
//       printf("%d\n", proximo_id());
//       printf("%d\n", proximo_id() + proximo_id());
//       printf("%d\n", soma_ate(4));
//       printf("%d\n", total);
//       altera(total);
//       printf("%d\n", DOBRO(total + 1));
//       return 0;
//   }
//
// Dicas:
// 1. id é static: 11, depois 12 e 13.
// 2. soma_ate(4) chama soma_ate 5 vezes (de 4 até 0), e cada uma soma 1 na global.
// 3. Resposta esperada: 11, 25, 10, 5, 12. O parâmetro total de altera esconde
//    a global: o 99 vai para a cópia, e o retorno é jogado fora.
//    DOBRO(5 + 1) = ((5 + 1) * 2) = 12.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
