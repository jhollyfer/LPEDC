// 0093 · Insertion sort
// Exercício E557 · ★★★

#include <stdio.h>

int main(void) {
    int idades[] = {31, 12, 45, 27, 8, 19};
    int n = 6;
    int comparacoes = 0, deslocamentos = 0;

    for (int j = 1; j < n; j++) {
        int x = idades[j];
        int i = j - 1;
        while (i >= 0) {
            comparacoes++;
            if (idades[i] <= x) {
                break;
            }
            idades[i + 1] = idades[i];
            deslocamentos++;
            i--;
        }
        idades[i + 1] = x;
        printf("j = %d:", j);
        for (int k = 0; k < n; k++) {
            printf(" %d", idades[k]);
        }
        printf("\n");
    }
    printf("%d comparações, %d deslocamentos\n", comparacoes, deslocamentos);
    return 0;
}
