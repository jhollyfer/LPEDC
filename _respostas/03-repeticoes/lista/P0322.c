// Lista · Módulo 03 · Laços
// Exercício P0322 · ★★★ · De decimal para qualquer base

#include <stdio.h>

int main(void) {
    int n, base;

    do {
        printf("Número e base: ");
        if (scanf("%d %d", &n, &base) != 2) {
            return 1;
        }
    } while (n < 0 || base < 2 || base > 16);

    int potencia = 1;
    while (potencia <= n / base) { // maior potência que ainda cabe em n
        potencia *= base;
    }

    printf("%d na base %d: ", n, base);
    int resto = n;
    while (potencia > 0) {
        int digito = resto / potencia;
        resto %= potencia;
        potencia /= base;
        printf("%c", digito < 10 ? '0' + digito : 'A' + digito - 10);
    }
    printf("\n");
    return 0;
}
