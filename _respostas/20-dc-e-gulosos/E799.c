// 0134 · Seleção de intervalos
// Exercício E799 · ★☆☆

#include <stdio.h>

int main(void) {
    // reuniões já ordenadas pela hora de fim
    int ini[] = {8, 8, 9, 10, 11, 12, 13, 14};
    int fim[] = {9, 10, 11, 12, 12, 14, 15, 16};
    int n = 8;

    int livre_em = 0, total = 0;
    printf("Escolhidas:");
    for (int i = 0; i < n; i++) {
        if (ini[i] >= livre_em) {
            printf(" %d-%d", ini[i], fim[i]);
            livre_em = fim[i];
            total++;
        }
    }
    printf("\nTotal: %d\n", total);
    return 0;
}
