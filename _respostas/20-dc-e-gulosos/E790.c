// 0132 · Inversões e subvetor de soma máxima
// Exercício E790 · ★★☆

#include <stdio.h>
#include <string.h>

// insertion sort que devolve quantos deslocamentos fez
long long insercao(int v[], int n) {
    long long desloca = 0;
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
            desloca++;
        }
        v[j + 1] = x;
    }
    return desloca;
}

long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    return conta(v, w, p, q) + conta(v, w, q, r) + intercala(v, w, p, q, r);
}

int main(void) {
    int pesos[] = {31, 12, 45, 27, 8, 39, 19, 50, 4, 23, 36, 15};
    int n = 12;
    int a[12], b[12], w[12];
    memcpy(a, pesos, sizeof pesos); // cada algoritmo ordena a sua cópia
    memcpy(b, pesos, sizeof pesos);

    printf("Deslocamentos do insertion sort: %lld\n", insercao(a, n));
    printf("Inversões pelo merge sort: %lld\n", conta(b, w, 0, n));
    return 0;
}
