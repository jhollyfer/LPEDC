// 0146 · Árvore B
// Exercício E871 · ★☆☆

#include <stdio.h>
#include "arvoreb.h"

int conta_chaves(const NoB *r) {
    int total = r->n;
    if (!r->folha) {
        for (int i = 0; i <= r->n; i++) { // n chaves, n + 1 filhos
            total += conta_chaves(r->filho[i]);
        }
    }
    return total;
}

int conta_nos(const NoB *r) {
    int total = 1;
    if (!r->folha) {
        for (int i = 0; i <= r->n; i++) {
            total += conta_nos(r->filho[i]);
        }
    }
    return total;
}

int main(void) {
    NoB *r = NULL;
    for (int c = 1; c <= 20; c++) {
        r = ab_insere(r, c);
    }
    ab_mostra(r);
    printf("chaves: %d | nós: %d | média: %.2f chaves por nó\n",
           conta_chaves(r), conta_nos(r), (double)conta_chaves(r) / conta_nos(r));
    r = ab_libera(r);
    return 0;
}
