// 0144 · Árvores gerais
// Exercício E863 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "arvgen.h"

bool remove_filho(NoG *pai, const char *nome) {
    NoG *ant = NULL;
    NoG *p = pai->filho;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->irmao;
    }
    if (p == NULL) {
        return false; // não é filho direto de pai
    }
    if (ant == NULL) { // primeiro solta p da fila de irmãos...
        pai->filho = p->irmao; // era o primeiro filho
    } else {
        ant->irmao = p->irmao; // pula o removido
    }
    ag_libera(p); // ...depois libera: p->irmao já foi lido
    return true;
}

int main(void) {
    NoG *cardapio = ag_cria("cardapio", 0);
    NoG *lanches = ag_adiciona(cardapio, "lanches", 0);
    ag_adiciona(lanches, "xburguer", 22);
    ag_adiciona(lanches, "xsalada", 20);
    ag_adiciona(lanches, "misto", 12);
    NoG *bebidas = ag_adiciona(cardapio, "bebidas", 0);
    ag_adiciona(bebidas, "suco", 9);
    ag_adiciona(bebidas, "cafe", 5);
    NoG *sobremesas = ag_adiciona(cardapio, "sobremesas", 0);
    ag_adiciona(sobremesas, "pudim", 8);

    ag_mostra(cardapio);
    printf("Tirou bebidas: %s\n", remove_filho(cardapio, "bebidas") ? "sim" : "não");
    printf("Tirou misto: %s\n", remove_filho(cardapio, "misto") ? "sim"
                                    : "não (não é filho direto do cardapio)");
    printf("Tirou misto de lanches: %s\n", remove_filho(lanches, "misto") ? "sim" : "não");
    ag_mostra(cardapio);

    ag_libera(cardapio);
    return 0;
}
