// 0072 · Notação O: como o custo cresce
// Exercício E431 · ★★★
//
// Resposta: B passa a ganhar em n = 190. Abaixo disso, o algoritmo O(n²) é
// o mais rápido; com 10000 entregas, B é uns 30 vezes mais rápido.

#include <math.h>
#include <stdio.h>

double custo_a(int n) {
    return 2.0 * n * n;
}

double custo_b(int n) {
    return 50.0 * n * log2(n);
}

int main(void) {
    for (int n = 2;; n++) {
        if (custo_b(n) < custo_a(n)) {
            printf("B passa a ganhar em n = %d (A: %.0f, B: %.0f)\n", n, custo_a(n), custo_b(n));
            break;
        }
    }

    int tamanhos[4] = {10, 100, 1000, 10000};
    printf("%6s %11s %10s\n", "n", "A", "B");
    for (int k = 0; k < 4; k++) {
        int n = tamanhos[k];
        printf("%6d %11.0f %10.0f\n", n, custo_a(n), custo_b(n));
    }
    return 0;
}
