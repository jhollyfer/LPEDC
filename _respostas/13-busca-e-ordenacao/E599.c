// 0100 · Quick sort
// Exercício E599 · ★★★

#include <stdio.h>

static int comparacoes = 0;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// devolve o valor que ficaria na posição k se v fosse ordenado
int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;          // só o lado que contém k interessa
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

void quick_sort(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int j = separa(v, p, r);
    quick_sort(v, p, j - 1);
    quick_sort(v, j + 1, r);
}

int main(void) {
    int a[] = {45, 22, 38, 31, 50, 27, 24, 41, 29, 35, 33};
    int b[] = {45, 22, 38, 31, 50, 27, 24, 41, 29, 35, 33};
    int n = 11;

    int mediana = quickselect(a, n, n / 2);
    int c1 = comparacoes;
    comparacoes = 0;
    quick_sort(b, 0, n - 1);
    printf("mediana: %d min (quickselect: %d comparações)\n", mediana, c1);
    printf("ordenando tudo: %d min (%d comparações)\n", b[n / 2], comparacoes);
    return 0;
}
