// 0092 · Selection sort
// Exercício E548 · ★☆☆

#include <stdio.h>

int main(void) {
    int caixas[] = {3, 1, 2, 5, 4};
    int n = 5, trocas = 0, comparacoes = 0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (caixas[j] < caixas[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int aux = caixas[i];
            caixas[i] = caixas[menor];
            caixas[menor] = aux;
            trocas++;
        }
        printf("i = %d:", i);
        for (int k = 0; k < n; k++) {
            printf(" %d", caixas[k]);
        }
        if (menor == i) {
            printf(" (sem troca)");
        }
        printf("\n");
    }
    printf("trocas: %d\n", trocas);
    printf("comparações: %d\n", comparacoes);
    return 0;
}
