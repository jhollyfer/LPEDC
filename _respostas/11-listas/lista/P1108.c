// Lista · Módulo 11 · Listas
// Exercício P1108 · ★☆☆ · As senhas da farmácia e a memória

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *insere_fim(No *inicio, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (inicio == NULL) {
        return novo;
    }
    No *p = inicio;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return inicio;
}

void imprime(const No *inicio) {
    printf("Senhas: ");
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

// tira a primeira senha e devolve o novo início
No *chama(No *inicio) {
    if (inicio == NULL) {
        return NULL;
    }
    printf("Chamou %d\n", inicio->valor);
    No *resto = inicio->prox;
    free(inicio); // o nó chamado sai da memória também
    return resto;
}

void libera(No *inicio) {
    No *p = inicio;
    while (p != NULL) {
        No *seguinte = p->prox; // guarda ANTES do free
        free(p);
        p = seguinte;
    }
}

int main(void) {
    No *painel = NULL;
    for (int s = 41; s <= 44; s++) {
        painel = insere_fim(painel, s);
    }
    imprime(painel);
    painel = chama(painel);
    painel = chama(painel);
    imprime(painel);
    libera(painel);
    return 0;
}
