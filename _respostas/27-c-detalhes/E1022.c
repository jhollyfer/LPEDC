// 0171 · Com sinal e sem sinal
// Exercício E1022 · ★☆☆

#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("signed char:    %zu bytes, %d a %d\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:  %zu bytes, 0 a %d\n", sizeof(unsigned char), UCHAR_MAX);
    printf("short:          %zu bytes, %d a %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %zu bytes, 0 a %d\n", sizeof(unsigned short), USHRT_MAX);
    printf("int:            %zu bytes, %d a %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned:       %zu bytes, 0 a %u\n", sizeof(unsigned), UINT_MAX);
    printf("long:           %zu bytes, %ld a %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long:  %zu bytes, 0 a %lu\n", sizeof(unsigned long), ULONG_MAX);
    return 0;
}
