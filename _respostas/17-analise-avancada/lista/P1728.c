// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1728 · ★★★ · Fabrique o pior caso do merge sort

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

long comparacoes;

void intercala(int v[], int n) {
    int h = n / 2, i = 0, j = h, k = 0, t[MAX];
    while (i < h && j < n) {
        comparacoes++;
        t[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i < h) t[k++] = v[i++];
    while (j < n) t[k++] = v[j++];
    memcpy(v, t, n * sizeof(int));
}

void merge_sort(int v[], int n) {
    if (n <= 1) return;
    merge_sort(v, n / 2);
    merge_sort(v + n / 2, n - n / 2);
    intercala(v, n);
}

void pior(int v[], int n) { // desfaz o merge sort: pares à esquerda, ímpares à direita
    if (n <= 1) return;
    int t[MAX];
    for (int i = 0; i < n; i++) t[(i % 2) * (n / 2) + i / 2] = v[i];
    pior(t, n / 2);
    pior(t + n / 2, n / 2);
    memcpy(v, t, n * sizeof(int));
}

int main(void) {
    int fabricada8[8];
    printf("   n  ordenada  fabricada  n lg n - n + 1  teto(lg n!)\n");
    for (int n = 8; n <= MAX; n = (n == 16 ? 1024 : 2 * n)) {
        int v[MAX], k = 0;
        for (int i = 0; i < n; i++) v[i] = i + 1;
        comparacoes = 0;
        merge_sort(v, n);
        long c_ord = comparacoes;

        pior(v, n); // v está ordenado: fabrica o pior caso
        if (n == 8) memcpy(fabricada8, v, sizeof fabricada8);
        comparacoes = 0;
        merge_sort(v, n);
        for (int m = n; m > 1; m /= 2) k++; // k = lg n
        double lgfat = 0;
        for (int i = 2; i <= n; i++) lgfat += log2((double)i);
        printf("%4d %9ld %10ld %15d %12.0f\n", n, c_ord, comparacoes, n * k - n + 1, ceil(lgfat));
    }
    printf("Entrada fabricada (n = 8):");
    for (int i = 0; i < 8; i++) printf(" %d", fabricada8[i]);
    printf("\n");
    return 0;
}
