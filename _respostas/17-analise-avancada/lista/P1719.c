// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1719 · ★★☆ · Quantas chamadas para escolher o time do futsal

#include <stdio.h>

long chamadas, multiplicacoes;

long comb(int n, int k) {
    chamadas++;
    if (k == 0 || k == n) return 1;
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

long comb_linha(int n, int k) {
    long r = 1;
    for (int i = 1; i <= k; i++) {
        r = r * (n - i + 1) / i; // r vale C(n, i): a divisão é exata
        multiplicacoes++;
    }
    return r;
}

int main(void) {
    int pares[][2] = {{6, 2}, {10, 5}, {20, 10}, {26, 13}};
    printf(" n  k     C(n,k)  chamadas  2C-1      linha  mult\n");
    for (int t = 0; t < 4; t++) {
        int n = pares[t][0], k = pares[t][1];
        chamadas = multiplicacoes = 0;
        long c = comb(n, k);
        long l = comb_linha(n, k);
        printf("%2d %2d %10ld %9ld %9ld %10ld %4ld\n", n, k, c, chamadas, 2 * c - 1, l, multiplicacoes);
    }
    return 0;
}
