// Lista · Módulo 04 · Funções e modularização
// Exercício P0407 · ★☆☆ · A pirâmide de latas

#include <stdio.h>

int latas(int n) {
    if (n == 1) {
        return 1;
    }
    return n + latas(n - 1);
}

int main(void) {
    printf("Base 1: %d lata(s)\n", latas(1));
    printf("Base 4: %d lata(s)\n", latas(4));
    printf("Base 10: %d lata(s)\n", latas(10));
    return 0;
}
