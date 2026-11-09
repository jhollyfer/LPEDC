// 0166 · O, Ω e Θ de verdade
// Exercício E991 · ★☆☆
//
// O sistema do condomínio gera os boletos de n condôminos com
// f(n) = 5n + 40 passos. Prove, com um programa, que f(n) é O(n): escreva
// a função custo(n) e uma função acha_n0(c) que testa todo n de 1 até
// 10000 e devolve o menor n0 a partir do qual custo(n) <= c * n sempre
// vale. Mostre o n0 para c = 6, 7, 10 e 45:
//
//   Saída esperada:
//   c =  6: n0 = 40
//   c =  7: n0 = 20
//   c = 10: n0 = 8
//   c = 45: n0 = 1
//
// Dicas:
// 1. Comece com n0 = 1. Toda vez que custo(n) > c * n, faça n0 = n + 1:
//    o n0 tem que ficar depois da última falha.
// 2. Use long para n, custo e c * n.
// 3. Confira à mão: 5n + 40 <= 6n vira n >= 40. Quanto maior o c, menor o
//    n0; com c = 45, já vale em n = 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
