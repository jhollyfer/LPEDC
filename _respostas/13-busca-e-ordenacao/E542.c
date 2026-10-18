// 0091 · Bubble sort
// Exercício E542 · ★☆☆

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int senhas[] = {9, 4, 7, 1, 5};
    int n = 5, trocas = 0;
    bool trocou = true;

    for (int passada = 1; passada < n && trocou; passada++) {
        trocou = false;
        int nesta = 0;                  // trocas só desta passada
        for (int j = 0; j < n - passada; j++) {
            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
                trocas++;
                nesta++;
                trocou = true;
            }
        }
        printf("passada %d:", passada);
        for (int i = 0; i < n; i++) {
            printf(" %d", senhas[i]);
        }
        printf(" (%d trocas)\n", nesta);
    }
    printf("trocas: %d\n", trocas);
    return 0;
}
