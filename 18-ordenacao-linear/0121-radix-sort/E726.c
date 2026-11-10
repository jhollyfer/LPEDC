// 0121 · Radix sort
// Exercício E726 · ★★★
//
// O extrato tem saques (negativos) e depósitos, em centavos. No complemento
// de dois, -7 é FFFFFFF9: como número sem sinal ele é enorme, e o radix sort
// em base 256 ingênuo põe os negativos depois dos positivos. Escreva
// radix(v, aux, n, com_chave) para int32_t: sem a chave, ordena por
// (uint32_t) x; com a chave, por (uint32_t) x ^ 0x80000000u (inverte o bit
// de sinal). Use -150000, 3200, -7, 0, INT_MAX, INT_MIN, 98000, -98000 e 7;
// mostre o -7 em hexadecimal e o resultado dos dois casos.
//
//   Saída esperada:
//   -7 como uint32_t: FFFFFFF9
//   sem a chave: 0 7 3200 98000 2147483647 -2147483648 -150000 -98000 -7
//   com a chave: -2147483648 -150000 -98000 -7 0 7 3200 98000 2147483647
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
