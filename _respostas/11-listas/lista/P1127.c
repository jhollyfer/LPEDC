// Lista · Módulo 11 · Listas
// Exercício P1127 · ★★★ · Dividir a ciranda em duas rodas

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *insere_fim(No *ultimo, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    if (ultimo == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    return novo;
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

void divide(No *ultimo, No **ultimo1, No **ultimo2) {
    *ultimo1 = *ultimo2 = NULL;
    if (ultimo == NULL) {
        return;
    }
    No *primeiro = ultimo->prox;
    if (primeiro == ultimo) { // um nó só
        *ultimo1 = ultimo;
        return;
    }
    No *lento = primeiro, *rapido = primeiro;
    while (rapido->prox != primeiro && rapido->prox->prox != primeiro) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    if (rapido->prox->prox == primeiro) { // n par
        rapido = rapido->prox;
    }
    rapido->prox = lento->prox; // fecha a metade 2
    lento->prox = primeiro;     // fecha a metade 1
    *ultimo1 = lento;
    *ultimo2 = rapido;
}

void mostra(const char *rotulo, const No *ultimo) {
    printf("%s:", rotulo);
    const No *p = ultimo->prox;
    do {
        printf(" %d", p->valor);
        p = p->prox;
    } while (p != ultimo->prox);
}

void testa(int n) {
    No *roda = NULL;
    for (int v = 1; v <= n; v++) {
        roda = insere_fim(roda, v);
    }
    char rotulo[20];
    snprintf(rotulo, sizeof rotulo, "roda de %d", n);
    mostra(rotulo, roda);
    printf("\n");

    No *u1, *u2;
    divide(roda, &u1, &u2);
    mostra("  metade 1", u1);
    printf(" (o %d aponta para o %d)\n", u1->valor, u1->prox->valor);
    if (u2 != NULL) {
        mostra("  metade 2", u2);
        printf(" (o %d aponta para o %d)\n", u2->valor, u2->prox->valor);
    }
    libera(u1);
    libera(u2);
}

int main(void) {
    testa(7);
    testa(6);
    return 0;
}
