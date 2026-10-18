// 0146 · Árvore B
// Exercício E872 · ★☆☆

#include <stdio.h>
#include "arvoreb.h"

// a menor chave: desce sempre pelo primeiro filho até a folha
int minimo(const NoB *r, int *lidos) {
    *lidos = 1;
    while (!r->folha) {
        r = r->filho[0];
        (*lidos)++;
    }
    return r->chave[0];
}

// a maior: desce sempre pelo último filho
int maximo(const NoB *r, int *lidos) {
    *lidos = 1;
    while (!r->folha) {
        r = r->filho[r->n];
        (*lidos)++;
    }
    return r->chave[r->n - 1];
}

int main(void) {
    int temperaturas[] = {27, 31, 19, 24, 35, 22, 18, 29, 33, 21, 26, 30, 17, 36, 25};
    NoB *r = NULL;
    for (int i = 0; i < 15; i++) {
        r = ab_insere(r, temperaturas[i]);
    }
    ab_mostra(r);
    int l1, l2;
    int mi = minimo(r, &l1), ma = maximo(r, &l2);
    printf("mínima: %d graus (%d nós lidos)\n", mi, l1);
    printf("máxima: %d graus (%d nós lidos)\n", ma, l2);
    r = ab_libera(r);
    return 0;
}
