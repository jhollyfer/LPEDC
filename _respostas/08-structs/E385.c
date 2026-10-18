// 0065 · Bits, máscaras e flags
// Exercício E385 · ★☆☆

#include <stdio.h>

void mostrar(const char *nome, unsigned char r) {
    printf("%-7s ", nome);
    for (int b = 7; b >= 0; b--) {
        printf("%u%s", (r >> b) & 1u, b == 4 ? " " : "");
    }
    printf(" = 0x%02X = %u\n", r, r);
}

int main(void) {
    unsigned char a = 0xCA;
    unsigned char b = 0x5C;

    mostrar("a", a);
    mostrar("b", b);
    mostrar("a & b", a & b);
    mostrar("a | b", a | b);
    mostrar("a ^ b", a ^ b);
    mostrar("~a", (unsigned char)~a);
    mostrar("a << 1", (unsigned char)(a << 1));
    mostrar("a >> 3", a >> 3);
    return 0;
}
