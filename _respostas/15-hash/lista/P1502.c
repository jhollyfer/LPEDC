// Lista · Módulo 15 · Tabelas hash
// Exercício P1502 · ★☆☆ · As encomendas nos escaninhos

#include <stdio.h>
#include <stdlib.h>

#define M 7

typedef struct No {
    int codigo;
    struct No *prox;
} No;

void insere(No *tabela[], int codigo) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    int b = codigo % M;
    novo->codigo = codigo;
    novo->prox = tabela[b]; // no início da corrente: O(1)
    tabela[b] = novo;
}

void mostra(No *tabela[]) {
    for (int b = 0; b < M; b++) {
        printf("%d:", b);
        for (No *p = tabela[b]; p != NULL; p = p->prox) {
            printf(" %d", p->codigo);
        }
        printf("\n");
    }
}

void libera(No *tabela[]) {
    for (int b = 0; b < M; b++) {
        while (tabela[b] != NULL) {
            No *prox = tabela[b]->prox;
            free(tabela[b]);
            tabela[b] = prox;
        }
    }
}

int main(void) {
    No *tabela[M] = {NULL};
    int codigos[] = {40, 23, 17, 52, 11, 66, 5, 31, 26};
    for (int i = 0; i < 9; i++) {
        insere(tabela, codigos[i]);
    }
    mostra(tabela);
    libera(tabela);
    return 0;
}
