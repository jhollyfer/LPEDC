// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2728 · ★★★ · O crivo de Eratóstenes em bits
//
// Para achar os primos até 100, o crivo de Eratóstenes marca os múltiplos
// de cada primo. Em vez de um vetor de 101 bool, use um vetor de uint32_t
// em que cada bit é um número: o número k fica no bit k % 32 da palavra
// k / 32. Escreva as macros ou funções para marcar e testar um bit, rode o
// crivo e mostre quantos primos existem até 100, os maiores que 80 e
// quantos bytes o vetor ocupou.
//
//   Saída esperada:
//   primos até 100: 25
//   maiores que 80: 83 89 97
//   vetor de bits: 16 bytes
//
// Dicas:
// 1. São 101 números: (101 + 31) / 32 = 4 palavras de 4 bytes.
// 2. Marcar k: v[k / 32] |= (uint32_t)1 << (k % 32). O 1 precisa ser de
//    32 bits sem sinal antes de deslocar.
// 3. Comece o crivo em p = 2 e, para cada p não marcado, marque p * p,
//    p * p + p, ... até 100.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
