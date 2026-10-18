// huffman.c · implementação do TAD árvore de Huffman
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

// ---- heap de mínimo de ponteiros para nó (só este arquivo enxerga) ----

typedef struct {
    NoHuf *v[256];
    int n;
} Heap;

// a é "menor" que b: menos frequente; empate, menor ordem
static int menor(const NoHuf *a, const NoHuf *b) {
    if (a->freq != b->freq) {
        return a->freq < b->freq;
    }
    return a->ordem < b->ordem;
}

static void troca(NoHuf **a, NoHuf **b) {
    NoHuf *t = *a;
    *a = *b;
    *b = t;
}

static void poe(Heap *h, NoHuf *no) {
    int i = h->n++;
    h->v[i] = no;
    while (i > 0 && menor(h->v[i], h->v[(i - 1) / 2])) {
        troca(&h->v[i], &h->v[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

static NoHuf *tira(Heap *h) {
    NoHuf *topo = h->v[0];
    h->v[0] = h->v[--h->n];
    int i = 0;
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;
        if (f + 1 < h->n && menor(h->v[f + 1], h->v[f])) {
            f++;
        }
        if (!menor(h->v[f], h->v[i])) {
            break;
        }
        troca(&h->v[i], &h->v[f]);
        i = f;
    }
    return topo;
}

// ---- a árvore ----

static NoHuf *novo_no(unsigned char simbolo, long freq, int ordem, NoHuf *esq, NoHuf *dir) {
    NoHuf *no = malloc(sizeof *no);
    if (no == NULL) {
        fprintf(stderr, "huffman: sem memória\n");
        exit(1);
    }
    no->simbolo = simbolo;
    no->freq = freq;
    no->ordem = ordem;
    no->esq = esq;
    no->dir = dir;
    return no;
}

NoHuf *huf_constroi(const long freq[256]) {
    Heap h = {.n = 0};
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            poe(&h, novo_no((unsigned char)c, freq[c], c, NULL, NULL));
        }
    }
    if (h.n == 0) {
        return NULL;
    }
    int criados = 0;
    while (h.n > 1) {
        NoHuf *a = tira(&h);  // o menos frequente vira o filho 0
        NoHuf *b = tira(&h);  // o segundo vira o filho 1
        poe(&h, novo_no(0, a->freq + b->freq, 256 + criados++, a, b));
    }
    return tira(&h);
}

int huf_folha(const NoHuf *no) {
    return no->esq == NULL && no->dir == NULL;
}

// desce acumulando o caminho em buf; na folha, copia o caminho
static void preenche(const NoHuf *no, char buf[], int prof, char codigos[256][256]) {
    if (huf_folha(no)) {
        buf[prof] = '\0';
        strcpy(codigos[no->simbolo], buf);
        return;
    }
    buf[prof] = '0';
    preenche(no->esq, buf, prof + 1, codigos);
    buf[prof] = '1';
    preenche(no->dir, buf, prof + 1, codigos);
}

void huf_codigos(const NoHuf *raiz, char codigos[256][256]) {
    for (int c = 0; c < 256; c++) {
        codigos[c][0] = '\0';
    }
    if (raiz == NULL) {
        return;
    }
    if (huf_folha(raiz)) {              // um símbolo só: o código é "0"
        strcpy(codigos[raiz->simbolo], "0");
        return;
    }
    char buf[256];
    preenche(raiz, buf, 0, codigos);
}

void huf_libera(NoHuf *raiz) {
    if (raiz == NULL) {
        return;
    }
    huf_libera(raiz->esq);
    huf_libera(raiz->dir);
    free(raiz);
}
