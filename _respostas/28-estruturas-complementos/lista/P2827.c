// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2827 · ★★★ · A AVL mais magra de cada altura

#include <math.h>
#include <stdio.h>

int main(void) {
    long N[13];
    N[0] = 1;
    N[1] = 2;
    for (int h = 2; h <= 12; h++) {
        N[h] = N[h - 1] + N[h - 2] + 1;
    }
    printf(" h | mínimo | máximo | h / log2(N + 1)\n");
    for (int h = 0; h <= 12; h++) {
        printf("%2d | %6ld | %6ld | %.2f\n", h, N[h], (1L << (h + 1)) - 1,
               h / log2(N[h] + 1.0));
    }
    return 0;
}
