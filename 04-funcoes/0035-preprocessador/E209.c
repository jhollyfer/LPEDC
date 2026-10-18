// 0035 · Pré-processador: macros e #ifdef
// Exercício E209 · ★★★
//
// A macro avalia o argumento cada vez que ele aparece. Preveja a saída:
//
//   #define MAIOR(a, b) ((a) > (b) ? (a) : (b))
//
//   int chamadas = 0;
//
//   int pontos(int p) {
//       chamadas++;
//       return p;
//   }
//
//   int maior(int a, int b) {
//       return a > b ? a : b;
//   }
//
//   int main(void) {
//       int x = 5;
//       int y = 3;
//       int m = MAIOR(x++, y);
//       printf("m = %d, x = %d\n", m, x);
//
//       x = 5;
//       m = maior(x++, y);
//       printf("m = %d, x = %d\n", m, x);
//
//       m = MAIOR(pontos(40), pontos(25));
//       printf("m = %d, chamadas = %d\n", m, chamadas);
//
//       chamadas = 0;
//       m = maior(pontos(40), pontos(25));
//       printf("m = %d, chamadas = %d\n", m, chamadas);
//       return 0;
//   }
//
// Dicas:
// 1. Expanda MAIOR(x++, y) à mão: ((x++) > (y) ? (x++) : (y)). Quantos x++
//    rodam quando a comparação é verdadeira?
// 2. Na função, o argumento x++ é avaliado uma vez, antes da chamada.
// 3. Resposta esperada: m = 6, x = 7 / m = 5, x = 6 / m = 40, chamadas = 3 /
//    m = 40, chamadas = 2. (No primeiro, x++ compara 5, vira 6; o segundo x++
//    devolve 6 e vira 7.)
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
