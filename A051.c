// A051 · Mesma semente, mesmo sorteio

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // bingo da quermesse: 5 bolas de 1 a 75 (a + rand() % (b - a + 1))
    srand(2026);
    printf("Semente 2026:        ");
    for (int i = 0; i < 5; i++) {
        printf("%3d", 1 + rand() % 75);
    }
    printf("\n");

    // a mesma semente de novo: a sequência recomeça do mesmo ponto
    srand(2026);
    printf("Semente 2026 de novo:");
    for (int i = 0; i < 5; i++) {
        printf("%3d", 1 + rand() % 75);
    }
    printf("\n");

    // outra semente: outra sequência
    srand(2027);
    printf("Semente 2027:        ");
    for (int i = 0; i < 5; i++) {
        printf("%3d", 1 + rand() % 75);
    }
    printf("\n");
    return 0;
}
// Saída (glibc, Linux; em outro sistema os números podem ser outros,
// mas as duas primeiras linhas continuam iguais entre si):
// Semente 2026:         38 73 74 70 62
// Semente 2026 de novo: 38 73 74 70 62
// Semente 2027:         54 29  7  5 53
