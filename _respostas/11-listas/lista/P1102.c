// Lista · Módulo 11 · Listas
// Exercício P1102 · ★☆☆ · O itinerário do ônibus, parada por parada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void imprime(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

void libera(No *inicio) {
    while (inicio != NULL) {
        No *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

No *insere_fim(No *inicio, int valor, int *visitados) {
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
    (*visitados)++;
    while (p->prox != NULL) {
        p = p->prox;
        (*visitados)++;
    }
    p->prox = novo;
    return inicio;
}

int main(void) {
    int paradas[5] = {101, 205, 310, 412, 520};
    No *linha = NULL;
    int visitados = 0;
    for (int i = 0; i < 5; i++) {
        linha = insere_fim(linha, paradas[i], &visitados);
    }
    imprime(linha);
    printf("Nós visitados: %d\n", visitados);
    libera(linha);
    return 0;
}
