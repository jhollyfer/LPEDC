// 0071 · Eficiência: contar passos
// Exercício E423 · ★★☆
//
// Resposta: médias 5.5, 50.5 e 500.5, ou seja, (n + 1) / 2.

#include <stdio.h>

long passos = 0;

int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        passos++;
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int v[1000];
    int tamanhos[3] = {10, 100, 1000};

    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            v[i] = 3 * i + 1;
        }
        passos = 0;
        for (int i = 0; i < n; i++) {
            busca(v, n, v[i]);
        }
        printf("n = %4d: total %6ld, média %5.1f\n", n, passos, (double)passos / n);
    }
    return 0;
}
