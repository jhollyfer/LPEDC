// A164 · Nó-cabeça: a remoção sem caso especial

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Com um nó-cabeça (um nó "de mentira" no começo, cujo valor ninguém lê),
// todo nó de verdade tem um anterior. O primeiro não é mais especial.

static void cab_insere(No *cabeca, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;
    novo->prox = cabeca->prox; // entra logo depois da cabeça
    cabeca->prox = novo;
}

static int cab_remove(No *cabeca, int valor) {
    No *ant = cabeca;          // nunca é NULL
    No *p = cabeca->prox;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return 0;
    ant->prox = p->prox;       // um caso só: vale até para o primeiro
    free(p);
    return 1;
}

int main(void) {
    No cabeca = {0, NULL};     // a cabeça pode até morar na pilha
    cab_insere(&cabeca, 8);
    cab_insere(&cabeca, 42);
    cab_insere(&cabeca, 17);
    cab_insere(&cabeca, 31);
    lista_imprime(cabeca.prox); // a lista de verdade começa depois da cabeça

    cab_remove(&cabeca, 31);    // o primeiro: nenhum if especial
    cab_remove(&cabeca, 8);     // o último
    lista_imprime(cabeca.prox);

    lista_libera(cabeca.prox);  // a cabeça não veio do malloc: não leva free
    return 0;
}
// Saída:
// 31 -> 17 -> 42 -> 8 -> NULL
// 17 -> 42 -> NULL
