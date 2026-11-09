// Lista · Módulo 04 · Funções e modularização
// Exercício P0413 · ★★☆ · Quantas chamadas custa uma combinação

#include <stdio.h>

long chamadas = 0;

int combinacao(int n, int k) {
    chamadas++;
    if (k == 0 || k == n) {
        return 1;
    }
    return combinacao(n - 1, k - 1) + combinacao(n - 1, k);
}

int main(void) {
    int r;

    chamadas = 0;
    r = combinacao(5, 2);
    printf("C(5, 2) = %d com %ld chamadas\n", r, chamadas);

    chamadas = 0;
    r = combinacao(10, 5);
    printf("C(10, 5) = %d com %ld chamadas\n", r, chamadas);

    chamadas = 0;
    r = combinacao(20, 10);
    printf("C(20, 10) = %d com %ld chamadas\n", r, chamadas);
    return 0;
}
