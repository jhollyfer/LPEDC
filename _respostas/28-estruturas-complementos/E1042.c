// 0174 · Lista com sentinela
// Exercício E1042 · ★★☆

#include <stdio.h>
#include "sentinela.h"

int remove_todas(ListaS *L, int codigo) {
    int removidos = 0;
    NoS *x = L->nil.prox;
    while (x != &L->nil) {
        NoS *seguinte = x->prox; // lido antes de liberar x
        if (x->chave == codigo) {
            sent_remove(L, x);
            removidos++;
        }
        x = seguinte;
    }
    return removidos;
}

int main(void) {
    ListaS *L = sent_cria();
    if (L == NULL) {
        return 1;
    }
    int codigos[] = {7, 3, 3, 9, 3, 5, 3};
    for (int i = 0; i < 7; i++) {
        sent_insere_fim(L, codigos[i]);
    }
    printf("Antes: ");
    sent_mostra(L);
    int r = remove_todas(L, 3);
    printf("Removidos %d do código 3: ", r);
    sent_mostra(L);
    r = remove_todas(L, 8);
    printf("Removidos %d do código 8: ", r);
    sent_mostra(L);
    sent_libera(L);
    return 0;
}
