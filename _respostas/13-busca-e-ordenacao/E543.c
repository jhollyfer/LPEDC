// 0091 · Bubble sort
// Exercício E543 · ★★☆

#include <stdio.h>

int main(void) {
    int idades[] = {34, 19, 27, 45, 22};
    int n = 5;
    int trocas = 0;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada; j++) {
            if (idades[j] > idades[j + 1]) {
                int aux = idades[j];
                idades[j] = idades[j + 1];
                idades[j + 1] = aux;
                trocas++;
            }
        }
        printf("passada %d:", passada);
        for (int i = 0; i < n; i++) {
            printf(" %d", idades[i]);
        }
        printf("\n");
    }
    printf("%d trocas\n", trocas);
    return 0;
}
