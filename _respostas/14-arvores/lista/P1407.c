// Lista · Módulo 14 · Árvores
// Exercício P1407 · ★☆☆ · O fator de cada nó

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq), hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

// mostra o fator de cada nó em ordem; devolve true se todos estão em -1..1
bool fatores(const No *r) {
    if (r == NULL) {
        return true;
    }
    bool ok_esq = fatores(r->esq);
    int f = altura(r->esq) - altura(r->dir);
    printf("%d: fator %d\n", r->chave, f);
    bool ok_dir = fatores(r->dir);
    return ok_esq && ok_dir && f >= -1 && f <= 1;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int pedidos[] = {40, 20, 60, 10, 30, 25, 35, 70, 27};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, pedidos[i]);
    }

    bool avl = fatores(raiz);
    printf("é AVL? %s\n", avl ? "sim" : "não");
    libera(raiz);
    return 0;
}
