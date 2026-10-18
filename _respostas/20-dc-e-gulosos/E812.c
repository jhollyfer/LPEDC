// 0136 · Código de Huffman
// Exercício E812 · ★☆☆

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {
    long freq[256] = {0};
    freq['N'] = 700; // normal
    freq['A'] = 200; // alerta
    freq['F'] = 80;  // falha
    freq['D'] = 20;  // desligado

    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);

    long bits = 0, total = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            printf("%c: %s\n", c, cod[c]);
            bits += freq[c] * (long)strlen(cod[c]);
            total += freq[c];
        }
    }
    printf("Huffman: %ld bits\n", bits);
    printf("Fixo de 2 bits: %ld bits\n", 2 * total);
    printf("Média: %.2f bits por leitura\n", (double)bits / total);
    huf_libera(raiz);
    return 0;
}
