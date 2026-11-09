// Lista · Módulo 15 · Tabelas hash
// Exercício P1516 · ★★☆ · Cancelando matrículas na tabela encadeada

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int matricula;
    struct No *prox;
} No;

void insere(No *t[], int k) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->matricula = k;
    novo->prox = t[k % M];
    t[k % M] = novo;
}

// devolve 1 se removeu; o ponteiro para ponteiro trata o início da corrente
int remove_chave(No *t[], int k) {
    No **p = &t[k % M];
    while (*p != NULL && (*p)->matricula != k) {
        p = &(*p)->prox;
    }
    if (*p == NULL) {
        return 0;
    }
    No *sai = *p;
    *p = sai->prox;
    free(sai);
    return 1;
}

void mostra(No *t[]) {
    for (int b = 0; b < M; b++) {
        printf("  %d:", b);
        for (No *p = t[b]; p != NULL; p = p->prox) {
            printf(" %d", p->matricula);
        }
        printf("\n");
    }
}

int main(void) {
    No *t[M] = {NULL};
    int entram[] = {101, 206, 311, 416, 122, 227, 133};
    for (int i = 0; i < 7; i++) {
        insere(t, entram[i]);
    }
    printf("início:\n");
    mostra(t);

    int saem[] = {311, 416, 101, 999};
    for (int i = 0; i < 4; i++) {
        printf("remove %d: %s\n", saem[i], remove_chave(t, saem[i]) ? "ok" : "não existe");
    }
    printf("fim:\n");
    mostra(t);

    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            remove_chave(t, t[b]->matricula);
        }
    }
    return 0;
}
