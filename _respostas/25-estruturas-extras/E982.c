// 0164 · Listas autoajustáveis
// Exercício E982 · ★★☆

#include <stdio.h>
#include <string.h>
#include "autolista.h"

void liga(AutoLista *l, const char *nome) {
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return; // não está na agenda
    }
    if (ant != NULL) { // se já é o primeiro, não há o que mover
        ant->prox = p->prox;
        p->prox = l->inicio;
        l->inicio = p;
    }
}

int main(void) {
    const char *contatos[] = {"Ana", "Bia", "Caio", "Duda"};
    const char *chamadas[] = {"Bia", "Bia", "Duda", "Ana", "Ana"};
    AutoLista *agenda = al_cria();
    for (int i = 0; i < 4; i++) {
        al_insere_fim(agenda, contatos[i]);
    }

    for (int i = 0; i < 5; i++) {
        liga(agenda, chamadas[i]);
        printf("%s: ", chamadas[i]);
        al_mostra(agenda);
        printf("\n");
    }

    al_libera(agenda);
    return 0;
}
