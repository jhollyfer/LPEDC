// 0101 · AVL: balanceamento e rotações
// Exercício E601 · ★☆☆

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

int altura(const Arv *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq);
    int hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

// pré-ordem: mostra o nó e depois as subárvores; devolve quantos estão fora
int relatorio(const Arv *r) {
    if (r == NULL) {
        return 0;
    }
    int fator = altura(r->esq) - altura(r->dir);
    int ruim = fator < -1 || fator > 1;
    printf("%d: altura %d, fator %d%s\n", r->chave, altura(r), fator,
           ruim ? " <- desequilibrado" : "");
    return ruim + relatorio(r->esq) + relatorio(r->dir);
}

int main(void) {
    Arv *raiz = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                   no(70, NULL, no(80, NULL, no(90, NULL, NULL))));

    int ruins = relatorio(raiz);
    printf("É AVL? %s\n", ruins == 0 ? "sim" : "não");
    libera(raiz);
    return 0;
}
