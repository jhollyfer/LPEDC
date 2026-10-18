// 0022 · For
// Exercício E132 · ★★★
//
// O laço abaixo usa a vírgula para controlar duas variáveis. Escreva um
// programa que roda esse laço e, logo depois, o MESMO laço reescrito com
// while, com a mesma saída. Nos dois, acrescente um contador de voltas e
// mostre-o na linha do "Fim":
//
//   int i, j;
//   for (i = 0, j = 20; i < j; i += 3, j -= 2) {
//       printf("i = %2d, j = %2d\n", i, j);
//   }
//   printf("Fim: i = %d, j = %d\n", i, j);
//
//   Saída esperada (a do for; a do while vem logo depois, igual):
//   i =  0, j = 20
//   i =  3, j = 18
//   i =  6, j = 16
//   i =  9, j = 14
//   Fim: i = 12, j = 12, voltas = 4
//
// Dicas:
// 1. A vírgula separa duas inicializações e dois passos; a condição é uma só.
// 2. No while, as inicializações vão antes do laço e os dois passos vão no
//    FIM do corpo, depois do printf. Zere o contador antes de cada laço.
// 3. Resposta esperada: 4 linhas e "Fim: i = 12, j = 12, voltas = 4", duas
//    vezes. Com while: i = 0; j = 20; while (i < j) { printf(...);
//    voltas++; i += 3; j -= 2; }.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
