// 0136 · Código de Huffman
// Exercício E815 · ★★★

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {
    const char *frase = "BANANA NA CABANA";
    long freq[256] = {0};
    for (const char *p = frase; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }
    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);

    // só os comprimentos importam: monta a lista (comprimento, símbolo)
    int simb[256], comp[256], k = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            simb[k] = c;
            comp[k] = (int)strlen(cod[c]);
            k++;
        }
    }
    // ordena por comprimento e, no empate, pelo símbolo (insertion sort)
    for (int i = 1; i < k; i++) {
        int s = simb[i], l = comp[i], j = i - 1;
        while (j >= 0 && (comp[j] > l || (comp[j] == l && simb[j] > s))) {
            simb[j + 1] = simb[j];
            comp[j + 1] = comp[j];
            j--;
        }
        simb[j + 1] = s;
        comp[j + 1] = l;
    }

    // código canônico: soma 1 e, quando o comprimento cresce, empurra à esquerda
    unsigned codigo = 0;
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            codigo = (codigo + 1) << (comp[i] - comp[i - 1]);
        }
        printf("'%c' %d bits: ", simb[i], comp[i]);
        for (int b = comp[i] - 1; b >= 0; b--) {
            putchar((codigo >> b) & 1 ? '1' : '0');
        }
        printf("  (Huffman deu %s)\n", cod[simb[i]]);
    }
    huf_libera(raiz);
    return 0;
}
