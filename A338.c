// A338 · Três jeitos de achar o par: tempo contra espaço

#include <stdio.h>
#include <stdlib.h>
#include "0169-custo.h"

#define N 2000
#define VALOR_MAX 10000

unsigned semente = 7;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    // vales-presente da loja (em reais); existe um par que soma o alvo?
    static int vale[N], copia[N];
    for (int i = 0; i < N; i++) {
        vale[i] = 1 + sorteia(VALOR_MAX);
        copia[i] = vale[i];
    }
    int alvo = 2 * VALOR_MAX + 1;        // nunca existe: o pior caso dos três

    // 1. testar todos os pares: Θ(n²) tempo, Θ(1) espaço
    custo_zera();
    long pares = custo_pares(vale, N, alvo);
    printf("pares:    %8ld passos, %6zu bytes, achou: %s\n", custo_passos, custo_bytes,
           pares > 0 ? "sim" : "não");

    // 2. ordenar (merge sort) e andar com duas pontas: Θ(n log n), Θ(n)
    custo_zera();
    custo_merge(copia, N);
    int i = 0, j = N - 1, achou = 0;
    while (i < j && !achou) {
        custo_passos++;
        int s = copia[i] + copia[j];
        if (s == alvo) {
            achou = 1;
        } else if (s < alvo) {
            i++;
        } else {
            j--;
        }
    }
    printf("ordenar:  %8ld passos, %6zu bytes, achou: %s\n", custo_passos, custo_bytes,
           achou ? "sim" : "não");

    // 3. tabela de presença dos valores: Θ(n) passos, Θ(VALOR_MAX) espaço
    long passos3 = 0;
    char *visto = calloc(VALOR_MAX + 1, 1);
    if (visto == NULL) {
        return 1;
    }
    achou = 0;
    for (int k = 0; k < N && !achou; k++) {
        passos3++;
        int falta = alvo - vale[k];
        if (falta >= 1 && falta <= VALOR_MAX && visto[falta]) {
            achou = 1;
        }
        visto[vale[k]] = 1;
    }
    free(visto);
    printf("tabela:   %8ld passos, %6d bytes, achou: %s\n", passos3, VALOR_MAX + 1,
           achou ? "sim" : "não");
    return 0;
}
// Saída:
// pares:     1999000 passos,      0 bytes, achou: não
// ordenar:     23951 passos,   8000 bytes, achou: não
// tabela:       2000 passos,  10001 bytes, achou: não
