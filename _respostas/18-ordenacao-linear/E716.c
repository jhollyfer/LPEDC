// 0120 · Counting sort
// Exercício E716 · ★☆☆

#include <stdio.h>

#define MENOR 34
#define K 11 // tamanhos de 34 a 44

int main(void) {
    // pares no estoque de cada tamanho: c[0] é o 34, c[10] é o 44
    int c[K] = {2, 0, 3, 5, 4, 6, 3, 2, 0, 1, 1};

    for (int x = 1; x < K; x++) {
        c[x] += c[x - 1];
    }
    printf("total: %d pares\n", c[K - 1]);
    for (int x = 0; x < K; x++) {
        int comeco = x == 0 ? 0 : c[x - 1];
        if (c[x] - comeco == 1) {
            printf("tamanho %d: posição %d\n", x + MENOR, comeco);
        } else if (c[x] > comeco) {
            printf("tamanho %d: posições %d a %d\n", x + MENOR, comeco, c[x] - 1);
        }
    }
    return 0;
}
