// A352 · Fator 0 no filho: o caso que só a remoção tem

#include <stdio.h>
#include "0176-avlrem.h"

NoA *monta(const int *v, int n) {
    NoA *r = NULL;
    for (int i = 0; i < n; i++) {
        r = avr_insere(r, v[i]);
    }
    return r;
}

void relata(const char *nome, NoA *r, int sai) {
    printf("%s\n  antes:  pré", nome);
    avr_pre_ordem(r);
    printf(" | altura %d | fator do filho esquerdo %d\n", avr_altura(r), avr_fator(r->esq));
    r = avr_remove(r, sai);
    printf("  tira %d: pré", sai);
    avr_pre_ordem(r);
    printf(" | altura %d\n", avr_altura(r));
    avr_libera(r);
}

int main(void) {
    int a[] = {20, 10, 30, 5, 15}; // o 10 tem os dois filhos: fator 0
    int b[] = {20, 10, 30, 5};     // o 10 só tem o 5: fator 1
    relata("Filho com fator 0:", monta(a, 5), 30);
    relata("Filho com fator 1:", monta(b, 4), 30);
    return 0;
}
// Saída:
// Filho com fator 0:
//   antes:  pré 20 10 5 15 30 | altura 2 | fator do filho esquerdo 0
//   tira 30: pré 10 5 20 15 | altura 2
// Filho com fator 1:
//   antes:  pré 20 10 5 30 | altura 2 | fator do filho esquerdo 1
//   tira 30: pré 10 5 20 | altura 1
