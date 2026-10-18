// 0139 · Troco com programação dinâmica
// Exercício E832 · ★★☆

#include <stdio.h>

#define TOTAL 7

int valor[] = {1, 2, 5};
int k = 3;

// combinações: a ordem não importa (moeda no laço de fora)
long long combinacoes(int total) {
    long long w[TOTAL + 1] = {0};
    w[0] = 1;
    for (int m = 0; m < k; m++) {
        for (int v = valor[m]; v <= total; v++) {
            w[v] += w[v - valor[m]];
        }
    }
    return w[total];
}

// sequências: a ordem importa (valor no laço de fora; testa cada último)
long long sequencias(int total) {
    long long w[TOTAL + 1] = {0};
    w[0] = 1;
    for (int v = 1; v <= total; v++) {
        for (int m = 0; m < k; m++) {
            if (valor[m] <= v) {
                w[v] += w[v - valor[m]];
            }
        }
    }
    return w[total];
}

int main(void) {
    printf("combinações: %lld\n", combinacoes(TOTAL));
    printf("sequências:  %lld\n", sequencias(TOTAL));
    return 0;
}
