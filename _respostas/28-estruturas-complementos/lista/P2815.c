// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2815 · ★★☆ · O fiscal da rubro-negra

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    char cor;
    struct No *esq, *dir;
} No;

No *novo(int chave, char cor, No *esq, No *dir) {
    No *x = malloc(sizeof(No));
    if (x == NULL) {
        exit(1);
    }
    x->chave = chave;
    x->cor = cor;
    x->esq = esq;
    x->dir = dir;
    return x;
}

int vermelho(const No *x) {
    return x != NULL && x->cor == 'V';
}

int fiscal(const No *x) {
    if (x == NULL) {
        return 0;
    }
    if (vermelho(x) && (vermelho(x->esq) || vermelho(x->dir))) {
        return -1;
    }
    int e = fiscal(x->esq), d = fiscal(x->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (x->cor == 'P');
}

void confere(const char *nome, const No *raiz) {
    int bh = fiscal(raiz);
    if (raiz->cor != 'P' || bh < 0) {
        printf("%s: não é rubro-negra\n", nome);
    } else {
        printf("%s: rubro-negra, altura negra %d\n", nome, bh);
    }
}

void libera(No *x) {
    if (x != NULL) {
        libera(x->esq);
        libera(x->dir);
        free(x);
    }
}

int main(void) {
    No *a = novo(20, 'P', novo(10, 'V', novo(5, 'P', NULL, NULL), novo(15, 'P', NULL, NULL)),
                 novo(30, 'P', NULL, novo(35, 'V', NULL, NULL)));
    No *b = novo(20, 'P', novo(10, 'V', novo(5, 'V', NULL, NULL), novo(15, 'P', NULL, NULL)),
                 novo(30, 'P', NULL, NULL));
    No *c = novo(20, 'P', novo(10, 'P', novo(5, 'P', NULL, NULL), NULL), novo(30, 'P', NULL, NULL));
    confere("A", a);
    confere("B", b);
    confere("C", c);
    libera(a);
    libera(b);
    libera(c);
    return 0;
}
