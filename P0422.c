// Lista · Módulo 04 · Funções e modularização
// Exercício P0422 · ★★★ · De volta para a base 10
//
// O sistema antigo grava números em outras bases, escritos com os dígitos de 0
// a 9 como se fossem decimais (2026 na base 8 vem como 3752). Escreva a função
// recursiva "long long para_decimal(long long digitos, int base)", que
// converte para a base 10 olhando o último dígito e o resto do número, e
// devolve -1 se algum dígito não existir naquela base. Teste com os quatro
// casos abaixo:
//
//   Saída esperada:
//   11111101010 na base 2 = 2026
//   3752 na base 8 = 2026
//   2210001 na base 3 = 2026
//   1289 na base 8 = inválido
//
// Dicas:
// 1. O último dígito é digitos % 10; o resto do número é digitos / 10, que
//    vale (resto convertido) × base.
// 2. Caso base: digitos == 0 devolve 0. Se o último dígito for >= base,
//    devolva -1; se a chamada para o resto devolver -1, devolva -1 também.
// 3. 11111101010 não cabe num int: use long long e o sufixo LL.
// 4. Resposta esperada: 2026 nos três primeiros; inválido no último.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
