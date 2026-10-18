// 0124 · Juntando tudo
// Exercício E740 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000

// faixa do valor: 0 até R$ 9,99; 1 até R$ 99,99; 2 até R$ 999,99; 3 o resto
int faixa(int32_t centavos) {
    if (centavos < 1000) {
        return 0;
    }
    if (centavos < 10000) {
        return 1;
    }
    if (centavos < 100000) {
        return 2;
    }
    return 3;
}

int main(void) {
    Pix *v = malloc(N * sizeof(Pix));
    if (v == NULL) {
        return 1;
    }
    pix_gera(v, N, 2024);

    int c[4] = {0};
    for (int i = 0; i < N; i++) {
        c[faixa(v[i].centavos)]++;
    }
    const char *nomes[] = {"até R$ 9,99:       ", "R$ 10 a R$ 99,99:  ", "R$ 100 a R$ 999,99:",
                           "R$ 1000 ou mais:   "};
    for (int f = 0; f < 4; f++) {
        printf("%s %6d (%4.1f%%)\n", nomes[f], c[f], 100.0 * c[f] / N);
    }
    free(v);
    return 0;
}
