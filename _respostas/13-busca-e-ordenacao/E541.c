// 0091 · Bubble sort
// Exercício E541 · ★☆☆

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int pontos[] = {18, 31, 7, 25, 31, 12};
    int n = 6;

    for (int passada = 1; passada < n; passada++) {
        bool trocou = false;
        for (int j = 0; j < n - passada; j++) {
            if (pontos[j] < pontos[j + 1]) { // só muda o sinal: < em vez de >
                int aux = pontos[j];
                pontos[j] = pontos[j + 1];
                pontos[j + 1] = aux;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }

    printf("Ranking:");
    for (int i = 0; i < n; i++) {
        printf(" %d", pontos[i]);
    }
    printf("\n");
    return 0;
}
