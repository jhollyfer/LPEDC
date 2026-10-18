// 0030 · Escopo e tempo de vida
// Exercício E175 · ★☆☆
//
// Preveja as cinco linhas, sem rodar:
//
//   int volume = 10;
//
//   void mostrar(void) {
//       printf("%d\n", volume);
//   }
//
//   int main(void) {
//       mostrar();
//       int volume = 25;
//       printf("%d\n", volume);
//       {
//           int volume = 40;
//           printf("%d\n", volume);
//       }
//       printf("%d\n", volume);
//       mostrar();
//       return 0;
//   }
//
// Dicas:
// 1. A função mostrar está fora do main: ela não enxerga nenhuma variável do main.
// 2. Vale a declaração mais próxima; o bloco interno acaba no "}".
// 3. Resposta esperada: 10, 25, 40, 25, 10.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
