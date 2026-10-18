// 0023 · Break e continue
// Exercício E134 · ★☆☆
//
// Preveja a saída antes de rodar:
//
//   for (int i = 1; i <= 10; i++) {
//       if (i % 4 == 0) {
//           continue;
//       }
//       if (i == 7) {
//           break;
//       }
//       printf("%d ", i);
//   }
//   printf("\n");
//
// E se você trocar a ordem dos dois if, muda alguma coisa? E se o break
// testasse i == 8?
//
// Dicas:
// 1. continue pula só esta volta; break acaba com o laço.
// 2. O 4 é pulado. Quem chega primeiro no 7: o continue ou o break?
// 3. Resposta esperada: "1 2 3 5 6". Trocar a ordem dos if não muda nada
//    aqui (7 não é múltiplo de 4). Com i == 8, o break nunca acontece, porque
//    o continue pega o 8 antes: a saída vira "1 2 3 5 6 7 9 10".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
