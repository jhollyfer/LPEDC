// 0171 · Com sinal e sem sinal
// Exercício E1026 · ★★★

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

unsigned sub_saturada(unsigned a, unsigned b) {
    return a < b ? 0u : a - b;
}

bool soma_cabe(unsigned a, unsigned b) {
    return a <= UINT_MAX - b;
}

int compara(int a, unsigned b) {
    if (a < 0) {
        return -1; // qualquer negativo é menor que qualquer unsigned
    }
    unsigned ua = (unsigned)a; // a >= 0: a conversão não muda o valor
    return (ua > b) - (ua < b);
}

int main(void) {
    printf("sub_saturada(2, 3) = %u\n", sub_saturada(2, 3));
    printf("sub_saturada(10, 3) = %u\n", sub_saturada(10, 3));
    printf("soma_cabe(4000000000, 300000000) = %s\n", soma_cabe(4000000000u, 300000000u) ? "sim" : "nao");
    printf("soma_cabe(4000000000, 294967295) = %s\n", soma_cabe(4000000000u, 294967295u) ? "sim" : "nao");
    printf("compara(-1, 0) = %d\n", compara(-1, 0u));
    printf("compara(5, 5) = %d\n", compara(5, 5u));
    printf("compara(7, 3) = %d\n", compara(7, 3u));
    return 0;
}
