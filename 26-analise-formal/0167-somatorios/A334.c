// A334 · As lâmpadas do corredor: a soma harmônica

#include <stdio.h>
#include <math.h>

#define MAX 100000

// O corredor tem n lâmpadas apagadas. O zelador p (p = 1..n) passa e
// aperta o interruptor das lâmpadas p, 2p, 3p, ... Quantos apertos no total?
// O zelador p faz n/p apertos: n/1 + n/2 + ... + n/n.
long apertos(int n, int *acesas) {
    static int lampada[MAX + 1];
    for (int k = 1; k <= n; k++) {
        lampada[k] = 0;
    }
    long total = 0;
    for (int p = 1; p <= n; p++) {
        for (int k = p; k <= n; k += p) {
            lampada[k] = !lampada[k];
            total++;
        }
    }
    *acesas = 0;
    for (int k = 1; k <= n; k++) {
        *acesas += lampada[k];
    }
    return total;
}

int main(void) {
    printf("     n   apertos   n·H(n)   n ln n  acesas\n");
    for (int n = 10; n <= MAX; n *= 10) {
        double h = 0;                    // H(n) = 1 + 1/2 + ... + 1/n
        for (int p = 1; p <= n; p++) {
            h += 1.0 / p;
        }
        int acesas;
        long a = apertos(n, &acesas);
        printf("%6d %9ld %8.0f %8.0f %7d\n", n, a, n * h, n * log(n), acesas);
    }
    // Acesas: só as lâmpadas de número quadrado perfeito (1, 4, 9, ...),
    // que têm uma quantidade ímpar de divisores.
    return 0;
}
// Saída:
//      n   apertos   n·H(n)   n ln n  acesas
//     10        27       29       23       3
//    100       482      519      461      10
//   1000      7069     7485     6908      31
//  10000     93668    97876    92103     100
// 100000   1166750  1209015  1151293     316
