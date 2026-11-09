// 0178 · Hash: divisão e multiplicação
// Exercício E1067 · ★★★

#include <stdint.h>
#include <stdio.h>

#define P 4
#define M (1 << P)

uint32_t balde(uint32_t k) {
    uint32_t produto = k * 2654435769u; // mod 2^32
    return produto >> (32 - P); // os P bits mais altos
}

int main(void) {
    int conta[M] = {0};
    printf("baldes:");
    for (uint32_t k = 16; k <= 160; k += 16) {
        uint32_t b = balde(k);
        conta[b]++;
        printf(" %u", (unsigned)b);
    }
    int maior = 0;
    for (int i = 0; i < M; i++) {
        if (conta[i] > maior) {
            maior = conta[i];
        }
    }
    printf("\nbalde mais cheio: %d\n", maior);
    return 0;
}
