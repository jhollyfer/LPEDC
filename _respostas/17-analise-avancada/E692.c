// 0116 · Análise amortizada
// Exercício E692 · ★☆☆

#include <stdio.h>

// capacidade começa em 'passo' e cresce somando 'passo'
long copias_soma(long n, long passo) {
    long cap = passo, tam = 0, copias = 0;
    for (long i = 0; i < n; i++) {
        if (tam == cap) {
            copias += tam;    // copia todos para o vetor novo
            cap += passo;
        }
        tam++;
    }
    return copias;
}

// capacidade começa em 1 e dobra
long copias_dobra(long n) {
    long cap = 1, tam = 0, copias = 0;
    for (long i = 0; i < n; i++) {
        if (tam == cap) {
            copias += tam;
            cap *= 2;
        }
        tam++;
    }
    return copias;
}

int main(void) {
    printf("     n      soma 10     dobra\n");
    for (long n = 1000; n <= 100000; n *= 10) {
        printf("%6ld %12ld %9ld\n", n, copias_soma(n, 10), copias_dobra(n));
    }
    return 0;
}
