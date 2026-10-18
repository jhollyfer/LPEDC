// 0137 · Juntando tudo
// Exercício E822 · ★★★

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {
    const char *texto = "O PADEIRO PEDIU PAPEL PARDO PARA O PAO DE PAPAI";
    long freq[256] = {0};
    long n = 0;
    for (const char *p = texto; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
        n++;
    }
    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);

    double bits = 0, entropia = 0;
    int k = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            double p = (double)freq[c] / n;
            bits += freq[c] * (double)strlen(cod[c]);
            entropia -= p * log2(p);  // H = soma de -p log2 p
            k++;
        }
    }
    printf("%d símbolos em %ld letras\n", k, n);
    printf("Código fixo:  %d bits por letra\n", (int)ceil(log2(k)));
    printf("Huffman:      %.3f bits por letra\n", bits / n);
    printf("Entropia:     %.3f bits por letra\n", entropia);
    huf_libera(raiz);
    return 0;
}
