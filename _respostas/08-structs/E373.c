// 0063 · Enum
// Exercício E373 · ★☆☆
//
// Resposta: P = 1, M = 2, G = 3, GG = 10, XG = 11, XXG = 20, ESP = 21; e
// G + XG = 3 + 11 = 14.

#include <stdio.h>

enum Tamanho { P = 1, M, G, GG = 10, XG, XXG = GG * 2, ESP };

int main(void) {
    printf("%d %d %d %d %d %d %d\n", P, M, G, GG, XG, XXG, ESP);
    printf("%d\n", G + XG);
    return 0;
}
