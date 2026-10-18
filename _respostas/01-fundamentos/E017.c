// 0003 · Tipos e limites
// Exercício E017 · ★★★
//
// Resposta: a) 2.147.483.647 é o INT32_MAX, o maior inteiro de 32 bits com
// sinal (2^31 - 1): um contador desse tipo não passa dali. b) 2147483647
// segundos divididos por uns 31,5 milhões de segundos por ano dão cerca de
// 68 anos; 1970 + 68 = 2038 (o estouro é em 19/01/2038, às 03:14:07 UTC).
// c) Na prática, sim: 2^63 segundos são uns 292 bilhões de anos.

#include <stdio.h>
#include <stdint.h>

int main(void) {
    printf("int32_t vai até %d\n", INT32_MAX);
    printf("int64_t vai até %lld\n", (long long)INT64_MAX);
    return 0;
}
