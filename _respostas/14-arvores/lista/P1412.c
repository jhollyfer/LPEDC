// Lista · Módulo 14 · Árvores
// Exercício P1412 · ★★☆ · Remoções em sequência na BST

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

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

No *remove_chave(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_chave(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_chave(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        // 0 ou 1 filho: o filho (ou NULL) toma o lugar
        No *filho = (r->esq != NULL) ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        // 2 filhos: copia o sucessor e remove o sucessor da direita
        No *s = r->dir;
        while (s->esq != NULL) {
            s = s->esq;
        }
        r->chave = s->chave;
        r->dir = remove_chave(r->dir, s->chave);
    }
    return r;
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

int main(void) {
    int armarios[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, armarios[i]);
    }
    printf("início:   ");
    pre(raiz);
    printf("\n");

    int saem[] = {20, 60, 30, 50};
    for (int k = 0; k < 4; k++) {
        raiz = remove_chave(raiz, saem[k]);
        printf("sem o %d:", saem[k]);
        pre(raiz);
        printf("\n");
    }
    libera(raiz);
    return 0;
}
