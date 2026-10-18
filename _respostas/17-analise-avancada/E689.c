// 0115 · Teorema mestre
// Exercício E689 · ★★★

#include <stdio.h>
#include <stdlib.h>

long mults = 0; // multiplicações de coeficientes

// r[0..2n-2] = a[0..n-1] * b[0..n-1], com 4 produtos: T(n) = 4 T(n/2) + n
void multiplica4(const long a[], const long b[], int n, long r[]) {
    for (int i = 0; i < 2 * n - 1; i++) {
        r[i] = 0;
    }
    if (n == 1) {
        r[0] = a[0] * b[0];
        mults++;
        return;
    }
    int h = n / 2;
    long *p = malloc(4 * (2 * h - 1) * sizeof *p);
    if (p == NULL) {
        exit(1);
    }
    long *p00 = p, *p01 = p + (2 * h - 1), *p10 = p + 2 * (2 * h - 1), *p11 = p + 3 * (2 * h - 1);
    multiplica4(a, b, h, p00);         // a0 · b0
    multiplica4(a, b + h, h, p01);     // a0 · b1
    multiplica4(a + h, b, h, p10);     // a1 · b0
    multiplica4(a + h, b + h, h, p11); // a1 · b1
    for (int i = 0; i < 2 * h - 1; i++) {
        r[i] += p00[i];
        r[i + h] += p01[i] + p10[i];
        r[i + 2 * h] += p11[i];
    }
    free(p);
}

// Karatsuba: 3 produtos, T(n) = 3 T(n/2) + n
void multiplica3(const long a[], const long b[], int n, long r[]) {
    for (int i = 0; i < 2 * n - 1; i++) {
        r[i] = 0;
    }
    if (n == 1) {
        r[0] = a[0] * b[0];
        mults++;
        return;
    }
    int h = n / 2;
    int t = 2 * h - 1;                 // tamanho de cada produto parcial
    long *m = malloc((3 * t + 2 * h) * sizeof *m);
    if (m == NULL) {
        exit(1);
    }
    long *p0 = m, *p1 = m + t, *p2 = m + 2 * t;
    long *sa = m + 3 * t, *sb = sa + h;
    for (int i = 0; i < h; i++) {
        sa[i] = a[i] + a[i + h];       // a0 + a1
        sb[i] = b[i] + b[i + h];       // b0 + b1
    }
    multiplica3(a, b, h, p0);          // a0 · b0
    multiplica3(a + h, b + h, h, p2);  // a1 · b1
    multiplica3(sa, sb, h, p1);        // (a0 + a1)(b0 + b1)
    for (int i = 0; i < t; i++) {
        p1[i] -= p0[i] + p2[i];        // sobra a0·b1 + a1·b0
        r[i] += p0[i];
        r[i + h] += p1[i];
        r[i + 2 * h] += p2[i];
    }
    free(m);
}

int main(void) {
    long a[4] = {1, 2, 3, 4}; // 1 + 2x + 3x² + 4x³
    long b[4] = {5, 6, 7, 8}; // 5 + 6x + 7x² + 8x³
    long r[7];

    mults = 0;
    multiplica4(a, b, 4, r);
    printf("4 produtos:");
    for (int i = 0; i < 7; i++) {
        printf(" %ld", r[i]);
    }
    printf("  (%ld multiplicações)\n", mults);

    mults = 0;
    multiplica3(a, b, 4, r);
    printf("3 produtos:");
    for (int i = 0; i < 7; i++) {
        printf(" %ld", r[i]);
    }
    printf("  (%ld multiplicações)\n", mults);

    // polinômios grandes: confere que dão igual e compara as contagens
    int n = 256;
    long *x = malloc(n * sizeof *x), *y = malloc(n * sizeof *y);
    long *r4 = malloc((2 * n - 1) * sizeof *r4), *r3 = malloc((2 * n - 1) * sizeof *r3);
    if (x == NULL || y == NULL || r4 == NULL || r3 == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        x[i] = i % 10;
        y[i] = (3 * i) % 7;
    }
    for (int tam = 64; tam <= n; tam *= 2) {
        mults = 0;
        multiplica4(x, y, tam, r4);
        long m4 = mults;
        mults = 0;
        multiplica3(x, y, tam, r3);
        int iguais = 1;
        for (int i = 0; i < 2 * tam - 1; i++) {
            if (r4[i] != r3[i]) {
                iguais = 0;
            }
        }
        printf("n = %3d: %6ld contra %5ld multiplicações, %s\n", tam, m4, mults, iguais ? "mesmo resultado" : "DIFERENTE");
    }
    free(x);
    free(y);
    free(r4);
    free(r3);
    return 0;
}
