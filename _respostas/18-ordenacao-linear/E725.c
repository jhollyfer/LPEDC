// 0121 · Radix sort
// Exercício E725 · ★★★

#include <stdio.h>
#include <stdint.h>

// radix sort em base 256: 4 passadas, um byte por vez
void radix_256(uint32_t v[], uint32_t aux[], int n) {
    for (int b = 0; b < 4; b++) {
        int desloca = 8 * b;                     // 8 bits por byte
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[(v[i] >> desloca) & 0xFF]++;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            aux[--c[(v[i] >> desloca) & 0xFF]] = v[i];
        }
        for (int i = 0; i < n; i++) {
            v[i] = aux[i];
        }
    }
}

int main(void) {
    // downloads de cada app da loja no mês
    uint32_t downloads[] = {70000, 16777216, 300, 131072, 5, 1000000, 65535, 4000000000u};
    uint32_t aux[8];
    int n = 8;

    radix_256(downloads, aux, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%u" : " %u", (unsigned) downloads[i]);
    }
    printf("\n");
    return 0;
}
