// 0004 · Constantes
// Exercício E022 · ★★☆

#include <stdio.h>

int main(void) {
    printf("10: vale %d, %zu bytes\n", 10, sizeof 10);
    printf("10.0: vale %.1f, %zu bytes\n", 10.0, sizeof 10.0);
    printf("10.0f: vale %.1f, %zu bytes\n", 10.0f, sizeof 10.0f);
    printf("010: vale %d, %zu bytes\n", 010, sizeof 010);     // octal
    printf("0x10: vale %d, %zu bytes\n", 0x10, sizeof 0x10);  // hexa
    printf("'0': vale %d, %zu bytes\n", '0', sizeof '0');     // código do '0'
    printf("\"0\": %zu bytes\n", sizeof "0");                 // '0' e o '\0'
    printf("1e3: vale %.1f, %zu bytes\n", 1e3, sizeof 1e3);
    return 0;
}
