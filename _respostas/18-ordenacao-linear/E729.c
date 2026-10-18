// 0122 · Bucket sort
// Exercício E729 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB 26 // um balde por letra inicial

typedef struct No {
    const char *nome;
    struct No *prox;
} No;

No *insere_ordenado(No *lista, const char *nome) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->nome = nome;
    if (lista == NULL || strcmp(nome, lista->nome) < 0) {
        novo->prox = lista;
        return novo;
    }
    No *p = lista;
    while (p->prox != NULL && strcmp(p->prox->nome, nome) <= 0) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

int main(void) {
    const char *contatos[] = {"Marcos", "Ana", "Bruno", "Mariana", "Carla", "Alberto",
                              "Beatriz", "Marta", "Caio", "Amanda", "Mauro"};
    int n = 11;
    No *baldes[NB] = {NULL};

    for (int i = 0; i < n; i++) {
        int b = contatos[i][0] - 'A';
        baldes[b] = insere_ordenado(baldes[b], contatos[i]);
    }
    int k = 0;
    for (int b = 0; b < NB; b++) {
        if (baldes[b] == NULL) {
            continue;
        }
        printf("%c:", 'A' + b);
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            printf(" %s", p->nome);
            contatos[k++] = p->nome;
            baldes[b] = p->prox;
            free(p);
        }
        printf("\n");
    }
    printf("agenda:");
    for (int i = 0; i < n; i++) {
        printf(" %s", contatos[i]);
    }
    printf("\n");
    return 0;
}
