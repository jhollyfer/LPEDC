// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1928 · ★★★ · A próxima trinca pelos bits

#include <stdio.h>

#define N 5
#define K 3

const char *nome[N] = {"Ana", "Bia", "Cris", "Dani", "Eli"};

unsigned proxima(unsigned x) {
    unsigned c = x & -x;
    unsigned r = x + c;
    return (((r ^ x) >> 2) / c) | r;
}

void mostra(unsigned x) {
    for (int b = N - 1; b >= 0; b--) {
        printf("%u", (x >> b) & 1u);
    }
    printf(":");
    for (int i = 0; i < N; i++) {
        if (x & (1u << i)) {
            printf(" %s", nome[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int total = 0;
    for (unsigned x = (1u << K) - 1; x < (1u << N); x = proxima(x)) {
        mostra(x);
        total++;
    }
    printf("Total: %d trincas\n", total);
    return 0;
}
