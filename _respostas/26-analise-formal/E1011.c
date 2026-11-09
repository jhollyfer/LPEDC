// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1011 · ★★☆

#include <stdio.h>
#include <math.h>
#include "custo.h"

int main(void) {
    static int v[8000];
    printf("    n  bytes   4n  frames  teto(log2 n)+2\n");
    for (int n = 1000; n <= 8000; n *= 2) {
        for (int i = 0; i < n; i++) {
            v[i] = n - i;                // ao contrário
        }
        custo_zera();
        custo_merge(v, n);
        printf("%5d %6zu %5d %7d %15d\n", n, custo_bytes, 4 * n, custo_prof_max,
               (int)ceil(log2(n)) + 2);
    }
    return 0;
}
