// Lista · Módulo 14 · Árvores
// Exercício P1422 · ★★★ · A BST de volta a partir da pré-ordem

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

// usa pre[*i] se ele couber no intervalo aberto (min, max)
No *monta(const int pre[], int n, int *i, int min, int max) {
    if (*i >= n || pre[*i] <= min || pre[*i] >= max) {
        return NULL;
    }
    No *r = malloc(sizeof(No));
    if (r == NULL) {
        exit(1);
    }
    r->chave = pre[(*i)++];
    r->esq = monta(pre, n, i, min, r->chave);
    r->dir = monta(pre, n, i, r->chave, max);
    return r;
}

void em(const No *r) {
    if (r != NULL) {
        em(r->esq);
        printf(" %d", r->chave);
        em(r->dir);
    }
}

void pos(const No *r) {
    if (r != NULL) {
        pos(r->esq);
        pos(r->dir);
        printf(" %d", r->chave);
    }
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void testa(const char *nome, const int pre[], int n) {
    int i = 0;
    No *r = monta(pre, n, &i, INT_MIN, INT_MAX);
    printf("%s: ", nome);
    if (i < n) {
        printf("não é pré-ordem de BST (parou no %d, posição %d)\n", pre[i], i);
    } else {
        printf("ok\n  em: ");
        em(r);
        printf("\n  pós:");
        pos(r);
        printf("\n");
    }
    libera(r);
}

int main(void) {
    int backup1[] = {45, 20, 10, 30, 25, 35, 70, 60, 90};
    int backup2[] = {45, 20, 50, 30, 60};
    int backup3[] = {8, 5, 1, 7, 10, 12};

    testa("backup 1", backup1, 9);
    testa("backup 2", backup2, 5);
    testa("backup 3", backup3, 6);
    return 0;
}
