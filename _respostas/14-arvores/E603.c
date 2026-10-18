// 0101 · AVL: balanceamento e rotações
// Exercício E603 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esq, *dir;
} Arv;

Arv *no(int chave, Arv *esq, Arv *dir) {
    Arv *n = malloc(sizeof(Arv));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    return n;
}

void libera(Arv *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int altura_se_avl(const Arv *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura_se_avl(r->esq);
    int hd = altura_se_avl(r->dir);
    if (he == -2 || hd == -2) {
        return -2; // o problema já apareceu lá embaixo
    }
    int fb = he - hd;
    if (fb > 1 || fb < -1) {
        return -2;
    }
    return 1 + (he > hd ? he : hd);
}

void testa(const char *nome, const Arv *r) {
    int h = altura_se_avl(r);
    if (h == -2) {
        printf("%s: não é AVL\n", nome);
    } else {
        printf("%s: é AVL, altura %d\n", nome, h);
    }
}

int main(void) {
    Arv *a1 = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                 no(70, NULL, no(80, NULL, no(90, NULL, NULL))));
    Arv *a2 = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                 no(80, no(70, NULL, NULL), no(90, NULL, NULL)));
    testa("Árvore 1", a1);
    testa("Árvore 2", a2);
    libera(a1);
    libera(a2);
    return 0;
}
