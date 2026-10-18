// 0139 · Troco com programação dinâmica
// Exercício E830 · ★☆☆

#include <stdio.h>

#define PONTOS 10

int main(void) {
    int cesta[] = {1, 2, 3}; // lance livre, cesta de dois, cesta de três
    long long jeitos[PONTOS + 1] = {0};

    jeitos[0] = 1;
    for (int c = 0; c < 3; c++) {                    // de fora: o tipo de cesta
        for (int v = cesta[c]; v <= PONTOS; v++) {   // de dentro: os pontos
            jeitos[v] += jeitos[v - cesta[c]];
        }
    }

    printf("jeitos:");
    for (int v = 0; v <= PONTOS; v++) {
        printf(" %lld", jeitos[v]);
    }
    printf("\nCombinações de cestas que dão %d pontos: %lld\n", PONTOS, jeitos[PONTOS]);
    return 0;
}
