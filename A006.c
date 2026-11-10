// A006 · A tabela de tamanhos e limites desta máquina

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

// Cada tipo tem o seu código no printf: %d (int), %u (unsigned),
// %ld (long), %lld (long long), %llu (unsigned long long).
int main(void) {
    printf("char:      %zu byte,  %d a %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("u. char:   %zu byte,  0 a %d\n", sizeof(unsigned char), UCHAR_MAX);
    printf("short:     %zu bytes, %d a %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int:       %zu bytes, %d a %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("u. int:    %zu bytes, 0 a %u\n", sizeof(unsigned int), UINT_MAX);
    printf("long:      %zu bytes, até %ld\n", sizeof(long), LONG_MAX);
    printf("long long: %zu bytes, até %lld\n", sizeof(long long), LLONG_MAX);

    // stdint.h: o número de bits está no nome do tipo
    printf("int8_t: %zu, uint16_t: %zu, int32_t: %zu, int64_t: %zu bytes\n",
           sizeof(int8_t), sizeof(uint16_t), sizeof(int32_t), sizeof(int64_t));
    printf("uint64_t vai até %llu\n", (unsigned long long)UINT64_MAX);

    // hexadecimal no código: 0x na frente; cada dígito vale 4 bits
    printf("0xFF = %d, 0xFFFF = %d, 0x7FFFFFFF = %d\n", 0xFF, 0xFFFF, 0x7FFFFFFF);
    return 0;
}
// Saída (num PC Linux de 64 bits):
// char:      1 byte,  -128 a 127
// u. char:   1 byte,  0 a 255
// short:     2 bytes, -32768 a 32767
// int:       4 bytes, -2147483648 a 2147483647
// u. int:    4 bytes, 0 a 4294967295
// long:      8 bytes, até 9223372036854775807
// long long: 8 bytes, até 9223372036854775807
// int8_t: 1, uint16_t: 2, int32_t: 4, int64_t: 8 bytes
// uint64_t vai até 18446744073709551615
// 0xFF = 255, 0xFFFF = 65535, 0x7FFFFFFF = 2147483647
