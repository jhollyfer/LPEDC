// 0106 · Encadeamento
// Exercício E631 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int chave;
    struct No *prox;
} No;

void insere(No *baldes[], int chave) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    novo->chave = chave;
    novo->prox = baldes[chave % M]; // entra no início da corrente
    baldes[chave % M] = novo;
}

void mostra(No *baldes[]) {
    int vazios = 0, maior = 0;
    for (int b = 0; b < M; b++) {
        int tam = 0;
        printf("[%d]", b);
        for (No *p = baldes[b]; p != NULL; p = p->prox) {
            printf(" %d", p->chave);
            tam++;
        }
        printf("\n");
        if (tam == 0) {
            vazios++;
        }
        if (tam > maior) {
            maior = tam;
        }
    }
    printf("vazios: %d, maior corrente: %d\n", vazios, maior);
}

void libera(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        No *p = baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        baldes[b] = NULL;
    }
}

int main(void) {
    No *baldes[M] = {NULL};
    int chaves[] = {12, 7, 20, 17, 3, 25};
    for (int i = 0; i < 6; i++) {
        insere(baldes, chaves[i]);
    }
    mostra(baldes);
    libera(baldes);
    return 0;
}
