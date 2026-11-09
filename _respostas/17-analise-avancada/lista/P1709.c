// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1709 · ★☆☆ · A função que se chama duas vezes à toa

#include <stdio.h>

long chamadas;

long meta(int n) {
    chamadas++;
    if (n == 1) return 100;
    return meta(n - 1) + meta(n - 1); // dobra a meta do mês anterior
}

long meta_boa(int n) {
    chamadas++;
    if (n == 1) return 100;
    long anterior = meta_boa(n - 1); // uma chamada só
    return anterior + anterior;
}

int main(void) {
    int ns[] = {1, 5, 10, 20, 25};
    printf(" n        meta  ruim: chamadas     2^n-1  boa: chamadas\n");
    for (int k = 0; k < 5; k++) {
        int n = ns[k];
        chamadas = 0;
        long m = meta(n);
        long ruim = chamadas;
        chamadas = 0;
        meta_boa(n);
        printf("%2d %11ld %16ld %9ld %14ld\n", n, m, ruim, (1L << n) - 1, chamadas);
    }
    return 0;
}
