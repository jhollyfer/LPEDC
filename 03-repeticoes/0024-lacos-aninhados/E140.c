// 0024 · Laços aninhados
// Exercício E140 · ★☆☆
//
// O par de laços abaixo já está no main do arquivo:
//
//   for (int i = 1; i <= 3; i++) {
//       for (int j = 1; j <= i; j++) {
//           printf("%d ", i * j);
//       }
//       printf("\n");
//   }
//
// Estenda o programa: acrescente um contador que soma 1 cada vez que o printf
// de dentro roda e, depois dos dois laços, mostre quantas vezes foi:
//
//   Saída esperada:
//   1
//   2 4
//   3 6 9
//   printf de dentro: 6 vezes
//
// Depois troque o limite do laço de fora para 4 e rode de novo.
//
// Dicas:
// 1. O contador começa em 0 antes dos laços e soma 1 logo depois do printf
//    de dentro, no mesmo nível dele.
// 2. Para cada i, o laço de dentro roda i vezes: 1, depois 2, depois 3.
// 3. Resposta esperada: a saída acima (1 + 2 + 3 = 6). Com i até 4, aparece a
//    linha "4 8 12 16" e o contador vai a 10.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    return 0;
}
