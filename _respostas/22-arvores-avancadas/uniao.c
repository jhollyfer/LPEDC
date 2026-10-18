// uniao.c · implementação do TAD union-find (união por tamanho + compressão)
#include <stdio.h>
#include <stdlib.h>
#include "uniao.h"

UF *uf_cria(int n) {
    UF *u = malloc(sizeof(UF));
    if (u == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    u->pai = malloc(n * sizeof(int));
    u->tam = malloc(n * sizeof(int));
    if (u->pai == NULL || u->tam == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        u->pai[i] = i; // cada um é o seu próprio representante
        u->tam[i] = 1;
    }
    u->n = n;
    u->grupos = n;
    return u;
}

int uf_acha(UF *u, int x) {
    int raiz = x;
    while (u->pai[raiz] != raiz) { // sobe até a raiz
        raiz = u->pai[raiz];
    }
    while (u->pai[x] != raiz) {    // compressão: todo mundo do caminho
        int prox = u->pai[x];      // passa a apontar direto para a raiz
        u->pai[x] = raiz;
        x = prox;
    }
    return raiz;
}

bool uf_une(UF *u, int a, int b) {
    int ra = uf_acha(u, a);
    int rb = uf_acha(u, b);
    if (ra == rb) {
        return false; // já estavam juntos
    }
    if (u->tam[ra] < u->tam[rb]) { // ra fica sendo a raiz do grupo maior
        int t = ra;
        ra = rb;
        rb = t;
    }
    u->pai[rb] = ra; // a raiz do menor vira filha da raiz do maior
    u->tam[ra] += u->tam[rb];
    u->grupos--;
    return true;
}

bool uf_juntos(UF *u, int a, int b) {
    return uf_acha(u, a) == uf_acha(u, b);
}

int uf_grupos(const UF *u) {
    return u->grupos;
}

int uf_tamanho(UF *u, int x) {
    return u->tam[uf_acha(u, x)];
}

void uf_mostra(const UF *u) {
    printf("pai:");
    for (int i = 0; i < u->n; i++) {
        printf(" %d", u->pai[i]);
    }
    printf("\n");
}

void uf_libera(UF *u) {
    free(u->pai);
    free(u->tam);
    free(u);
}
