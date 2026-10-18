// 0138 · Memoização
// Exercício E823 · ★☆☆

#include <stdio.h>

#define N 10

int main(void) {
    long long t[N + 1];
    t[0] = 1;
    t[1] = 1;
    t[2] = 2;
    for (int i = 3; i <= N; i++) {
        t[i] = t[i - 1] + t[i - 2] + t[i - 3]; // último passo de 1, 2 ou 3
    }

    printf("t:");
    for (int i = 0; i <= N; i++) {
        printf(" %lld", t[i]);
    }
    printf("\nJeitos de subir %d degraus: %lld\n", N, t[N]);
    return 0;
}
