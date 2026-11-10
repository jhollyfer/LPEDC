// 0044 · Memória e endereços
// Exercício E263 · ★★★
//
// Variáveis declaradas juntas ficam juntas na memória? Escreva um programa
// que declare
//
//   int a = 1, b = 2, c = 3;
//   int v[3] = {1, 2, 3};
//
// e mostre o endereço de a, b e c (uma linha cada) e depois, com um for, o
// endereço de v[0], v[1] e v[2]. No fim, mostre sizeof v e a soma
// sizeof a + sizeof b + sizeof c. Rode com o rodar. Depois compile SEM o
// sanitizer e rode de novo, para comparar as duas saídas:
//
//   gcc -std=c17 E263.c -o e263 && ./e263
//
//   Saída esperada (endereços mudam a cada execução; com o rodar):
//   a em 0x7f...30
//   b em 0x7f...40
//   c em 0x7f...50
//   v[0] em 0x7f...60
//   v[1] em 0x7f...64
//   v[2] em 0x7f...68
//   sizeof v = 12, a + b + c = 12
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
