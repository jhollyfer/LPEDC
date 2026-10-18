// 0106 · Encadeamento
// Exercício E631 · ★☆☆
//
// Resposta:
// [0] 25 20
// [1]
// [2] 17 7 12
// [3] 3
// [4]
// Cada número novo entra no início da corrente, por isso o último inserido
// aparece primeiro. O balde 2 tem 3 nós; os baldes 1 e 4 ficaram vazios.

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int chave;
    struct No *prox;
} No;

int main(void) {
    No *baldes[M] = {NULL};
    int chaves[] = {12, 7, 20, 17, 3, 25};

    for (int i = 0; i < 6; i++) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            return 1;
        }
        int b = chaves[i] % M;
        novo->chave = chaves[i];
        novo->prox = baldes[b];
        baldes[b] = novo;
    }
    for (int b = 0; b < M; b++) {
        printf("[%d]", b);
        No *p = baldes[b];
        while (p != NULL) {
            printf(" %d", p->chave);
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        printf("\n");
    }
    return 0;
}
