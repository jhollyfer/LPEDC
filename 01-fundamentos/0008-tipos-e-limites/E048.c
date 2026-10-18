// 0008 · Tipos e limites
// Exercício E048 · ★★★
//
// Sem rodar, preveja a saída num PC Linux de 64 bits. Depois copie para a
// main (com os #include) e confira.
//
//   printf("%d\n", SCHAR_MAX);
//   printf("%d\n", SCHAR_MIN);
//   printf("%d\n", UCHAR_MAX);
//   printf("%d\n", SHRT_MIN);
//   printf("%u\n", UINT_MAX);
//   printf("%zu %zu\n", sizeof(long), sizeof(long long));
//   printf("%d\n", 0x7F + 0x01);
//
// Responda também:
// a) Por que o menor valor tem um número a mais que o maior (-128 e 127)?
// b) Num PC com Windows, o sizeof(long) daria o mesmo? Que tipo você usa
//    quando precisa de exatamente 64 bits em qualquer sistema?
//
// Dicas:
// 1. SCHAR é signed char (1 byte com sinal); UCHAR, unsigned char.
// 2. Complemento de dois: o bit de cima pesa negativo (-128 num byte).
// 3. Resposta esperada: 127, -128, 255, -32768, 4294967295, "8 8" e 128.
//    a) o zero ocupa uma das combinações do lado positivo, e não existe -0:
//    sobram 128 negativos e 127 positivos. b) não: no Windows o long tem 4
//    bytes; use int64_t (ou long long, que tem pelo menos 64 bits).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <limits.h>

int main(void) {

    return 0;
}
