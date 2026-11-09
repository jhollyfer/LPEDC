// Lista · Módulo 15 · Tabelas hash
// Exercício P1510 · ★☆☆ · O método da multiplicação
//
// O método da MULTIPLICAÇÃO do Cormen calcula h(k) = ⌊m · (k · A mod 1)⌋:
// multiplica k por uma constante 0 < A < 1, fica só com a parte fracionária
// e multiplica por m. A vantagem: o m pode ser potência de 2 sem estragar a
// distribuição. Escreva int h_mult(int k) com m = 16 e A = 0.6180339887 (a
// sugestão de Knuth, (√5 - 1)/2) e compare com a divisão k % 16 para os
// códigos 100, 101, 102, 103, 200, 300, 1000, 1024.
//
//   Saída esperada:
//    100: divisão  4, multiplicação 12
//    101: divisão  5, multiplicação  6
//    102: divisão  6, multiplicação  0
//    103: divisão  7, multiplicação 10
//    200: divisão  8, multiplicação  9
//    300: divisão 12, multiplicação  6
//   1000: divisão  8, multiplicação  0
//   1024: divisão  0, multiplicação 13
//
// Dicas:
// 1. A parte fracionária de x (positivo) é x - (long)x.
// 2. Depois, (int)(M * fracao) faz o piso.
// 3. Repare: na divisão, códigos seguidos caem em baldes seguidos, e todo
//    múltiplo de 16 (como 1024) vai para o 0. A multiplicação espalha.
// 4. Use printf("%4d: divisão %2d, multiplicação %2d\n", ...).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 16

int main(void) {

    return 0;
}
