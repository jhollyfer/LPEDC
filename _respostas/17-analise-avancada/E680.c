// 0114 · Recorrências e árvore de recursão
// Exercício E680 · ★☆☆

#include <stdio.h>

// A(n) = A(n/2) + 1, A(1) = 1
long rec_a(long n) {
    if (n == 1) {
        return 1;
    }
    return rec_a(n / 2) + 1;
}

// B(n) = 2 B(n/2) + 1, B(1) = 1
long rec_b(long n) {
    if (n == 1) {
        return 1;
    }
    return 2 * rec_b(n / 2) + 1;
}

// C(n) = 2 C(n/2) + n, C(1) = 1
long rec_c(long n) {
    if (n == 1) {
        return 1;
    }
    return 2 * rec_c(n / 2) + n;
}

int main(void) {
    printf(" n | A(n) log+1 | B(n) 2n-1 | C(n) n log n + n\n");
    long lg = 0; // log2 de n
    for (long n = 1; n <= 64; n *= 2, lg++) {
        printf("%2ld | %4ld %5ld | %4ld %4ld | %4ld %5ld\n",
               n, rec_a(n), lg + 1, rec_b(n), 2 * n - 1, rec_c(n), n * lg + n);
    }
    return 0;
}
