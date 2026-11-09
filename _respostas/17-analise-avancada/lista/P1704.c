// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1704 · ★☆☆ · Contador binário: quantas vezes cada bit troca

#include <stdio.h>

#define K 8

int trocas[K];

int incrementa(int b[]) {
    int i = 0, custo = 0;
    while (i < K && b[i] == 1) { // 1 vira 0 e "vai um"
        b[i] = 0;
        trocas[i]++;
        custo++;
        i++;
    }
    if (i < K) {
        b[i] = 1;
        trocas[i]++;
        custo++;
    }
    return custo;
}

int main(void) {
    int b[K] = {0}, n = 32;
    long total = 0;
    for (int k = 1; k <= n; k++) {
        int c = incrementa(b);
        total += c;
        if (k <= 8) {
            for (int i = K - 1; i >= 0; i--) printf("%d", b[i]);
            printf("  custo %d\n", c);
        }
    }
    for (int i = 0; i < K; i++) printf("bit %d: %2d trocas\n", i, trocas[i]);
    printf("Total: %ld trocas em %d incrementos (limite 2n = %d)\n", total, n, 2 * n);
    return 0;
}
