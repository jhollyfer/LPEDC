// 0177 · Rubro-negra clássica
// Exercício E1062 · ★★★

#include <stdio.h>
#include "vermelhopreto.h"

NoVP *sucessor(ArvVP *T, NoVP *x) {
    if (x->dir != &T->nil) {
        x = x->dir;
        while (x->esq != &T->nil) {
            x = x->esq;
        }
        return x;
    }
    NoVP *y = x->pai;
    while (y != &T->nil && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

// o primeiro nó com chave >= a: desce guardando o último em que virou à esquerda
NoVP *teto(ArvVP *T, int a) {
    NoVP *candidato = &T->nil;
    NoVP *x = T->raiz;
    while (x != &T->nil) {
        if (x->chave >= a) {
            candidato = x;
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    return candidato;
}

int relatorio(ArvVP *T, int a, int b) {
    int conta = 0;
    printf("[%d, %d]:", a, b);
    for (NoVP *x = teto(T, a); x != &T->nil && x->chave <= b; x = sucessor(T, x)) {
        printf(" %d", x->chave);
        conta++;
    }
    printf(" (%d pacotes)\n", conta);
    return conta;
}

int main(void) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    for (int i = 0; i < 20; i++) {
        vp_insere(T, 1000 + i * 37 % 100);
    }
    relatorio(T, 1020, 1050);
    relatorio(T, 1000, 1010);
    relatorio(T, 1093, 1200);
    relatorio(T, 1500, 1600);
    vp_libera(T);
    return 0;
}
