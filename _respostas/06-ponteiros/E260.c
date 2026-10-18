// 0044 · Memória e endereços
// Exercício E260 · ★☆☆

#include <stdio.h>

int main(void) {
    int gols = 3;
    double media = 1.5;
    char result = 'V';

    printf("gols   = %d   em %p, %zu bytes\n", gols, (void *)&gols, sizeof gols);
    printf("media  = %.1f em %p, %zu bytes\n", media, (void *)&media, sizeof media);
    printf("result = %c   em %p, %zu bytes\n", result, (void *)&result, sizeof result);

    size_t total = sizeof gols + sizeof media + sizeof result;
    printf("total: %zu bytes\n", total);
    return 0;
}
