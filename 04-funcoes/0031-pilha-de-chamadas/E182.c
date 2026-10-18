// 0031 · A pilha de chamadas
// Exercício E182 · ★☆☆
//
// Preveja a ordem exata das linhas na tela:
//
//   void c(void) {
//       printf("c\n");
//   }
//
//   void b(void) {
//       printf("b começa\n");
//       c();
//       printf("b termina\n");
//   }
//
//   void a(void) {
//       printf("a começa\n");
//       b();
//       c();
//       printf("a termina\n");
//   }
//
//   int main(void) {
//       a();
//       c();
//       return 0;
//   }
//
// Qual é o número máximo de quadros na pilha ao mesmo tempo, contando o main?
//
// Dicas:
// 1. Uma função só continua depois que a função que ela chamou retornou.
// 2. O ponto mais fundo é main -> a -> b -> c.
// 3. Resposta esperada: a começa / b começa / c / b termina / c / a termina /
//    c. No máximo 4 quadros.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
