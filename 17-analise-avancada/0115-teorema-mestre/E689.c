// 0115 · Teorema mestre
// Exercício E689 · ★★★
//
// Multiplicar dois polinômios de n coeficientes (n potência de 2) dividindo
// cada um em duas metades, a(x) = a0 + a1·x^h e b(x) = b0 + b1·x^h, com
// h = n/2, pede os produtos a0·b0, a0·b1, a1·b0 e a1·b1. A função
// multiplica4 faz isso: T(n) = 4 T(n/2) + n, caso 1, Θ(n²) multiplicações.
//
// O truque de Karatsuba precisa de só TRÊS produtos:
//
//   p0 = a0·b0     p2 = a1·b1     p1 = (a0 + a1)·(b0 + b1) - p0 - p2
//
// e o resultado é p0 + p1·x^h + p2·x^(2h). Agora T(n) = 3 T(n/2) + n:
// ainda caso 1, mas Θ(n^(log₂ 3)) = Θ(n^1,585). Escreva multiplica3 e rode:
//
//   Saída esperada:
//   4 produtos: 5 16 34 60 61 52 32  (16 multiplicações)
//   3 produtos: 5 16 34 60 61 52 32  (9 multiplicações)
//   n =  64:   4096 contra   729 multiplicações, mesmo resultado
//   n = 128:  16384 contra  2187 multiplicações, mesmo resultado
//   n = 256:  65536 contra  6561 multiplicações, mesmo resultado
//
// Dicas:
// 1. Copie a estrutura de multiplica4: caso base n == 1 (conta 1
//    multiplicação) e, no caso geral, um bloco de rascunho com malloc.
// 2. O rascunho precisa de 3 produtos de 2h - 1 coeficientes e das somas
//    sa = a0 + a1 e sb = b0 + b1, de h coeficientes cada.
// 3. Monte o resultado como em multiplica4: r[i] += p0[i];
//    r[i + h] += p1[i]; r[i + 2h] += p2[i]. Não esqueça do free.
// 4. Resposta esperada: a saída acima. 16 = 4², 729 = 3⁶, 6561 = 3⁸: com
//    n = 2^j, são 4^j contra 3^j multiplicações.
//
// Escreva sua resposta abaixo (escreva multiplica3):

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
    (void)a; // apague estas duas linhas e escreva o resto
    (void)b;
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
