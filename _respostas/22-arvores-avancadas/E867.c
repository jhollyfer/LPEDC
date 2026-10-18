// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E867 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

NoRN *no(int chave, bool vermelho, NoRN *esq, NoRN *dir) {
    NoRN *n = malloc(sizeof(NoRN));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->vermelho = vermelho;
    n->esq = esq;
    n->dir = dir;
    return n;
}

int confere(const NoRN *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->dir != NULL && r->dir->vermelho) {
        return -1;
    }
    if (r->vermelho && r->esq != NULL && r->esq->vermelho) {
        return -2;
    }
    int e = confere(r->esq);
    if (e < 0) {
        return e;
    }
    int d = confere(r->dir);
    if (d < 0) {
        return d;
    }
    if (e != d) {
        return -3;
    }
    return e + (r->vermelho ? 0 : 1);
}

void relata(const char *nome, const NoRN *r) {
    int c = confere(r);
    if (c >= 0) {
        printf("%s: ok, altura preta %d\n", nome, c);
    } else {
        printf("%s: quebra a regra %d\n", nome, -c);
    }
}

int main(void) {
    NoRN *tad = NULL;
    for (int c = 1; c <= 20; c++) {
        tad = rn_insere(tad, c);
    }
    // A: 20 com 10 (preto) à esquerda e 30 (VERMELHO) à direita
    NoRN *a = no(20, false, no(10, false, NULL, NULL), no(30, true, NULL, NULL));
    // B: 30 com 20 vermelho à esquerda, e 10 vermelho embaixo do 20
    NoRN *b = no(30, false, no(20, true, no(10, true, NULL, NULL), NULL),
                 no(40, false, NULL, NULL));
    // C: tudo preto, mas o 10 tem um filho (5) e o 30 não tem nenhum
    NoRN *c = no(20, false, no(10, false, no(5, false, NULL, NULL), NULL),
                 no(30, false, NULL, NULL));

    relata("TAD (1 a 20)", tad);
    relata("Árvore A", a);
    relata("Árvore B", b);
    relata("Árvore C", c);

    tad = rn_libera(tad);
    a = rn_libera(a);
    b = rn_libera(b);
    c = rn_libera(c);
    return 0;
}
