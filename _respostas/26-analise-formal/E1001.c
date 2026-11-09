// 0167 · Somatórios que saem de laços
// Exercício E1001 · ★★★

#include <stdio.h>

int main(void) {
    long n = 1024;

    long a = 0;                          // laço dependente: j < i
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            a++;
        }
    }
    long formula_a = n * (n - 1) / 2;    // era n(n+1)/2: sobravam n

    long b = 0;                          // laço que dobra
    for (long t = 1; t < n; t *= 2) {
        for (long j = 0; j < t; j++) {
            b++;
        }
    }
    long formula_b = n - 1;              // 1 + 2 + ... + 512 = 1023, não n log n

    long c = 0;                          // de 3 em 3
    for (long i = 0; i < n; i += 3) {
        c++;
    }
    long formula_c = (n + 2) / 3;        // teto de n/3, não n/3 truncado

    printf("a: %ld e %ld, confere: %s\n", a, formula_a, a == formula_a ? "sim" : "não");
    printf("b: %ld e %ld, confere: %s\n", b, formula_b, b == formula_b ? "sim" : "não");
    printf("c: %ld e %ld, confere: %s\n", c, formula_c, c == formula_c ? "sim" : "não");
    return 0;
}
