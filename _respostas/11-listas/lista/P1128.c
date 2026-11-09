// Lista · Módulo 11 · Listas
// Exercício P1128 · ★★★ · A esteira do sushi em ordem de preço

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int preco;
    struct no *prox;
} No;

No *insere_ordenado(No *ultimo, int preco) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->preco = preco;
    if (ultimo == NULL) {
        novo->prox = novo;
        return novo;
    }
    if (preco >= ultimo->preco) { // mais caro de todos: vira o último
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
        return novo;
    }
    No *p = ultimo;
    while (p->prox->preco <= preco) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return ultimo;
}

void mostra(const No *ultimo) {
    const No *p = ultimo->prox;
    do {
        printf(p == ultimo->prox ? "%d" : " %d", p->preco);
        p = p->prox;
    } while (p != ultimo->prox);
    printf(" | último: %d\n", ultimo->preco);
}

void libera(No *ultimo) {
    if (ultimo == NULL) {
        return;
    }
    No *p = ultimo->prox;
    ultimo->prox = NULL;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {
    int pratos[7] = {30, 10, 50, 20, 40, 60, 5};
    No *esteira = NULL;
    for (int i = 0; i < 7; i++) {
        esteira = insere_ordenado(esteira, pratos[i]);
        mostra(esteira);
    }
    libera(esteira);
    return 0;
}
