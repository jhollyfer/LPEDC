// 0139 · Troco com programação dinâmica
// Exercício E834 · ★★★

#include <stdio.h>

#define TOTAL 100
#define MAXM 6

int main(void) {
    int moeda[] = {5, 10, 25, 50};
    int k = 4;
    // w[q][v] = combinações com exatamente q moedas que somam v centavos
    long long w[MAXM + 1][TOTAL + 1] = {{0}};

    w[0][0] = 1; // zero moedas somam zero
    for (int m = 0; m < k; m++) {                    // moeda por fora: combinações
        for (int v = moeda[m]; v <= TOTAL; v++) {    // v crescente: a moeda repete
            for (int q = 1; q <= MAXM; q++) {
                w[q][v] += w[q - 1][v - moeda[m]];   // mais uma moeda[m]
            }
        }
    }

    long long total = 0;
    for (int q = 1; q <= MAXM; q++) {
        printf("exatamente %d moeda%s: %lld\n", q, q > 1 ? "s" : "", w[q][TOTAL]);
        total += w[q][TOTAL];
    }
    printf("até %d moedas: %lld combinações\n", MAXM, total);
    return 0;
}
