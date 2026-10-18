// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E442 · ★★☆
//
// Resposta: o Pix de R$ 100,00 é negado; o de R$ 35,50 passa.
// Bia: R$ 44,50 | Caio: R$ 45,50.

#include <stdbool.h>
#include <stdio.h>

#include "conta.h"

// Move "centavos" de "de" para "para". Devolve false, sem mexer em nada, se
// o saque na origem não der certo.
bool transfere(Conta *de, Conta *para, int centavos) {
    if (!conta_saca(de, centavos)) {
        return false;
    }
    return conta_deposita(para, centavos); // centavos > 0, já que o saque passou
}

void mostra_pix(int centavos, bool ok) {
    printf("Pix de R$ %d,%02d: %s\n", centavos / 100, centavos % 100, ok ? "ok" : "negado");
}

int main(void) {
    Conta *bia = conta_cria("Bia");
    Conta *caio = conta_cria("Caio");
    if (bia == NULL || caio == NULL) {
        conta_libera(bia);
        conta_libera(caio);
        return 1;
    }
    conta_deposita(bia, 8000);
    conta_deposita(caio, 1000);

    mostra_pix(10000, transfere(bia, caio, 10000));
    mostra_pix(3550, transfere(bia, caio, 3550));

    int sb = conta_saldo(bia), sc = conta_saldo(caio);
    printf("%s: R$ %d,%02d | %s: R$ %d,%02d\n", conta_titular(bia), sb / 100, sb % 100,
           conta_titular(caio), sc / 100, sc % 100);

    conta_libera(bia);
    conta_libera(caio);
    return 0;
}
