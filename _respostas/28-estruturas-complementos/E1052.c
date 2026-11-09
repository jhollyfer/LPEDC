// 0176 · AVL: remoção
// Exercício E1052 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
#include "avlrem.h"

// confere a ordem (lim_inf < chave < lim_sup), o campo altura e o fator.
// Devolve quantos nós passaram; -1 se algum falhou.
int confere(const NoA *r, long lim_inf, long lim_sup) {
    if (r == NULL) {
        return 0;
    }
    int e = confere(r->esq, lim_inf, r->chave);
    int d = confere(r->dir, r->chave, lim_sup);
    if (e < 0 || d < 0 || r->chave <= lim_inf || r->chave >= lim_sup) {
        return -1;
    }
    int he = avr_altura(r->esq), hd = avr_altura(r->dir);
    bool altura_ok = r->altura == 1 + (he > hd ? he : hd);
    bool fator_ok = he - hd >= -1 && he - hd <= 1;
    if (!altura_ok || !fator_ok) {
        return -1;
    }
    return 1 + e + d;
}

int main(void) {
    NoA *raiz = NULL;
    for (int k = 1; k <= 100; k++) {
        raiz = avr_insere(raiz, k);
    }
    for (int k = 3; k <= 100; k += 3) {
        raiz = avr_remove(raiz, k);
    }
    int nos = confere(raiz, -1, 1000);
    if (nos < 0) {
        printf("AVL quebrada\n");
    } else {
        printf("AVL ok: %d nós, altura %d, %d rotações no total\n", nos, avr_altura(raiz), avr_rotacoes());
    }
    raiz = avr_libera(raiz);
    return 0;
}
