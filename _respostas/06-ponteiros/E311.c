// 0052 · Ponteiros e vetores
// Exercício E311 · ★★★

#include <stdio.h>

int main(void) {
    int vendas[3][4] = {
        {12, 15, 9, 20},
        {7, 11, 14, 10},
        {18, 6, 13, 16},
    };
    int filial[3] = {0};
    int total = 0;
    int *inicio = &vendas[0][0];

    for (int *p = inicio; p < inicio + 12; p++) {
        total += *p;
        filial[(p - inicio) / 4] += *p;
    }

    printf("Total: %d\n", total);
    int campea = 0;
    for (int i = 0; i < 3; i++) {
        printf("Filial %d: %d\n", i, filial[i]);
        if (filial[i] > filial[campea]) {
            campea = i;
        }
    }
    printf("Campeã: filial %d\n", campea);
    return 0;
}
