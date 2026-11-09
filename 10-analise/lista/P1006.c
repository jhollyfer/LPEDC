// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1006 · ★☆☆ · Quantos dígitos tem o valor do boleto
//
// Escreva int digitos(long long n, int *passos), que conta os dígitos de
// n >= 0 dividindo por 10 até sobrar zero, e conta em *passos quantas
// divisões fez. Use um do-while, para que o 0 tenha 1 dígito. Mostre o
// resultado para 0, 7, 70, 7000, 7000000 e 7000000000.
//
//   Saída esperada:
//   0: 1 dígito(s), 1 divisões
//   7: 1 dígito(s), 1 divisões
//   70: 2 dígito(s), 2 divisões
//   7000: 4 dígito(s), 4 divisões
//   7000000: 7 dígito(s), 7 divisões
//   7000000000: 10 dígito(s), 10 divisões
//
// Dicas:
// 1. do { n = n / 10; cont++; } while (n > 0);
// 2. 7000000000 não cabe num int: use long long e "%lld".
// 3. n multiplicado por 1000 custa só 3 divisões a mais: o número de passos
//    é piso(log₁₀ n) + 1, ou seja, O(log n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
