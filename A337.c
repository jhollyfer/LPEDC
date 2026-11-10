// A337 · Prever antes de medir

#include <stdio.h>
#include <math.h>
#include "0169-custo.h"

// Mede com n = 1000, prevê n = 8000 só pela classe (sem rodar) e confere.
// n multiplicado por 8: Θ(n) → × 8, Θ(n²) → × 64,
// Θ(n log n) → × 8 · log(8000)/log(1000), Θ(log n) → + log2(8) = + 3.
int main(void) {
    static int v[8000];
    for (int i = 0; i < 8000; i++) {
        v[i] = 3 * i;
    }
    double fator_nlogn = 8.0 * log2(8000.0) / log2(1000.0);
    long med[4], prev[4], real[4];

    custo_zera(); custo_soma(v, 1000);         med[0] = custo_passos;
    custo_zera(); custo_busca(v, 1000, -1);    med[1] = custo_passos;
    custo_zera(); custo_pares(v, 1000, -1);    med[2] = custo_passos;
    custo_zera(); custo_merge(v, 1000);        med[3] = custo_passos;

    prev[0] = med[0] * 8;
    prev[1] = med[1] + 3;
    prev[2] = med[2] * 64;
    prev[3] = lround(med[3] * fator_nlogn);

    custo_zera(); custo_soma(v, 8000);         real[0] = custo_passos;
    custo_zera(); custo_busca(v, 8000, -1);    real[1] = custo_passos;
    custo_zera(); custo_pares(v, 8000, -1);    real[2] = custo_passos;
    custo_zera(); custo_merge(v, 8000);        real[3] = custo_passos;

    const char *nome[] = {"soma", "busca", "pares", "merge"};
    printf("função   n = 1000  previsto 8000  medido 8000  erro\n");
    for (int k = 0; k < 4; k++) {
        double erro = 100.0 * fabs((double)(real[k] - prev[k])) / real[k];
        printf("%-6s %10ld %14ld %12ld %4.1f%%\n", nome[k], med[k], prev[k], real[k], erro);
    }
    // pares erra 0,1%: a fórmula é n(n-1)/2, não exatamente n²/2.
    return 0;
}
// Saída:
// função   n = 1000  previsto 8000  medido 8000  erro
// soma         1000           8000         8000  0.0%
// busca          10             13           13  0.0%
// pares      499500       31968000     31996000  0.1%
// merge        9976         103833       103808  0.0%
