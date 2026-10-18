// A162 · Inserir no fim com um ponteiro para o último

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// põe "valor" depois do último nó; *inicio e *fim mudam quando precisa
static void insere_no_fim(No **inicio, No **fim, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;
    novo->prox = NULL;     // ele vai ser o último
    if (*inicio == NULL) { // lista vazia: é o primeiro e o último
        *inicio = novo;
    } else {
        (*fim)->prox = novo; // o antigo último aponta para ele
    }
    *fim = novo;
}

int main(void) {
    No *inicio = NULL;
    No *fim = NULL;

    insere_no_fim(&inicio, &fim, 20);
    insere_no_fim(&inicio, &fim, 45);
    insere_no_fim(&inicio, &fim, 10);
    insere_no_fim(&inicio, &fim, 80);

    lista_imprime(inicio); // agora na ordem de chegada
    printf("primeiro: %d, último: %d\n", inicio->valor, fim->valor);

    lista_libera(inicio);
    return 0;
}
// Saída:
// 20 -> 45 -> 10 -> 80 -> NULL
// primeiro: 20, último: 80
