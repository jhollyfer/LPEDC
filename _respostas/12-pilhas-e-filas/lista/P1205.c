// Lista · Módulo 12 · Pilhas e filas
// Exercício P1205 · ★☆☆ · A fila do forno da pizzaria

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido {
    char cliente[16];
    char sabor[16];
    struct pedido *prox;
} Pedido;

typedef struct {
    Pedido *inicio, *fim;
    int n;
} Fila;

void entra(Fila *f, const char *cliente, const char *sabor) {
    Pedido *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->cliente, cliente);
    strcpy(novo->sabor, sabor);
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->n++;
}

bool sai(Fila *f, char *cliente, char *sabor) {
    if (f->inicio == NULL) {
        return false;
    }
    Pedido *velho = f->inicio;
    strcpy(cliente, velho->cliente);
    strcpy(sabor, velho->sabor);
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(velho);
    f->n--;
    return true;
}

int tamanho(const Fila *f) {
    return f->n;
}

int main(void) {
    Fila forno = {NULL, NULL, 0};
    char cliente[16], sabor[16];
    entra(&forno, "Ana", "calabresa");
    entra(&forno, "Beto", "marguerita");
    entra(&forno, "Caio", "portuguesa");
    if (sai(&forno, cliente, sabor)) {
        printf("Saiu: %s (%s)\n", cliente, sabor);
    }
    entra(&forno, "Duda", "frango");
    printf("Na fila: %d pedidos\n", tamanho(&forno));
    while (sai(&forno, cliente, sabor)) {
        printf("Saiu: %s (%s)\n", cliente, sabor);
    }
    printf("Na fila: %d pedidos\n", tamanho(&forno));
    return 0;
}
