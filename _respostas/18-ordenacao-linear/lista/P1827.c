// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1827 · ★★★ · n números de 0 a n² - 1 em tempo linear

#include <stdio.h>
#include <string.h>

#define N 1000

unsigned semente = 31;
long operacoes;

int sorteia(void) { // de 0 a N² - 1
    semente = semente * 1103515245u + 12345u;
    unsigned alto = (semente >> 16) % 1000;
    semente = semente * 1103515245u + 12345u;
    return (int)(alto * 1000 + (semente >> 16) % 1000);
}

void passada(int v[], int n, int div, int base) {
    static int c[N * N], saida[N];
    for (int d = 0; d < base; d++) c[d] = 0;
    for (int i = 0; i < n; i++) c[(v[i] / div) % base]++;
    for (int d = 1; d < base; d++) c[d] += c[d - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] / div) % base]] = v[i];
    memcpy(v, saida, n * sizeof(int));
    operacoes += 3L * n + base;
}

int main(void) {
    int lote[N], a[N], b[N], c[N];
    for (int i = 0; i < N; i++) lote[i] = sorteia();

    memcpy(a, lote, sizeof a);
    operacoes = 0;
    passada(a, N, 1, N * N); // counting direto: k = n²
    printf("counting direto (k = n²): %8ld operações\n", operacoes);

    memcpy(b, lote, sizeof b);
    operacoes = 0;
    for (int div = 1; div < N * N; div *= 10) passada(b, N, div, 10);
    printf("radix base 10 (6 passadas): %6ld operações\n", operacoes);

    memcpy(c, lote, sizeof c);
    operacoes = 0;
    passada(c, N, 1, N); // x % n
    passada(c, N, N, N); // x / n
    printf("radix base n (2 passadas):  %6ld operações\n", operacoes);

    int iguais = memcmp(a, b, sizeof a) == 0 && memcmp(a, c, sizeof a) == 0;
    printf("Iguais: %s | menor %d, maior %d\n", iguais ? "sim" : "não", c[0], c[N - 1]);
    return 0;
}
