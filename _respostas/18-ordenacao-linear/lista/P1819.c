// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1819 · ★★☆ · Qual base para o radix? Conte as operações

#include <stdio.h>
#include <string.h>

#define MAXN 100000

unsigned semente = 99;
long operacoes;

unsigned sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    unsigned alto = semente >> 16;
    semente = semente * 1103515245u + 12345u;
    return (alto << 16) | (semente >> 16); // 32 bits
}

int radix(unsigned v[], int n, int r) { // devolve o número de passadas
    static unsigned saida[MAXN];
    static int c[1 << 16];
    int b = 1 << r, passadas = (32 + r - 1) / r;
    for (int p = 0; p < passadas; p++) {
        int s = p * r;
        for (int d = 0; d < b; d++) c[d] = 0;
        for (int i = 0; i < n; i++) c[(v[i] >> s) & (b - 1)]++;
        for (int d = 1; d < b; d++) c[d] += c[d - 1];
        for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] >> s) & (b - 1)]] = v[i];
        memcpy(v, saida, n * sizeof *v);
        operacoes += 3L * n + b;
    }
    return passadas;
}

int main(void) {
    static unsigned original[MAXN], v[MAXN];
    for (int i = 0; i < MAXN; i++) original[i] = sorteia();

    int rs[] = {1, 4, 8, 16};
    for (int n = MAXN; n >= 1000; n /= 100) {
        printf("n = %d\n", n);
        for (int k = 0; k < 4; k++) {
            memcpy(v, original, n * sizeof *v);
            operacoes = 0;
            int p = radix(v, n, rs[k]);
            int ok = 1;
            for (int i = 1; i < n; i++)
                if (v[i - 1] > v[i]) ok = 0;
            printf("  r = %2d: %2d passadas, %7ld operações (%5.1f por item), %s\n", rs[k], p, operacoes,
                   (double)operacoes / n, ok ? "ordenado" : "ERRO");
        }
    }
    return 0;
}
