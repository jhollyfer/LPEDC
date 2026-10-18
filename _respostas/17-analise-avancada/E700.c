// 0117 · Limite inferior da ordenação
// Exercício E700 · ★★☆

#include <stdio.h>

// pior caso do merge sort: W(n) = W(⌈n/2⌉) + W(⌊n/2⌋) + (n - 1), W(1) = 0
long pior_merge(int n) {
    if (n <= 1) {
        return 0;
    }
    return pior_merge((n + 1) / 2) + pior_merge(n / 2) + (n - 1);
}

int teto_log2(unsigned long long x) {
    int h = 0;
    unsigned long long folhas = 1;
    while (folhas < x) {
        folhas *= 2;
        h++;
    }
    return h;
}

int main(void) {
    unsigned long long fat = 1;
    printf(" n  limite  merge  insertion\n");
    for (int n = 1; n <= 16; n++) {
        fat *= n;
        printf("%2d  %6d  %5ld  %9d\n", n, teto_log2(fat), pior_merge(n), n * (n - 1) / 2);
    }
    return 0;
}
