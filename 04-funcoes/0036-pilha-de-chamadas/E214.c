// 0036 · A pilha de chamadas
// Exercício E214 · ★★☆
//
// Cada quadro tem as suas variáveis, mesmo com nomes iguais. Preveja a saída e
// monte uma tabela com o valor de cada "n" e cada "r" em cada quadro.
//
//   int dobro_mais_um(int n) {
//       int r = n * 2;
//       n = r + 1;
//       return n;
//   }
//
//   int processa(int n) {
//       int r = dobro_mais_um(n);
//       printf("processa: n = %d, r = %d\n", n, r);
//       return r + n;
//   }
//
//   int main(void) {
//       int n = 5;
//       int r = processa(n);
//       printf("main: n = %d, r = %d\n", n, r);
//       return 0;
//   }
//
// Dicas:
// 1. Em dobro_mais_um, n vira 11, mas é o n do quadro dela.
// 2. processa continua com n = 5 e recebe r = 11.
// 3. Resposta esperada: "processa: n = 5, r = 11" e "main: n = 5, r = 16".
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
