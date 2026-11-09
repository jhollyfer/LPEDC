// Lista · Módulo 14 · Árvores
// Exercício P1411 · ★★☆ · Sucessor e antecessor sem ponteiro para o pai

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

// menor chave maior que x (ou -1)
int sucessor(const No *r, int x) {
    int candidato = -1;
    while (r != NULL) {
        if (x < r->chave) {
            candidato = r->chave; // r é maior que x: pode ser a resposta
            r = r->esq;           // mas talvez haja um menor, à esquerda
        } else {
            r = r->dir;
        }
    }
    return candidato;
}

// maior chave menor que x (ou -1)
int antecessor(const No *r, int x) {
    int candidato = -1;
    while (r != NULL) {
        if (x > r->chave) {
            candidato = r->chave;
            r = r->dir;
        } else {
            r = r->esq;
        }
    }
    return candidato;
}

int main(void) {
    int horarios[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, horarios[i]);
    }

    int consultas[] = {40, 45, 65, 20, 80};
    for (int k = 0; k < 5; k++) {
        int x = consultas[k];
        printf("%d: antecessor %d, sucessor %d\n", x, antecessor(raiz, x), sucessor(raiz, x));
    }
    libera(raiz);
    return 0;
}
