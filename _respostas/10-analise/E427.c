// 0072 · Notação O: como o custo cresce
// Exercício E427 · ★☆☆

#include <stdio.h>

long trecho_a(int n) {
    long x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            x++;
        }
    }
    return x;
}

long trecho_b(int n) {
    long x = 0;
    for (int i = 1; i < n; i = i * 2) {
        x++;
    }
    return x;
}

long trecho_c(int n) {
    long x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            x++;
        }
    }
    return x;
}

long trecho_d(int n) {
    (void)n; // x = v[n / 2] + v[0]: uma conta só, qualquer que seja n
    return 1;
}

long trecho_e(int n) {
    long x = 0;
    for (int i = 0; i < n; i++) {
        x++;
    }
    for (int j = 0; j < n; j++) {
        x++;
    }
    return x;
}

long trecho_f(int n) {
    long x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n; j > 1; j = j / 2) {
            x++;
        }
    }
    return x;
}

int main(void) {
    printf("%-14s %6s %8s\n", "trecho", "n=16", "n=1024");
    printf("%-14s %6ld %8ld\n", "a) O(n)", trecho_a(16), trecho_a(1024));
    printf("%-14s %6ld %8ld\n", "b) O(log n)", trecho_b(16), trecho_b(1024));
    printf("%-14s %6ld %8ld\n", "c) O(n^2)", trecho_c(16), trecho_c(1024));
    printf("%-14s %6ld %8ld\n", "d) O(1)", trecho_d(16), trecho_d(1024));
    printf("%-14s %6ld %8ld\n", "e) O(n)", trecho_e(16), trecho_e(1024));
    printf("%-14s %6ld %8ld\n", "f) O(n log n)", trecho_f(16), trecho_f(1024));
    return 0;
}
