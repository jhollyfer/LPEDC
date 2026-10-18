// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E224 · ★☆☆
//
// Quantos movimentos a Torre de Hanói precisa? Para mover n discos você move
// n - 1, depois 1, depois n - 1 de novo. Escreva
// "unsigned long long movimentos(int n)", recursiva, com movimentos(0) = 0, e
// mostre o resultado para 3, 10, 20 e 64 discos.
//
//   Saída esperada:
//   3 discos: 7
//   10 discos: 1023
//   20 discos: 1048575
//   64 discos: 18446744073709551615
//
// Dicas:
// 1. movimentos(n) = 2 * movimentos(n - 1) + 1. Repare: UMA chamada só, não duas.
// 2. O resultado para 64 é 2^64 - 1: não cabe em long long (que vai até
//    2^63 - 1), por isso o unsigned. Mostre com %llu.
// 3. Resposta esperada: 7, 1023, 1048575 e 18446744073709551615. A um
//    movimento por segundo, os 64 discos levariam uns 585 bilhões de anos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
