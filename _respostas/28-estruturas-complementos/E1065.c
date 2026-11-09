// 0178 · Hash: divisão e multiplicação
// Exercício E1065 · ★★☆

#include <stdio.h>
#include "espalha.h"

int main(void) {
    int a[64] = {0}, b[61] = {0}, c[64] = {0};
    for (uint32_t i = 1; i <= 1000; i++) {
        uint32_t k = 64 * i; // as caixas vêm de 64 em 64
        a[esp_divisao(k, 64)]++;
        b[esp_divisao(k, 61)]++;
        c[esp_mult_desloca(k, 6)]++;
    }
    int usados_a = 0, usados_b = 0, usados_c = 0;
    for (int i = 0; i < 64; i++) {
        usados_a += a[i] > 0;
        usados_c += c[i] > 0;
    }
    for (int i = 0; i < 61; i++) {
        usados_b += b[i] > 0;
    }
    printf("divisão, m = 64:       %2d baldes usados, o mais cheio com %d\n", usados_a, esp_maior_balde(a, 64));
    printf("divisão, m = 61:       %2d baldes usados, o mais cheio com %d\n", usados_b, esp_maior_balde(b, 61));
    printf("multiplicação, m = 64: %2d baldes usados, o mais cheio com %d\n", usados_c, esp_maior_balde(c, 64));
    return 0;
}
