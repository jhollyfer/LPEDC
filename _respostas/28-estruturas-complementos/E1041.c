// 0174 · Lista com sentinela
// Exercício E1041 · ★★☆

#include <stdio.h>
#include "sentinela.h"

NoS *insere_ordenado(ListaS *L, int h) {
    NoS *p = L->nil.prox;
    while (p != &L->nil && p->chave < h) {
        p = p->prox;
    }
    return sent_insere_apos(L, p->ant, h); // entra antes de p
}

int main(void) {
    ListaS *agenda = sent_cria();
    if (agenda == NULL) {
        return 1;
    }
    int horarios[] = {1400, 900, 1630, 800, 1100};
    for (int i = 0; i < 5; i++) {
        insere_ordenado(agenda, horarios[i]);
        sent_mostra(agenda);
    }
    sent_libera(agenda);
    return 0;
}
