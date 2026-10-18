// 0004 · Constantes
// Exercício E022 · ★★☆
//
// Resposta: 10 é int (10); 10.0 é double (10); 10.0f é float (10); 010 é
// int em octal (8); 0x10 é int em hexadecimal (16); '0' é int (48, o código
// do caractere zero); "0" é um texto de 2 bytes ('0' e o byte zero); 1e3 é
// double (1000).

#include <stdio.h>

int main(void) {
    printf("10: %zu bytes\n", sizeof(10));
    printf("10.0: %zu bytes\n", sizeof(10.0));
    printf("10.0f: %zu bytes\n", sizeof(10.0f));
    printf("010: %zu bytes\n", sizeof(010));
    printf("0x10: %zu bytes\n", sizeof(0x10));
    printf("'0': %zu bytes\n", sizeof('0'));
    printf("\"0\": %zu bytes\n", sizeof("0"));
    printf("1e3: %zu bytes\n", sizeof(1e3));
    return 0;
}
