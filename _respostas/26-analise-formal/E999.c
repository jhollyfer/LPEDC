// 0167 · Somatórios que saem de laços
// Exercício E999 · ★★☆

#include <stdio.h>

// conta as comissões de 3 moradores diferentes (a ordem não importa)
long trios(int n) {
    long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                total++;
            }
        }
    }
    return total;
}

int main(void) {
    printf("  n   trios  n(n-1)(n-2)/6\n");
    int ns[] = {10, 30, 100};
    for (int a = 0; a < 3; a++) {
        long n = ns[a];
        printf("%3ld %7ld %14ld\n", n, trios(ns[a]), n * (n - 1) * (n - 2) / 6);
    }
    return 0;
}
