// 0136 · Código de Huffman
// Exercício E811 · ★☆☆

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {
    const char *frase = "PAPAI PAGOU A PIPOCA";
    long freq[256] = {0};
    for (const char *p = frase; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }
    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);

    long bits = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            printf("'%c' %ld: %s\n", c, freq[c], cod[c]);
            bits += freq[c] * (long)strlen(cod[c]);
        }
    }
    size_t original = 8 * strlen(frase);
    printf("%ld bits de %zu (%.1f%%)\n", bits, original, 100.0 * bits / original);
    huf_libera(raiz);
    return 0;
}
