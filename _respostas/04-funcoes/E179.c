// 0030 · Escopo e tempo de vida
// Exercício E179 · ★★★
//
// Resposta:
// main: 20 / bloco: 30 / a: 1 -> 2 / b: 5 -> 10 / c: 10 -> 20 /
// a: 1 -> 2 / b: 10 -> 15 / c: 20 -> 40 / main: 20.
// A local de a recomeça em 1; a static de b guarda o valor; c dobra a global
// (10, depois 20); o x do main nunca é tocado por ninguém.

#include <stdio.h>

int x = 10;

void a(void) {
    int x = 1;
    printf("a: %d", x);
    x++;
    printf(" -> %d\n", x);
}

void b(void) {
    static int x = 5;
    printf("b: %d", x);
    x += 5;
    printf(" -> %d\n", x);
}

void c(void) {
    printf("c: %d", x);
    x *= 2;
    printf(" -> %d\n", x);
}

int main(void) {
    int x = 20;
    printf("main: %d\n", x);
    {
        int x = 30;
        printf("bloco: %d\n", x);
    }
    a(); b(); c();
    a(); b(); c();
    printf("main: %d\n", x);
    return 0;
}
