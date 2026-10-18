// 0030 · Escopo e tempo de vida
// Exercício E179 · ★★★

#include <stdio.h>

int x = 10; // global

void a(void) {
    int x = 1; // local: recomeça em 1 a cada chamada
    printf("a: %d", x);
    x++;
    printf(" -> %d\n", x);
}

int b(void) {
    static int x = 5; // static: continua de onde parou
    printf("b: %d", x);
    x += 5;
    printf(" -> %d\n", x);
    return x;
}

void c(void) {
    printf("c: %d", x); // a global
    x *= 2;
    printf(" -> %d\n", x);
}

int main(void) {
    int x = 20;
    int soma = 0;

    printf("main: %d\n", x);
    {
        int x = 30;
        printf("bloco: %d\n", x);
    }
    a();
    soma += b();
    c();
    a();
    soma += b();
    c();
    printf("main: %d\n", x);
    printf("soma dos b: %d\n", soma);
    return 0;
}
