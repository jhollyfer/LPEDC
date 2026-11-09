// 0174 · Lista com sentinela
// Exercício E1044 · ★★★

#include <stdio.h>
#include "sentinela.h"

void inverte(ListaS *L) {
    NoS *x = &L->nil;
    do {
        NoS *t = x->prox; // troca ant com prox
        x->prox = x->ant;
        x->ant = t;
        x = x->ant;       // o antigo prox
    } while (x != &L->nil);
}

int main(void) {
    ListaS *L = sent_cria();
    ListaS *vazia = sent_cria();
    if (L == NULL || vazia == NULL) {
        return 1;
    }
    for (int p = 10; p <= 40; p += 10) {
        sent_insere_fim(L, p);
    }
    printf("ida:   ");
    sent_mostra(L);
    inverte(L);
    printf("volta: ");
    sent_mostra(L);
    printf("volta ao contrário: ");
    sent_mostra_inverso(L);
    inverte(vazia);
    printf("vazia invertida: ");
    sent_mostra(vazia);
    sent_libera(L);
    sent_libera(vazia);
    return 0;
}
