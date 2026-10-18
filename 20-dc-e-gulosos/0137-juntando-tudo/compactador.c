// compactador.c · implementação do compactador Huffman
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "compactador.h"
#include "huffman.h"

#define CABECALHO 4

// ---- escrever e ler bits soltos num arquivo de bytes ----

typedef struct {
    FILE *f;
    unsigned char byte; // os bits acumulados até agora
    int n;              // quantos bits já estão em byte (0 a 7)
} Bits;

static void escreve_bit(Bits *b, int bit) {
    b->byte = (unsigned char)((b->byte << 1) | bit); // entra pela direita
    b->n++;
    if (b->n == 8) {                                 // byte cheio: grava
        fputc(b->byte, b->f);
        b->byte = 0;
        b->n = 0;
    }
}

static void descarrega(Bits *b) {
    if (b->n > 0) {                                  // completa com zeros
        fputc((unsigned char)(b->byte << (8 - b->n)), b->f);
        b->byte = 0;
        b->n = 0;
    }
}

static int le_bit(Bits *b) {
    if (b->n == 0) {
        int c = fgetc(b->f);
        if (c == EOF) {
            return -1;
        }
        b->byte = (unsigned char)c;
        b->n = 8;
    }
    b->n--;
    return (b->byte >> b->n) & 1;                    // do mais alto para o mais baixo
}

// ---- compactar ----

long arq_tamanho(const char *nome) {
    FILE *f = fopen(nome, "rb");
    if (f == NULL) {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    long t = ftell(f);
    fclose(f);
    return t;
}

long huf_compacta(const char *entrada, const char *saida) {
    FILE *in = fopen(entrada, "rb");
    if (in == NULL) {
        return -1;
    }
    // 1ª passada: conta as frequências
    long freq[256] = {0};
    uint64_t total = 0;
    int c;
    while ((c = fgetc(in)) != EOF) {
        freq[c]++;
        total++;
    }

    FILE *out = fopen(saida, "wb");
    if (out == NULL) {
        fclose(in);
        return -1;
    }
    // o cabeçalho: assinatura, tamanho e frequências
    uint32_t f32[256];
    for (int i = 0; i < 256; i++) {
        f32[i] = (uint32_t)freq[i];
    }
    fwrite("HUF1", 1, CABECALHO, out);
    fwrite(&total, sizeof total, 1, out);
    fwrite(f32, sizeof f32[0], 256, out);

    // 2ª passada: troca cada byte pelo código dele
    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];
    huf_codigos(raiz, cod);
    rewind(in);
    Bits b = {out, 0, 0};
    while ((c = fgetc(in)) != EOF) {
        for (const char *p = cod[c]; *p != '\0'; p++) {
            escreve_bit(&b, *p - '0');
        }
    }
    descarrega(&b);

    huf_libera(raiz);
    fclose(in);
    long gravados = ftell(out);
    fclose(out);
    return gravados;
}

// ---- descompactar ----

long huf_descompacta(const char *entrada, const char *saida) {
    FILE *in = fopen(entrada, "rb");
    if (in == NULL) {
        return -1;
    }
    char assinatura[CABECALHO];
    uint64_t total;
    uint32_t f32[256];
    if (fread(assinatura, 1, CABECALHO, in) != CABECALHO || memcmp(assinatura, "HUF1", CABECALHO) != 0 ||
        fread(&total, sizeof total, 1, in) != 1 || fread(f32, sizeof f32[0], 256, in) != 256) {
        fclose(in);
        return -1;                       // não é um arquivo nosso
    }
    long freq[256];
    for (int i = 0; i < 256; i++) {
        freq[i] = (long)f32[i];
    }

    FILE *out = fopen(saida, "wb");
    if (out == NULL) {
        fclose(in);
        return -1;
    }
    NoHuf *raiz = huf_constroi(freq);   // mesmas frequências: mesma árvore
    Bits b = {in, 0, 0};
    for (uint64_t k = 0; k < total; k++) {
        const NoHuf *no = raiz;
        if (huf_folha(no)) {
            le_bit(&b);                  // um símbolo só: cada "0" é ele
        }
        while (!huf_folha(no)) {
            int bit = le_bit(&b);
            if (bit < 0) {
                break;                   // arquivo cortado
            }
            no = bit ? no->dir : no->esq;
        }
        fputc(no->simbolo, out);
    }
    huf_libera(raiz);
    fclose(in);
    long gravados = ftell(out);
    fclose(out);
    return gravados;
}
