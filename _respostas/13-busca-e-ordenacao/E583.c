// 0098 · Insertion sort
// Exercício E583 · ★☆☆

#include <stdio.h>

int main(void) {
    int notas[] = {650, 720, 580, 810, 690};
    int n = 5;

    for (int j = 1; j < n; j++) {
        int x = notas[j];
        int i = j - 1;
        while (i >= 0 && notas[i] < x) {   // empurra os MENORES
            notas[i + 1] = notas[i];
            i--;
        }
        notas[i + 1] = x;
    }

    printf("Classificação:");
    for (int i = 0; i < n; i++) {
        printf(" %d", notas[i]);
    }
    printf("\n");
    return 0;
}
