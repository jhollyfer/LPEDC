// 0111 · Encadeamento
// Exercício E663 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 4

typedef struct No {
    int pedido;
    struct No *prox;
} No;

bool insere(No *baldes[], int pedido) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->pedido = pedido;
    novo->prox = baldes[pedido % M];
    baldes[pedido % M] = novo;
    return true;
}

bool remove_pedido(No *baldes[], int pedido) {
    No **elo = &baldes[pedido % M]; // aponta para o ponteiro que leva ao nó
    while (*elo != NULL) {
        if ((*elo)->pedido == pedido) {
            No *sai = *elo;
            *elo = sai->prox; // o anterior (ou a cabeça) pula o nó
            free(sai);
            return true;
        }
        elo = &(*elo)->prox;
    }
    return false;
}

void mostra(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        printf("[%d]", b);
        for (No *p = baldes[b]; p != NULL; p = p->prox) {
            printf(" %d", p->pedido);
        }
        printf("\n");
    }
}

void libera(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        while (baldes[b] != NULL) {
            No *prox = baldes[b]->prox;
            free(baldes[b]);
            baldes[b] = prox;
        }
    }
}

int main(void) {
    No *baldes[M] = {NULL};
    int pedidos[] = {101, 205, 309, 120, 222, 315};
    for (int i = 0; i < 6; i++) {
        insere(baldes, pedidos[i]);
    }
    mostra(baldes);

    int retirados[] = {205, 309, 999};
    for (int i = 0; i < 3; i++) {
        if (remove_pedido(baldes, retirados[i])) {
            printf("pedido %d retirado\n", retirados[i]);
        } else {
            printf("pedido %d não existe\n", retirados[i]);
        }
    }
    mostra(baldes);
    libera(baldes);
    return 0;
}
