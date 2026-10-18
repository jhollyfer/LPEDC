// A271 · Decodificar descendo a árvore (e o estrago de um bit errado)

#include <stdio.h>
#include <string.h>
#include "huffman.h"

// lê os bits: 0 desce à esquerda, 1 à direita; ao chegar numa folha,
// escreve o símbolo e volta para a raiz
void decodifica(const NoHuf *raiz, const char *bits) {
    const NoHuf *no = raiz;
    for (const char *b = bits; *b != '\0'; b++) {
        no = (*b == '0') ? no->esq : no->dir;
        if (huf_folha(no)) {
            putchar(no->simbolo);
            no = raiz;
        }
    }
    putchar('\n');
}

int main(void) {
    const char *frase = "O RATO ROEU A ROUPA";
    long freq[256] = {0};
    for (const char *p = frase; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }
    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);

    // quem envia: concatena os códigos
    char bits[256] = "";
    for (const char *p = frase; *p != '\0'; p++) {
        strcat(bits, cod[(unsigned char)*p]);
    }
    printf("Bits (%zu): %s\n", strlen(bits), bits);

    // quem recebe: só com a árvore e os bits, refaz a frase
    printf("Decodificado: ");
    decodifica(raiz, bits);

    // um bit trocado na transmissão: o leitor perde o passo, junta pedaços
    // de códigos vizinhos e só se reencontra algumas letras depois. Até o
    // número de letras muda. Arquivo compactado não tolera bit errado.
    bits[7] = (bits[7] == '0') ? '1' : '0';
    printf("Com o bit 7 trocado: ");
    decodifica(raiz, bits);

    huf_libera(raiz);
    return 0;
}
// Saída:
// Bits (54): 010011010111100100110011000111100101001100111111001101
// Decodificado: O RATO ROEU A ROUPA
// Com o bit 7 trocado: O R U PPEU A ROUPA
