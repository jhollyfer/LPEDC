// 0164 · Listas autoajustáveis
// Exercício E981 · ★★☆

#include <stdio.h>
#include <string.h>
#include "autolista.h"

bool busca_sobe2(AutoLista *l, const char *nome, int *custo) {
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    int i = 0;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
        i++;
    }
    *custo = p == NULL ? i : i + 1;
    if (p == NULL) {
        return false;
    }
    if (i == 0) {
        return true; // já é o primeiro
    }
    ant->prox = p->prox; // tira p do lugar
    int destino = i >= 2 ? i - 2 : 0;
    NoAuto **q = &l->inicio;
    for (int k = 0; k < destino; k++) {
        q = &(*q)->prox;
    }
    p->prox = *q; // pendura p na posição destino
    *q = p;
    return true;
}

int main(void) {
    const char *contatos[] = {"Ana", "Bia", "Caio", "Duda", "Edu"};
    const char *chamadas[] = {"Edu", "Edu", "Duda", "Edu", "Duda"};
    AutoLista *agenda = al_cria();
    for (int i = 0; i < 5; i++) {
        al_insere_fim(agenda, contatos[i]);
    }

    int total = 0;
    for (int i = 0; i < 5; i++) {
        int custo;
        busca_sobe2(agenda, chamadas[i], &custo);
        total += custo;
        printf("%-4s custo %d -> ", chamadas[i], custo);
        al_mostra(agenda);
        printf("\n");
    }
    printf("Total: %d\n", total);

    al_libera(agenda);
    return 0;
}
