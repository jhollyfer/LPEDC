// Lista · Módulo 21 · Programação dinâmica
// Exercício P2126 · ★★★ · Subsequência crescente em O(n log n)

#include <stdio.h>

#define N 16

int main(void) {
    const int v[N] = {40, 42, 38, 45, 43, 47, 41, 50, 48, 52, 44, 55, 53, 49, 58, 60};
    int idx[N], ant[N], tam = 0;
    for (int i = 0; i < N; i++) {
        int ini = 0, fim = tam;
        while (ini < fim) {
            int meio = ini + (fim - ini) / 2;
            if (v[idx[meio]] < v[i]) {
                ini = meio + 1;
            } else {
                fim = meio;
            }
        }
        ant[i] = ini > 0 ? idx[ini - 1] : -1;
        idx[ini] = i;
        if (ini == tam) {
            tam++;
        }
    }
    int seq[N], k = 0;
    for (int i = idx[tam - 1]; i != -1; i = ant[i]) {
        seq[k++] = v[i];
    }
    printf("Maior sequência crescente: %d treinos\n", tam);
    printf("Cargas:");
    for (int i = k - 1; i >= 0; i--) {
        printf(" %d", seq[i]);
    }
    printf("\n");
    return 0;
}
