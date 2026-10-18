// 0115 · Teorema mestre
// Exercício E686 · ★☆☆

#include <stdio.h>

// cada chamada faz n unidades de trabalho e chama 3 vezes com metade
long trabalho(int n) {
    if (n == 1) {
        return 1;
    }
    long total = n;
    for (int i = 0; i < 3; i++) {
        total += trabalho(n / 2);
    }
    return total;
}

int main(void) {
    long anterior = trabalho(32);
    printf("    n     T(n)  T(n)/T(n/2)\n");
    for (int n = 64; n <= 4096; n *= 2) {
        long t = trabalho(n);
        printf("%5d %8ld %8.3f\n", n, t, (double)t / anterior);
        anterior = t;
    }
    return 0;
}
