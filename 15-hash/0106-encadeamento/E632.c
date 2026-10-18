// 0106 · Encadeamento
// Exercício E632 · ★☆☆
//
// A academia guarda as matrículas numa tabela com 7 baldes e encadeamento
// (h = matricula % 7). A inserção e a liberação já estão prontas. Complete a
// função busca: ela percorre a corrente do balde certo, conta em
// *comparacoes quantos nós olhou e devolve true se achou a matrícula.
//
//   Saída esperada:
//   5005: achou (3 comparações)
//   4000: não achou (0 comparações)
//
// Dicas:
// 1. O balde é matricula % M; a corrente começa em baldes[matricula % M].
// 2. Use "(*comparacoes)++" a cada nó visitado, antes de comparar.
// 3. Resposta esperada: a saída acima. 5005, 7210 e 2016 caem no balde 0, e
//    a corrente ficou 2016 -> 7210 -> 5005. O balde 3, do 4000, está vazio.
//
// Escreva sua resposta abaixo (complete o código):

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
    (void)baldes;    // apague estas duas linhas
    (void)matricula; // quando usar os parâmetros

    // complete aqui

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
