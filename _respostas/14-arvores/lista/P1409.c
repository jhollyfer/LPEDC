// Lista · Módulo 14 · Árvores
// Exercício P1409 · ★☆☆ · Contando os nós pelo número de filhos

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

// grau[g] conta os nós com g filhos
void conta_graus(const No *r, int grau[3]) {
    if (r == NULL) {
        return;
    }
    int g = (r->esq != NULL) + (r->dir != NULL);
    grau[g]++;
    conta_graus(r->esq, grau);
    conta_graus(r->dir, grau);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int precos[] = {45, 22, 67, 10, 30, 55, 80, 5, 27, 90, 85};
    No *raiz = NULL;
    for (int i = 0; i < 11; i++) {
        raiz = insere(raiz, precos[i]);
    }

    int grau[3] = {0, 0, 0};
    conta_graus(raiz, grau);
    printf("folhas (0 filhos): %d\n", grau[0]);
    printf("com 1 filho: %d\n", grau[1]);
    printf("com 2 filhos: %d\n", grau[2]);
    printf("total: %d nós\n", grau[0] + grau[1] + grau[2]);
    printf("folhas = (2 filhos) + 1? %s\n", grau[0] == grau[2] + 1 ? "sim" : "não");
    libera(raiz);
    return 0;
}
