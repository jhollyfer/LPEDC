// Lista · Módulo 03 · Laços
// Exercício P0311 · ★★☆ · O pedido de trás para frente

#include <stdio.h>

int main(void) {
    int original = 120345;
    int n = original, invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }
    printf("%d invertido: %d (%s)\n", original, invertido,
           invertido == original ? "é capicua" : "não é capicua");

    original = 12321;
    n = original;
    invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }
    printf("%d invertido: %d (%s)\n", original, invertido,
           invertido == original ? "é capicua" : "não é capicua");
    return 0;
}
