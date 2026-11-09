// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1726 · ★★★ · Busca na tabela de fretes: escada contra quadrantes

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 64

int frete[MAX][MAX];
long comparacoes;

bool escada(int n, int x) {
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        comparacoes++;
        if (frete[i][j] == x) return true;
        if (x < frete[i][j]) j--; // tudo abaixo na coluna j é maior ainda
        else i++;                  // tudo à esquerda na linha i é menor ainda
    }
    return false;
}

bool quadrantes(int l0, int c0, int l1, int c1, int x) {
    if (l0 > l1 || c0 > c1) return false; // retângulo vazio
    int mi = (l0 + l1) / 2, mj = (c0 + c1) / 2;
    comparacoes++;
    int m = frete[mi][mj];
    if (m == x) return true;
    if (x < m) // fora do quadrante de baixo à direita
        return quadrantes(l0, c0, mi - 1, mj - 1, x) || quadrantes(l0, mj, mi - 1, c1, x) ||
               quadrantes(mi, c0, l1, mj - 1, x);
    // fora do quadrante de cima à esquerda
    return quadrantes(l0, mj + 1, mi, c1, x) || quadrantes(mi + 1, c0, l1, mj, x) ||
           quadrantes(mi + 1, mj + 1, l1, c1, x);
}

int main(void) {
    printf(" n  escada  2n-1  quadrantes  n^lg3  concordam\n");
    for (int n = 8; n <= MAX; n *= 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) frete[i][j] = 10 * i + 7 * j;
        long pior_e = 0, pior_q = 0;
        bool concordam = true;
        for (int x = 0; x <= frete[n - 1][n - 1]; x++) {
            comparacoes = 0;
            bool a = escada(n, x);
            if (comparacoes > pior_e) pior_e = comparacoes;
            comparacoes = 0;
            bool b = quadrantes(0, 0, n - 1, n - 1, x);
            if (comparacoes > pior_q) pior_q = comparacoes;
            if (a != b) concordam = false;
        }
        printf("%2d %7ld %5d %11ld %6.0f %10s\n", n, pior_e, 2 * n - 1, pior_q, pow(n, log2(3.0)),
               concordam ? "sim" : "não");
    }
    return 0;
}
