// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1721 · ★★★ · Matrizes por blocos: 8 chamadas contra as 7 de Strassen

#include <stdio.h>

#define N 16

int A[N][N], B[N][N], C[N][N], D[N][N];
long mults;

void mult(int ar, int ac, int br, int bc, int cr, int cc, int n) {
    if (n == 1) {
        C[cr][cc] += A[ar][ac] * B[br][bc];
        mults++;
        return;
    }
    int h = n / 2;
    for (int i = 0; i < 2; i++)     // linha de blocos de C
        for (int j = 0; j < 2; j++) // coluna de blocos de C
            for (int k = 0; k < 2; k++) // Cij += Aik Bkj
                mult(ar + i * h, ac + k * h, br + k * h, bc + j * h, cr + i * h, cc + j * h, h);
}

int main(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = (i * 3 + j) % 7;     // transferências
            B[i][j] = (i + 2 * j) % 5 + 1; // custos em reais
        }

    for (int n = 2; n <= N; n *= 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                D[i][j] = 0;
                for (int k = 0; k < n; k++) D[i][j] += A[i][k] * B[k][j]; // laço triplo
            }
        mults = 0;
        mult(0, 0, 0, 0, 0, 0, n);
        int iguais = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (C[i][j] != D[i][j]) iguais = 0;
        printf("n = %2d: %4ld multiplicações (n³ = %4d), igual ao laço triplo: %s\n", n, mults, n * n * n,
               iguais ? "sim" : "não");
    }

    printf("    n          8 blocos   Strassen  razão\n");
    long m8 = 1, m7 = 1; // M(1) = S(1) = 1
    for (int n = 2; n <= 1024; n *= 2) {
        m8 *= 8; // M(n) = 8 M(n/2)
        m7 *= 7; // S(n) = 7 S(n/2)
        printf("%5d %17ld %10ld %6.2f\n", n, m8, m7, (double)m8 / m7);
    }
    return 0;
}
