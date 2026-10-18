// 0122 · Bucket sort
// Exercício E728 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

#define NB 6 // tempos de 0 a 599 segundos: um balde para cada 100 s

typedef struct No {
    int valor;
    struct No *prox;
} No;

// insere x na lista, mantendo a ordem crescente
No *insere_ordenado(No *lista, int x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    if (lista == NULL || x < lista->valor) {
        novo->prox = lista;
        return novo;
    }
    No *p = lista;
    while (p->prox != NULL && p->prox->valor <= x) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

int main(void) {
    // tempos da prova de 1 km da natação, em segundos
    int tempos[] = {512, 287, 433, 298, 365, 201, 470, 255, 318, 409, 295};
    int n = 11;
    No *baldes[NB] = {NULL};

    for (int i = 0; i < n; i++) {
        int b = tempos[i] / 100;
        baldes[b] = insere_ordenado(baldes[b], tempos[i]);
    }
    int k = 0;
    for (int b = 0; b < NB; b++) {
        printf("balde %d:", b);
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            printf(" %d", p->valor);
            tempos[k++] = p->valor;
            baldes[b] = p->prox;
            free(p);
        }
        printf("\n");
    }
    printf("ordenados:");
    for (int i = 0; i < n; i++) {
        printf(" %d", tempos[i]);
    }
    printf("\n");
    return 0;
}
