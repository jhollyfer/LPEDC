// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2829 · ★★★ · O cache da biblioteca

#include <stdio.h>
#include <stdlib.h>

#define M 7
#define CAPACIDADE 3

typedef struct No {
    int pagina;
    struct No *ant, *prox;
} No;

enum { LIVRE, OCUPADA, LAPIDE };

typedef struct {
    int pagina, estado;
    No *no;
} Pos;

static No nil;
static Pos tab[M];
static int tamanho = 0;

int acha(int p) {
    for (int i = 0; i < M; i++) {
        int j = (p % M + i) % M;
        if (tab[j].estado == LIVRE) {
            return -1;
        }
        if (tab[j].estado == OCUPADA && tab[j].pagina == p) {
            return j;
        }
    }
    return -1;
}

void guarda(int p, No *x) {
    for (int i = 0; i < M; i++) {
        int j = (p % M + i) % M;
        if (tab[j].estado != OCUPADA) {
            tab[j].pagina = p;
            tab[j].no = x;
            tab[j].estado = OCUPADA;
            return;
        }
    }
}

void desliga(No *x) {
    x->ant->prox = x->prox;
    x->prox->ant = x->ant;
}

void na_frente(No *x) {
    x->prox = nil.prox;
    x->ant = &nil;
    nil.prox->ant = x;
    nil.prox = x;
}

char acessa(int p) {
    int j = acha(p);
    if (j >= 0) {
        No *x = tab[j].no;
        desliga(x);
        na_frente(x);
        return 'A';
    }
    No *x;
    if (tamanho == CAPACIDADE) { // reaproveita o nó do menos recente
        x = nil.ant;
        desliga(x);
        tab[acha(x->pagina)].estado = LAPIDE;
    } else {
        x = malloc(sizeof(No));
        if (x == NULL) {
            exit(1);
        }
        tamanho++;
    }
    x->pagina = p;
    na_frente(x);
    guarda(p, x);
    return 'F';
}

int main(void) {
    nil.prox = nil.ant = &nil;
    int acessos[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int faltas = 0;
    for (int i = 0; i < 13; i++) {
        char r = acessa(acessos[i]);
        faltas += r == 'F';
        printf("%d: %c [", acessos[i], r);
        for (const No *x = nil.prox; x != &nil; x = x->prox) {
            printf(" %d", x->pagina);
        }
        printf(" ]\n");
    }
    printf("faltas: %d de 13\n", faltas);
    No *x = nil.prox;
    while (x != &nil) {
        No *s = x->prox;
        free(x);
        x = s;
    }
    return 0;
}
