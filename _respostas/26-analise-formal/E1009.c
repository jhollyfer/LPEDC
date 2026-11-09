// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1009 · ★☆☆

#include <stdio.h>
#include <math.h>
#include "custo.h"

int main(void) {
    static int preco[8000];
    for (int i = 0; i < 8000; i++) {
        preco[i] = 50 + 2 * i;
    }
    printf("    n  soma  busca  log2(n)+1\n");
    for (int n = 1000; n <= 8000; n *= 2) {
        custo_zera();
        custo_soma(preco, n);
        long p_soma = custo_passos;
        custo_zera();
        custo_busca(preco, n, 1);        // menor que todos: pior caso
        printf("%5d %5ld %6ld %10d\n", n, p_soma, custo_passos, (int)floor(log2(n)) + 1);
    }
    return 0;
}
