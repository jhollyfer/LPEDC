// Lista · Módulo 14 · Árvores
// Exercício P1414 · ★★☆ · Reconstruindo a árvore pela pós-ordem

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

// monta a árvore de em[ini..fim]; *ultimo anda de trás para frente na pós
No *monta(const int em[], int ini, int fim, const int pos[], int *ultimo) {
    if (ini > fim) {
        return NULL;
    }
    No *r = malloc(sizeof(No));
    if (r == NULL) {
        exit(1);
    }
    r->chave = pos[(*ultimo)--]; // a raiz é a última da pós
    int m = ini;
    while (em[m] != r->chave) {
        m++;
    }
    // na pós (lida de trás para frente) vem a raiz, depois a DIREITA
    r->dir = monta(em, m + 1, fim, pos, ultimo);
    r->esq = monta(em, ini, m - 1, pos, ultimo);
    return r;
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

int altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq), hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int em[] = {4, 2, 7, 5, 1, 3, 6};
    int pos[] = {4, 7, 5, 2, 6, 3, 1};
    int n = 7, ultimo = n - 1;

    No *raiz = monta(em, 0, n - 1, pos, &ultimo);
    printf("pré:");
    pre(raiz);
    printf("\naltura: %d\n", altura(raiz));
    libera(raiz);
    return 0;
}
