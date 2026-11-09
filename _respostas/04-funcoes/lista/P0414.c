// Lista · Módulo 04 · Funções e modularização
// Exercício P0414 · ★★☆ · Subindo a escada da arquibancada

#include <stdio.h>

int formas(int n) {
    if (n < 0) {
        return 0; // passou do topo: não conta
    }
    if (n == 0) {
        return 1; // chegou exatamente
    }
    return formas(n - 1) + formas(n - 2) + formas(n - 3);
}

int main(void) {
    for (int n = 1; n <= 10; n++) {
        printf("%d degrau(s): %d forma(s)\n", n, formas(n));
    }
    return 0;
}
