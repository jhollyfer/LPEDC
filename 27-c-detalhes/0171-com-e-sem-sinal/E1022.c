// 0171 · Com sinal e sem sinal
// Exercício E1022 · ★☆☆
//
// Usando as constantes de <limits.h> (SCHAR_MIN, SCHAR_MAX, UCHAR_MAX,
// SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN,
// LONG_MAX, ULONG_MAX) e o sizeof, mostre o tamanho e a faixa de cada tipo
// inteiro, com e sem sinal. Os valores abaixo são os de um PC de 64 bits com
// Linux.
//
//   Saída esperada:
//   signed char:    1 bytes, -128 a 127
//   unsigned char:  1 bytes, 0 a 255
//   short:          2 bytes, -32768 a 32767
//   unsigned short: 2 bytes, 0 a 65535
//   int:            4 bytes, -2147483648 a 2147483647
//   unsigned:       4 bytes, 0 a 4294967295
//   long:           8 bytes, -9223372036854775808 a 9223372036854775807
//   unsigned long:  8 bytes, 0 a 18446744073709551615
//
// Dicas:
// 1. sizeof devolve size_t: mostre com %zu.
// 2. Formato certo: %d para o que cabe em int (inclusive UCHAR_MAX e
//    USHRT_MAX), %u para UINT_MAX, %ld para long, %lu para unsigned long.
// 3. O mesmo número de bits dá a mesma quantidade de valores: o com sinal
//    só divide metade para os negativos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
