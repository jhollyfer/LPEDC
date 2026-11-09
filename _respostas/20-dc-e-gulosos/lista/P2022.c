// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2022 · ★★★ · Strassen numa matriz 4 × 4

#include <stdio.h>

#define N 4

long mults = 0;

void soma(int n, int x[n][n], int y[n][n], int r[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = x[i][j] + y[i][j];
        }
    }
}

void subtrai(int n, int x[n][n], int y[n][n], int r[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = x[i][j] - y[i][j];
        }
    }
}

void pega(int n, int m[2 * n][2 * n], int l0, int c0, int b[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = m[l0 + i][c0 + j];
        }
    }
}

void poe(int n, int b[n][n], int m[2 * n][2 * n], int l0, int c0) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[l0 + i][c0 + j] = b[i][j];
        }
    }
}

void strassen(int n, int a[n][n], int b[n][n], int c[n][n]) {
    if (n == 1) {
        mults++;
        c[0][0] = a[0][0] * b[0][0];
        return;
    }
    int h = n / 2;
    int a11[h][h], a12[h][h], a21[h][h], a22[h][h];
    int b11[h][h], b12[h][h], b21[h][h], b22[h][h];
    pega(h, a, 0, 0, a11);
    pega(h, a, 0, h, a12);
    pega(h, a, h, 0, a21);
    pega(h, a, h, h, a22);
    pega(h, b, 0, 0, b11);
    pega(h, b, 0, h, b12);
    pega(h, b, h, 0, b21);
    pega(h, b, h, h, b22);
    int t1[h][h], t2[h][h];
    int m1[h][h], m2[h][h], m3[h][h], m4[h][h], m5[h][h], m6[h][h], m7[h][h];
    soma(h, a11, a22, t1);
    soma(h, b11, b22, t2);
    strassen(h, t1, t2, m1);
    soma(h, a21, a22, t1);
    strassen(h, t1, b11, m2);
    subtrai(h, b12, b22, t2);
    strassen(h, a11, t2, m3);
    subtrai(h, b21, b11, t2);
    strassen(h, a22, t2, m4);
    soma(h, a11, a12, t1);
    strassen(h, t1, b22, m5);
    subtrai(h, a21, a11, t1);
    soma(h, b11, b12, t2);
    strassen(h, t1, t2, m6);
    subtrai(h, a12, a22, t1);
    soma(h, b21, b22, t2);
    strassen(h, t1, t2, m7);
    int c11[h][h], c12[h][h], c21[h][h], c22[h][h];
    soma(h, m1, m4, c11);
    subtrai(h, c11, m5, c11);
    soma(h, c11, m7, c11);
    soma(h, m3, m5, c12);
    soma(h, m2, m4, c21);
    subtrai(h, m1, m2, c22);
    soma(h, c22, m3, c22);
    soma(h, c22, m6, c22);
    poe(h, c11, c, 0, 0);
    poe(h, c12, c, 0, h);
    poe(h, c21, c, h, 0);
    poe(h, c22, c, h, h);
}

int main(void) {
    int a[N][N] = {{1, 2, 0, 3}, {4, 1, 2, 0}, {0, 3, 1, 2}, {2, 0, 4, 1}};
    int b[N][N] = {{2, 1, 0, 1}, {0, 3, 1, 2}, {1, 0, 2, 3}, {4, 1, 1, 0}};
    int c[N][N], d[N][N];
    mults = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = 0;
            for (int k = 0; k < N; k++) {
                d[i][j] += a[i][k] * b[k][j];
                mults++;
            }
        }
    }
    long pela_definicao = mults;
    mults = 0;
    strassen(N, a, b, c);
    int iguais = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", c[i][j]);
            if (c[i][j] != d[i][j]) {
                iguais = 0;
            }
        }
        printf("\n");
    }
    printf("Definição: %ld multiplicações\n", pela_definicao);
    printf("Strassen: %ld multiplicações\n", mults);
    printf("Resultados %s\n", iguais ? "iguais" : "diferentes");
    return 0;
}
