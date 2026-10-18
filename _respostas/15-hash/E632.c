// 0106 · Encadeamento
// Exercício E632 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 7

typedef struct No {
    int matricula;
    struct No *prox;
} No;

void insere(No *baldes[], int matricula) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    novo->matricula = matricula;
    novo->prox = baldes[matricula % M];
    baldes[matricula % M] = novo;
}

bool busca(No *baldes[], int matricula, int *comparacoes) {
    *comparacoes = 0;
    for (No *p = baldes[matricula % M]; p != NULL; p = p->prox) {
        (*comparacoes)++;
        if (p->matricula == matricula) {
            return true;
        }
    }
    return false;
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
    int alunos[] = {1021, 3344, 5005, 7210, 9876, 2016};
    for (int i = 0; i < 6; i++) {
        insere(baldes, alunos[i]);
    }

    int procurar[] = {5005, 4000};
    for (int i = 0; i < 2; i++) {
        int comp;
        bool achou = busca(baldes, procurar[i], &comp);
        printf("%d: %s (%d comparações)\n", procurar[i], achou ? "achou" : "não achou", comp);
    }
    libera(baldes);
    return 0;
}
