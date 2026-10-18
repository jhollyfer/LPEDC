// 0093 · Insertion sort
// Exercício E554 · ★☆☆

#include <stdio.h>

int main(void) {
    int malas[] = {23, 15, 30, 8, 19};   // kg
    int n = 5;

    for (int j = 1; j < n; j++) {
        int x = malas[j];
        int i = j - 1;
        while (i >= 0 && malas[i] > x) {
            malas[i + 1] = malas[i];     // linha 1: empurra para a direita
            i--;
        }
        malas[i + 1] = x;                // linha 2: encaixa no buraco
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", malas[k]);
    }
    printf("\n");
    return 0;
}
