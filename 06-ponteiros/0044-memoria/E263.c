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
// Dicas:
// 1. Compare só os últimos dígitos hexa de cada endereço.
// 2. O AddressSanitizer coloca "zonas proibidas" entre as variáveis para
//    pegar estouros; sem ele, o compilador arruma do jeito que quiser.
// 3. Resposta esperada: v[0], v[1] e v[2] sobem de 4 em 4 nas duas
//    compilações; a, b e c ficam a 16 bytes um do outro com o rodar e
//    costumam ficar a 4 bytes sem ele, em qualquer ordem. Os dois tamanhos
//    dão 12: o mesmo espaço, mas só o vetor tem ordem garantida.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
