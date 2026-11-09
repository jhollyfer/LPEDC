// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1714 · ★★☆ · Apertando √ na calculadora: T(n) = T(√n) + 1

#include <stdio.h>

typedef unsigned long long ull;

long chamadas;

ull raiz_inteira(ull n) { // maior r com r * r <= n
    ull ini = 0, fim = 4294967295ULL; // a raiz de n < 2^64 cabe em 32 bits
    while (ini < fim) {
        ull meio = ini + (fim - ini + 1) / 2;
        if (meio <= n / meio) ini = meio; // meio * meio <= n, sem estourar
        else fim = meio - 1;
    }
    return ini;
}

int teto_lg(ull n) { // menor h com 2^h >= n: o número de bits de n - 1
    int h = 0;
    for (ull m = n - 1; m; m >>= 1) h++;
    return h;
}

void raizes(ull n) {
    chamadas++;
    if (n <= 2) return;
    raizes(raiz_inteira(n));
}

int main(void) {
    ull ns[] = {4ULL, 16ULL, 256ULL, 65536ULL, 4294967296ULL, 18446744073709551615ULL};
    printf("%20s  chamadas  teto(lg teto(lg n)) + 1\n", "n");
    for (int k = 0; k < 6; k++) {
        chamadas = 0;
        raizes(ns[k]);
        printf("%20llu %9ld %12d\n", ns[k], chamadas, teto_lg((ull)teto_lg(ns[k])) + 1);
    }
    return 0;
}
