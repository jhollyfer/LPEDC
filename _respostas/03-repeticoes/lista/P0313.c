// Lista · Módulo 03 · Laços
// Exercício P0313 · ★★☆ · Os números amigos

#include <stdio.h>

int main(void) {
    int a = 220, b = 284;
    int soma_a = 0, soma_b = 0;

    for (int d = 1; d < a; d++) {
        if (a % d == 0) {
            soma_a += d;
        }
    }
    for (int d = 1; d < b; d++) {
        if (b % d == 0) {
            soma_b += d;
        }
    }

    printf("Divisores de %d somam %d\n", a, soma_a);
    printf("Divisores de %d somam %d\n", b, soma_b);
    if (soma_a == b && soma_b == a) {
        printf("%d e %d são amigos\n", a, b);
    } else {
        printf("%d e %d não são amigos\n", a, b);
    }
    return 0;
}
