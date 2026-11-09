// Lista · Módulo 25 · Estruturas especiais
// Exercício P2514 · ★★☆ · Skip list contra lista simples

#include <stdio.h>
#include <stdlib.h>

#define MAX 16
#define N 2000

typedef struct No {
    int chave;
    struct No *prox[MAX];
} No;

No cabeca;
unsigned semente = 7;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

void insere(int chave) {
    int andares = 1;
    while (andares < MAX && moeda() == 1) andares++;
    No *antes[MAX], *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) x = x->prox[k];
        antes[k] = x;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->chave = chave;
    for (int k = 0; k < MAX; k++) {
        novo->prox[k] = NULL;
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        }
    }
}

// devolve quantas chaves foram comparadas (cada olhada em x->prox[k])
int busca(int chave) {
    int passos = 0;
    No *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL) {
            passos++;
            if (x->prox[k]->chave >= chave) break;
            x = x->prox[k];
        }
    }
    return passos;
}

int main(void) {
    for (int c = 1; c <= N; c++) insere(3 * c); // códigos 3, 6, ..., 6000
    long total = 0;
    int pior = 0;
    for (int c = 1; c <= N; c++) {
        int p = busca(3 * c);
        total += p;
        if (p > pior) pior = p;
    }
    long lista = (long)N * (N + 1) / 2; // a chave c está na posição c da lista simples
    printf("Skip list: %ld comparações, média %.1f, pior %d\n", total, total / (double)N, pior);
    printf("Lista simples: %ld comparações, média %.1f, pior %d\n", lista, lista / (double)N, N);

    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
