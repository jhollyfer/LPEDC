// 0087 · Deque
// Exercício E521 · ★★★
//
// O deque também pode ser feito com nós, mas precisa de lista DUPLA: para
// retirar do fim, o último nó tem que saber quem é o penúltimo (o ant).
// Complete as quatro operações deste deque encadeado, sem limite de
// capacidade. O main repete a história da fila de músicas do texto.
//
//   Saída esperada:
//   Tocando a faixa 11
//   Removida a faixa 3
//   Ainda na fila: 5 8
//
// Escreva sua resposta abaixo (complete as quatro funções):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int valor;
    struct nod *ant;
    struct nod *prox;
} NoD;

typedef struct {
    NoD *inicio;
    NoD *fim;
} DequeLista;

bool dl_insere_inicio(DequeLista *d, int valor) {
    (void)d; // apague estas linhas
    (void)valor;
    return false;
}

bool dl_insere_fim(DequeLista *d, int valor) {
    (void)d; // apague estas linhas
    (void)valor;
    return false;
}

bool dl_retira_inicio(DequeLista *d, int *valor) {
    (void)d; // apague estas linhas
    (void)valor;
    return false;
}

bool dl_retira_fim(DequeLista *d, int *valor) {
    (void)d; // apague estas linhas
    (void)valor;
    return false;
}

void dl_libera(DequeLista *d) {
    while (d->inicio != NULL) {
        NoD *prox = d->inicio->prox;
        free(d->inicio);
        d->inicio = prox;
    }
    d->fim = NULL;
}

int main(void) {
    DequeLista fila = {NULL, NULL};
    int faixa;

    dl_insere_fim(&fila, 5);
    dl_insere_fim(&fila, 8);
    dl_insere_fim(&fila, 3);
    dl_insere_inicio(&fila, 11);

    if (dl_retira_inicio(&fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (dl_retira_fim(&fila, &faixa)) {
        printf("Removida a faixa %d\n", faixa);
    }
    printf("Ainda na fila:");
    while (dl_retira_inicio(&fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");
    dl_libera(&fila);
    return 0;
}
