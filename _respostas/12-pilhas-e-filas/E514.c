// 0086 · Fila encadeada
// Exercício E514 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int numero;
    struct pedido *prox;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Cozinha;

bool cozinha_entra(Cozinha *f, int numero) {
    Pedido *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->numero = numero;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

bool cozinha_sai(Cozinha *f, int *numero) {
    if (f->inicio == NULL) {
        return false;
    }
    Pedido *velho = f->inicio;
    *numero = velho->numero;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // a fila esvaziou
    }
    free(velho);
    return true;
}

int main(void) {
    Cozinha f = {NULL, NULL};
    int n;

    cozinha_entra(&f, 11);
    cozinha_entra(&f, 12);
    while (cozinha_sai(&f, &n)) {
        printf("Pronto: %d\n", n);
    }

    cozinha_entra(&f, 13); // a fila tinha esvaziado
    cozinha_entra(&f, 14);
    while (cozinha_sai(&f, &n)) {
        printf("Pronto: %d\n", n);
    }
    return 0;
}
