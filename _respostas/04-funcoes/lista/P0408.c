// Lista · Módulo 04 · Funções e modularização
// Exercício P0408 · ★☆☆ · Quantos dígitos tem

#include <stdio.h>

int digitos(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + digitos(n / 10);
}

int main(void) {
    printf("7 tem %d dígito(s)\n", digitos(7));
    printf("2026 tem %d dígito(s)\n", digitos(2026));
    printf("1000000 tem %d dígito(s)\n", digitos(1000000));
    return 0;
}
