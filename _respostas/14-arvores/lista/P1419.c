// Lista · Módulo 14 · Árvores
// Exercício P1419 · ★★☆ · O ancestral comum das estações

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

// ancestral comum mais baixo de a e b (os dois estão na árvore)
const No *ancestral(const No *r, int a, int b) {
    while (r != NULL) {
        if (a < r->chave && b < r->chave) {
            r = r->esq;
        } else if (a > r->chave && b > r->chave) {
            r = r->dir;
        } else {
            return r; // os dois se separam aqui (ou um deles é r)
        }
    }
    return NULL;
}

int profundidade(const No *r, int x) {
    int p = 0;
    while (r != NULL && r->chave != x) {
        r = (x < r->chave) ? r->esq : r->dir;
        p++;
    }
    return p;
}

int main(void) {
    int km[] = {60, 25, 90, 10, 40, 75, 120, 30, 50, 80};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, km[i]);
    }

    int pares[][2] = {{30, 50}, {10, 50}, {80, 120}, {30, 80}, {25, 30}};
    for (int i = 0; i < 5; i++) {
        int a = pares[i][0], b = pares[i][1];
        const No *c = ancestral(raiz, a, b);
        int dist = profundidade(raiz, a) + profundidade(raiz, b) - 2 * profundidade(raiz, c->chave);
        printf("%d e %d: ancestral %d, distância %d\n", a, b, c->chave, dist);
    }
    libera(raiz);
    return 0;
}
