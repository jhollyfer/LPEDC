// A369 · Quantas ordens existem e quanto custa testar todas

#include <limits.h>
#include <stdio.h>

#define MAXN 16

int p[MAXN + 1];
long chamadas;

// força bruta recursiva: tenta todos os cortes, sem lembrar de nada
long melhor(int i, int j) {
    chamadas++;
    if (i == j) return 0;
    long menor = LONG_MAX;
    for (int k = i; k < j; k++) {
        long c = melhor(i, k) + melhor(k + 1, j) + (long)p[i - 1] * p[k] * p[j];
        if (c < menor) menor = c;
    }
    return menor;
}

// quantas parentizações diferentes uma cadeia de n matrizes tem
long ordens(int n) {
    long t[MAXN + 1] = {0};
    t[1] = 1;
    for (int m = 2; m <= n; m++)
        for (int k = 1; k < m; k++) t[m] += t[k] * t[m - k]; // corte depois da k-ésima
    return t[n];
}

int main(void) {
    for (int i = 0; i <= MAXN; i++) p[i] = 5 + (i * 7) % 11; // dimensões quaisquer
    printf(" n      ordens  chamadas (força bruta)  casas da PD\n");
    for (int n = 2; n <= MAXN; n += 2) {
        chamadas = 0;
        melhor(1, n);
        printf("%2d  %10ld  %22ld  %11d\n", n, ordens(n), chamadas, n * (n + 1) / 2);
    }
    return 0;
}
// Saída:
//  n      ordens  chamadas (força bruta)  casas da PD
//  2           1                       3            3
//  4           5                      27           10
//  6          42                     243           21
//  8         429                    2187           36
// 10        4862                   19683           55
// 12       58786                  177147           78
// 14      742900                 1594323          105
// 16     9694845                14348907          136
//
// A recursão sem memória recalcula as mesmas cadeias sem parar: as
// chamadas são exatamente 3^(n-1). A PD calcula cada casa m[i][j] uma vez
// só: n(n+1)/2 casas, com no máximo n cortes cada. Para n = 16, 14 milhões
// de chamadas contra 136 casas.
