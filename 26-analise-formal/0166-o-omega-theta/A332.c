// A332 · Constante ou não: olhando a razão

#include <stdio.h>
#include <math.h>

// Se a razão f(n) / g(n) fica abaixo de um número fixo quando n cresce,
// esse número serve de c: f = O(g). Se a razão cresce sem parar, nenhum c
// serve: f não é O(g).
int main(void) {
    printf(" n  2^(n+1)/2^n  4^n/2^n\n");
    for (int n = 10; n <= 50; n += 10) {
        double r1 = pow(2, n + 1) / pow(2, n);   // sempre 2
        double r2 = pow(4, n) / pow(2, n);       // é 2^n: explode
        printf("%2d %12.0f %8.2e\n", n, r1, r2);
    }

    printf("\n     n  log(n²)/log n  n²/(100n)  (n log n)/n\n");
    for (long n = 10; n <= 1000000; n *= 10) {
        double r3 = log2((double)n * n) / log2((double)n); // sempre 2
        double r4 = (double)n * n / (100.0 * n);           // n/100
        double r5 = n * log2((double)n) / n;               // log n
        printf("%7ld %13.1f %10.1f %12.1f\n", n, r3, r4, r5);
    }
    // 2^(n+1) = O(2^n) com c = 2 e log(n²) = Θ(log n) com c = 2.
    // 4^n não é O(2^n), n² não é O(100n) e n log n não é O(n):
    // as três razões passam de qualquer c que você escolher.
    return 0;
}
// Saída:
//  n  2^(n+1)/2^n  4^n/2^n
// 10            2 1.02e+03
// 20            2 1.05e+06
// 30            2 1.07e+09
// 40            2 1.10e+12
// 50            2 1.13e+15
//
//      n  log(n²)/log n  n²/(100n)  (n log n)/n
//      10           2.0        0.1          3.3
//     100           2.0        1.0          6.6
//    1000           2.0       10.0         10.0
//   10000           2.0      100.0         13.3
//  100000           2.0     1000.0         16.6
// 1000000           2.0    10000.0         19.9
