// 0094 · Merge sort
// Exercício E559 · ★☆☆

#include <stdio.h>

int intercala(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0, comparacoes = 0;
    while (i < na && j < nb) {
        comparacoes++;
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < na) {
        c[k++] = a[i++];
    }
    while (j < nb) {
        c[k++] = b[j++];
    }
    return comparacoes;
}

int main(void) {
    int turma_a[] = {45, 60, 75, 90};
    int turma_b[] = {50, 60, 85, 95, 98};
    int todas[9];

    int c = intercala(turma_a, 4, turma_b, 5, todas);
    printf("Notas:");
    for (int k = 0; k < 9; k++) {
        printf(" %d", todas[k]);
    }
    printf("\n%d comparações\n", c);
    return 0;
}
