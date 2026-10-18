// 0040 · Pré-processador: macros e #ifdef
// Exercício E235 · ★☆☆
//
// Para cada linha, escreva como o pré-processador expande a macro e o valor
// que o printf mostra. Só depois rode.
//
//   #define DOBRO(x) x + x
//   #define METADE(x) ((x) / 2)
//   #define TAXA 10
//
//   printf("%d\n", DOBRO(4));
//   printf("%d\n", 3 * DOBRO(4));
//   printf("%d\n", METADE(10 + 4));
//   printf("%d\n", 100 + TAXA * 2);
//
// Dicas:
// 1. Escreva a troca de texto literalmente, sem parênteses que não existem.
// 2. Depois aplique a precedência normal: * e / antes de + e -.
// 3. Resposta esperada: 4 + 4 = 8; 3 * 4 + 4 = 16 (e não 24); ((10 + 4) / 2)
//    = 7; 100 + 10 * 2 = 120.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
