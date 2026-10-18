// 0035 · Escopo e tempo de vida
// Exercício E209 · ★★★
//
// Teste de mesa caprichado: preveja as linhas, na ordem.
//
//   int x = 10;
//
//   void a(void) {
//       int x = 1;
//       printf("a: %d", x);
//       x++;
//       printf(" -> %d\n", x);
//   }
//
//   void b(void) {
//       static int x = 5;
//       printf("b: %d", x);
//       x += 5;
//       printf(" -> %d\n", x);
//   }
//
//   void c(void) {
//       printf("c: %d", x);
//       x *= 2;
//       printf(" -> %d\n", x);
//   }
//
//   int main(void) {
//       int x = 20;
//       printf("main: %d\n", x);
//       {
//           int x = 30;
//           printf("bloco: %d\n", x);
//       }
//       a(); b(); c();
//       a(); b(); c();
//       printf("main: %d\n", x);
//       return 0;
//   }
//
// Dicas:
// 1. São quatro x diferentes fora do bloco: a global, a do main, a local de a
//    e a static de b. Qual cada função enxerga?
// 2. A local de a recomeça em 1; a static de b continua de onde parou; c mexe
//    na global.
// 3. Resposta esperada: main: 20 / bloco: 30 / a: 1 -> 2 / b: 5 -> 10 /
//    c: 10 -> 20 / a: 1 -> 2 / b: 10 -> 15 / c: 20 -> 40 / main: 20.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
