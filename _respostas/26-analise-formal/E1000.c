// 0167 · Somatórios que saem de laços
// Exercício E1000 · ★★☆

#include <stdio.h>

// pirâmide de laranjas: a camada i (de cima para baixo) tem i × i laranjas
long laranjas(int camadas) {
    long total = 0;
    for (int i = 1; i <= camadas; i++) {
        for (int j = 0; j < i * i; j++) {
            total++;
        }
    }
    return total;
}

int main(void) {
    printf("  n  laranjas  n(n+1)(2n+1)/6\n");
    int ns[] = {3, 10, 100};
    for (int a = 0; a < 3; a++) {
        long n = ns[a];
        printf("%3ld %9ld %15ld\n", n, laranjas(ns[a]), n * (n + 1) * (2 * n + 1) / 6);
    }
    return 0;
}
