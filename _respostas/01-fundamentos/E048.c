// 0008 · Tipos e limites
// Exercício E048 · ★★★
//
// Resposta: 127, -128, 255, -32768, 4294967295, "8 8" e 128 (0x7F é 127).
// a) Em complemento de dois, o zero usa uma combinação do lado "positivo"
// (bit de cima 0) e não existe -0. Com 256 combinações: 128 negativas, o
// zero e 127 positivas. b) Não: no Windows o long tem 4 bytes. Para
// exatamente 64 bits em qualquer sistema, use int64_t (do stdint.h).

#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("%d\n", SCHAR_MAX);
    printf("%d\n", SCHAR_MIN);
    printf("%d\n", UCHAR_MAX);
    printf("%d\n", SHRT_MIN);
    printf("%u\n", UINT_MAX);
    printf("%zu %zu\n", sizeof(long), sizeof(long long));
    printf("%d\n", 0x7F + 0x01);
    return 0;
}
