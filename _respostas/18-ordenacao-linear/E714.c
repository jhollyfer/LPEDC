// 0119 · Shell sort
// Exercício E714 · ★★★

#include <stdio.h>

// pares (i, j) com i < j e v[i] > v[j]: quanto falta para ordenar
long inversoes(const int v[], int n) {
    long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                total++;
            }
        }
    }
    return total;
}

int main(void) {
    int v[200];
    int n = 200;
    for (int i = 0; i < n; i++) {
        v[i] = (i * 73 + 11) % 200; // os números de 0 a 199, embaralhados
    }

    long inicio = inversoes(v, n), total = 0;
    printf("início: %5ld inversões\n", inicio);
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        long movimentos = 0;
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];
                j -= h;
                movimentos++;
            }
            v[j] = x;
        }
        total += movimentos;
        printf("h = %3d: %5ld inversões, %4ld movimentos\n", h, inversoes(v, n), movimentos);
    }
    // cada movimento do insertion sort desfaz exatamente uma inversão
    printf("total: %ld movimentos (o insertion sort faria %ld)\n", total, inicio);
    return 0;
}
