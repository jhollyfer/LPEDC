// 0026 · Do-while
// Exercício E152 · ★☆☆
//
// Os dois trechos são quase iguais. Preveja o que cada um mostra e depois
// rode para conferir.
//
//   // trecho A
//   int n = 10;
//   while (n < 5) {
//       printf("%d ", n);
//       n++;
//   }
//   printf("| A terminou com n = %d\n", n);
//
//   // trecho B
//   int m = 10;
//   do {
//       printf("%d ", m);
//       m++;
//   } while (m < 5);
//   printf("| B terminou com m = %d\n", m);
//
// Depois responda: para o trecho A se comportar como o B, o que você teria
// que acrescentar antes do while?
//
// Dicas:
// 1. O while pergunta antes de entrar; o do-while entra e pergunta depois.
// 2. 10 < 5 é falso logo na primeira pergunta.
// 3. Resposta esperada: A mostra "| A terminou com n = 10" (zero voltas);
//    B mostra "10 | B terminou com m = 11" (uma volta, mesmo com a condição
//    falsa). Para o while imitar o do-while, é preciso copiar o corpo uma vez
//    antes do laço.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
