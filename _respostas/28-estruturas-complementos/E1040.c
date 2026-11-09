// 0174 · Lista com sentinela
// Exercício E1040 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
#include "sentinela.h"

int main(void) {
    ListaS *fila = sent_cria();
    if (fila == NULL) {
        return 1;
    }
    for (int s = 1; s <= 5; s++) {
        sent_insere_fim(fila, s);
    }
    bool frente = true;
    while (fila->n > 0) {
        NoS *x = frente ? fila->nil.prox : fila->nil.ant;
        int senha = x->chave; // guarda antes de liberar
        sent_remove(fila, x);
        printf("chama %d: ", senha);
        sent_mostra(fila);
        frente = !frente;
    }
    sent_libera(fila);
    return 0;
}
