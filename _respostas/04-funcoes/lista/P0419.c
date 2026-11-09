// Lista · Módulo 04 · Funções e modularização
// Exercício P0419 · ★★☆ · O número da numerologia

#include <stdio.h>

int soma_digitos(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + soma_digitos(n / 10);
}

int reduz(int n) {
    printf("%d", n);
    if (n < 10) {
        printf("\n");
        return n;
    }
    printf(" -> ");
    return reduz(soma_digitos(n));
}

int main(void) {
    reduz(27111990);
    reduz(2026);
    return 0;
}
