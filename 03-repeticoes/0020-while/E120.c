// 0020 · While
// Exercício E120 · ★★★
//
// Preveja o que cada trecho mostra ANTES de rodar. Depois cole cada um no main
// e confira.
//
//   // trecho A
//   int i = 0;
//   while (i++ < 5) {
//       printf("%d ", i);
//   }
//   printf("| %d\n", i);
//
//   // trecho B
//   int n = 100, voltas = 0;
//   while (n > 1) {
//       n = n / 3;
//       voltas++;
//   }
//   printf("%d %d\n", n, voltas);
//
//   // trecho C
//   int k = 10;
//   while (k < 10) {
//       k++;
//   }
//   printf("%d\n", k);
//
// Dicas:
// 1. Trecho A: i++ compara o valor ANTIGO e só depois soma 1 (assunto 0009).
//    Isso vale também na última pergunta, a que dá falso.
// 2. Trecho B: divisão inteira. 100 / 3 = 33.
// 3. Resposta esperada: A mostra "1 2 3 4 5 | 6" (a pergunta falsa, 5 < 5,
//    ainda soma 1); B mostra "1 4" (100, 33, 11, 3, 1); C mostra "10": o
//    corpo roda zero vezes, porque o while pergunta antes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
