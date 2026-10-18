// 0091 · Fila encadeada
// Exercício E546 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox; // no último, aponta de volta para o primeiro
} No;

bool circ_insere(No **ultimo, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->valor = valor;
    if (*ultimo == NULL) {
        novo->prox = novo; // um nó só: aponta para ele mesmo
    } else {
        novo->prox = (*ultimo)->prox; // o novo aponta para o primeiro
        (*ultimo)->prox = novo;       // o antigo último aponta para o novo
    }
    *ultimo = novo;
    return true;
}

bool circ_retira(No **ultimo, int *valor) {
    if (*ultimo == NULL) {
        return false;
    }
    No *primeiro = (*ultimo)->prox;
    *valor = primeiro->valor;
    if (primeiro == *ultimo) {
        *ultimo = NULL; // era o único
    } else {
        (*ultimo)->prox = primeiro->prox;
    }
    free(primeiro);
    return true;
}

int main(void) {
    No *ultimo = NULL;
    int p;

    circ_insere(&ultimo, 501);
    circ_insere(&ultimo, 502);
    circ_insere(&ultimo, 503);
    if (circ_retira(&ultimo, &p)) {
        printf("Preparando: %d\n", p);
    }
    circ_insere(&ultimo, 504);

    printf("Depois:");
    while (circ_retira(&ultimo, &p)) {
        printf(" %d", p);
    }
    printf("\n");
    return 0;
}
