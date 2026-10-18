// 0146 · Árvore B
// Exercício E873 · ★★☆

#include <stdio.h>
#include "arvoreb.h"

// soma, em *chaves e *nos, as chaves e os nós da subárvore
void mede(const NoB *r, int *chaves, int *nos) {
    *chaves += r->n;
    (*nos)++;
    if (!r->folha) {
        for (int i = 0; i <= r->n; i++) {
            mede(r->filho[i], chaves, nos);
        }
    }
}

void relata(const char *nome, const NoB *r) {
    int chaves = 0, nos = 0;
    mede(r, &chaves, &nos);
    printf("%-12s nós %3d | altura %d | ocupação %.1f%%\n", nome, nos, ab_altura(r),
           100.0 * chaves / (nos * AB_MAX));
}

int main(void) {
    int n = 200;
    NoB *crescente = NULL, *embaralhada = NULL;
    for (int i = 1; i <= n; i++) {
        crescente = ab_insere(crescente, i);
    }
    for (int i = 0; i < n; i++) {
        embaralhada = ab_insere(embaralhada, i * 37 % n + 1); // 1 a 200, misturados
    }
    relata("crescente:", crescente);
    relata("embaralhada:", embaralhada);
    crescente = ab_libera(crescente);
    embaralhada = ab_libera(embaralhada);
    return 0;
}
