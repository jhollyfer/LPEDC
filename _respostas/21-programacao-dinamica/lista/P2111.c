// Lista · Módulo 21 · Programação dinâmica
// Exercício P2111 · ★★☆ · Dois barcos com o mesmo peso

#include <stdbool.h>
#include <stdio.h>

#define N 8

int main(void) {
    const int peso[N] = {12, 7, 9, 15, 6, 11, 8, 4};
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += peso[i];
    }
    if (total % 2 != 0) {
        printf("Total ímpar: não dá\n");
        return 0;
    }
    int meta = total / 2;
    bool pode[N + 1][73];
    for (int i = 0; i <= N; i++) {
        for (int s = 0; s <= meta; s++) {
            if (i == 0) {
                pode[i][s] = s == 0;
            } else {
                pode[i][s] = pode[i - 1][s] || (s >= peso[i - 1] && pode[i - 1][s - peso[i - 1]]);
            }
        }
    }
    if (!pode[N][meta]) {
        printf("Não dá para dividir %d kg ao meio\n", total);
        return 0;
    }
    bool barco1[N] = {false};
    for (int i = N, s = meta; i > 0; i--) {
        if (!pode[i - 1][s]) {
            barco1[i - 1] = true;
            s -= peso[i - 1];
        }
    }
    for (int b = 1; b <= 2; b++) {
        int soma = 0;
        printf("Barco %d:", b);
        for (int i = 0; i < N; i++) {
            if (barco1[i] == (b == 1)) {
                printf(" %d", peso[i]);
                soma += peso[i];
            }
        }
        printf(" (%d kg)\n", soma);
    }
    return 0;
}
