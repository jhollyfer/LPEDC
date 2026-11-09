// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2702 · ★☆☆ · Dígitos com do/while

#include <stdio.h>

int contar_digitos(unsigned n) {
    int q = 0;
    do {
        q++;
        n /= 10;
    } while (n > 0);
    return q;
}

unsigned somar_digitos(unsigned n) {
    unsigned s = 0;
    do {
        s += n % 10;
        n /= 10;
    } while (n > 0);
    return s;
}

int main(void) {
    unsigned testes[] = {0, 7, 2026, 1000000};
    for (int i = 0; i < 4; i++) {
        printf("%u: %d dígito(s), soma %u\n", testes[i], contar_digitos(testes[i]), somar_digitos(testes[i]));
    }
    return 0;
}
