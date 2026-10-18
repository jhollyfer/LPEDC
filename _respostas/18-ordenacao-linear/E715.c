// 0120 · Counting sort
// Exercício E715 · ★☆☆

#include <stdio.h>

int main(void) {
    int notas[] = {7, 5, 10, 3, 7, 8, 5, 7, 9, 6, 4, 7, 8, 2, 5, 10, 6, 7, 8, 5};
    int n = 20;
    int c[11] = {0};

    for (int i = 0; i < n; i++) {
        c[notas[i]]++;
    }
    int pos = 0, mais_comum = 0;
    for (int x = 0; x <= 10; x++) {
        for (int r = 0; r < c[x]; r++) {
            notas[pos++] = x;
        }
        if (c[x] > c[mais_comum]) {
            mais_comum = x;
        }
    }
    printf("ordenadas:");
    for (int i = 0; i < n; i++) {
        printf(" %d", notas[i]);
    }
    printf("\nmais comum: %d (%d alunos)\n", mais_comum, c[mais_comum]);
    return 0;
}
