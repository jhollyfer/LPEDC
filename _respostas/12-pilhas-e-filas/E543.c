// 0091 · Fila encadeada
// Exercício E543 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[30];
    struct cliente *prox;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
} FilaPadaria;

bool entra(FilaPadaria *f, const char *nome) {
    Cliente *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo; // fila vazia: é o primeiro também
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

bool sai(FilaPadaria *f, char *destino) {
    if (f->inicio == NULL) {
        return false;
    }
    Cliente *velho = f->inicio;
    strcpy(destino, velho->nome);
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // saiu o último
    }
    free(velho);
    return true;
}

int main(void) {
    FilaPadaria f = {NULL, NULL};
    char nome[30];

    entra(&f, "Ana");
    entra(&f, "Bruno");
    entra(&f, "Carla");
    if (sai(&f, nome)) {
        printf("Atendendo %s\n", nome);
    }
    entra(&f, "Davi");
    while (sai(&f, nome)) {
        printf("Atendendo %s\n", nome);
    }
    printf("Fila vazia\n");
    return 0;
}
