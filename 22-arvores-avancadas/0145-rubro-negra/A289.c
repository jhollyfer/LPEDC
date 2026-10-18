// A289 · Mil chaves em ordem, mil ao contrário

#include <math.h>
#include <stdio.h>
#include "rubronegra.h"

void relata(const char *nome, const NoRN *r, int rot, int inv) {
    printf("%-12s altura %2d | altura preta %2d | rotações %4d | inversões %4d\n",
           nome, rn_altura(r), rn_altura_preta(r), rot, inv);
}

int main(void) {
    int n = 1000;
    NoRN *cresce = NULL;
    for (int i = 1; i <= n; i++) {
        cresce = rn_insere(cresce, i);
    }
    int rot1 = rn_rotacoes(), inv1 = rn_inversoes();
    relata("crescente:", cresce, rot1, inv1);

    NoRN *desce = NULL; // os contadores são acumulados: desconte os de antes
    for (int i = n; i >= 1; i--) {
        desce = rn_insere(desce, i);
    }
    relata("decrescente:", desce, rn_rotacoes() - rot1, rn_inversoes() - inv1);

    NoRN *mistura = NULL; // 1000 chaves embaralhadas: i * 7919 % 1000
    int rot2 = rn_rotacoes(), inv2 = rn_inversoes();
    for (int i = 0; i < n; i++) {
        mistura = rn_insere(mistura, i * 7919 % n);
    }
    relata("embaralhada:", mistura, rn_rotacoes() - rot2, rn_inversoes() - inv2);

    printf("Limite teórico: altura <= 2 log2(n + 1) = %.1f\n", 2 * log2(n + 1.0));
    printf("Busca 777 na crescente: %s\n", rn_busca(cresce, 777) ? "achou" : "não achou");

    cresce = rn_libera(cresce);
    desce = rn_libera(desce);
    mistura = rn_libera(mistura);
    return 0;
}
// Saída:
// crescente:   altura  9 | altura preta  9 | rotações  991 | inversões  985
// decrescente: altura 14 | altura preta  9 | rotações  985 | inversões  985
// embaralhada: altura 11 | altura preta  8 | rotações  546 | inversões  658
// Limite teórico: altura <= 2 log2(n + 1) = 19.9
// Busca 777 na crescente: achou
