// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2705 · ★☆☆ · Para onde vai o negativo

#include <stdio.h>

int main(void) {
    unsigned char a = (unsigned char)-1;
    unsigned char b = (unsigned char)256;
    unsigned char c = (unsigned char)300;
    unsigned short d = (unsigned short)-2;
    unsigned e = (unsigned)-3;
    printf("(unsigned char)-1 = %d\n", a);
    printf("(unsigned char)256 = %d\n", b);
    printf("(unsigned char)300 = %d\n", c);
    printf("(unsigned short)-2 = %d\n", d);
    printf("(unsigned)-3 = %u\n", e);
    return 0;
}
