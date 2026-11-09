// 0175 · Conceitos e sucessor
// Exercício E1049 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct Saida {
    int hora;
    struct Saida *esq, *dir, *pai;
} Saida;

Saida *insere(Saida *raiz, int hora) {
    Saida *pai = NULL;
    Saida *x = raiz;
    while (x != NULL) {
        pai = x;
        x = hora < x->hora ? x->esq : x->dir;
    }
    Saida *z = malloc(sizeof(Saida));
    if (z == NULL) {
        exit(1);
    }
    z->hora = hora;
    z->esq = z->dir = NULL;
    z->pai = pai;
    if (pai == NULL) {
        return z;
    }
    if (hora < pai->hora) {
        pai->esq = z;
    } else {
        pai->dir = z;
    }
    return raiz;
}

Saida *minimo(Saida *x) {
    while (x->esq != NULL) {
        x = x->esq;
    }
    return x;
}

Saida *sucessor(Saida *x) {
    if (x->dir != NULL) {
        return minimo(x->dir);
    }
    Saida *y = x->pai;
    while (y != NULL && x == y->dir) { // sobe enquanto vem da direita
        x = y;
        y = y->pai;
    }
    return y;
}

void libera(Saida *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int horas[] = {800, 615, 1030, 700, 650, 920, 1200, 730};
    Saida *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = insere(raiz, horas[i]);
    }
    // percorre em ordem com uma lista fixa de horários, para não depender
    // do próprio sucessor para andar
    int ordem[] = {615, 650, 700, 730, 800, 920, 1030, 1200};
    for (int i = 0; i < 8; i++) {
        Saida *x = raiz;
        while (x->hora != ordem[i]) {
            x = ordem[i] < x->hora ? x->esq : x->dir;
        }
        Saida *s = sucessor(x);
        printf("depois de %dh%02d: ", x->hora / 100, x->hora % 100);
        if (s == NULL) {
            printf("nenhum\n");
        } else {
            printf("%dh%02d\n", s->hora / 100, s->hora % 100);
        }
    }
    libera(raiz);
    return 0;
}
