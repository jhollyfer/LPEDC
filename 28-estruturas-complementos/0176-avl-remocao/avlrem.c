// avlrem.c · implementação da AVL com remoção
#include <stdio.h>
#include <stdlib.h>
#include "avlrem.h"

static int rotacoes = 0;

int avr_altura(const NoA *r) {
    return r == NULL ? -1 : r->altura;
}

int avr_fator(const NoA *r) {
    return r == NULL ? 0 : avr_altura(r->esq) - avr_altura(r->dir);
}

int avr_rotacoes(void) {
    return rotacoes;
}

static void atualiza(NoA *r) {
    int he = avr_altura(r->esq);
    int hd = avr_altura(r->dir);
    r->altura = 1 + (he > hd ? he : hd);
}

static NoA *rot_direita(NoA *r) {
    NoA *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    rotacoes++;
    return e;
}

static NoA *rot_esquerda(NoA *r) {
    NoA *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    rotacoes++;
    return d;
}

// o mesmo rebalanceamento da inserção, com uma diferença: na remoção o
// filho do lado pesado pode ter fator 0, e aí basta a rotação simples
static NoA *rebalanceia(NoA *r) {
    atualiza(r);
    int fb = avr_fator(r);
    if (fb > 1) {
        if (avr_fator(r->esq) < 0) { // só -1 pede a dupla; 0 e 1, a simples
            r->esq = rot_esquerda(r->esq);
        }
        return rot_direita(r);
    }
    if (fb < -1) {
        if (avr_fator(r->dir) > 0) {
            r->dir = rot_direita(r->dir);
        }
        return rot_esquerda(r);
    }
    return r;
}

NoA *avr_insere(NoA *r, int chave) {
    if (r == NULL) {
        NoA *n = malloc(sizeof(NoA));
        if (n == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        n->chave = chave;
        n->altura = 0;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
    if (chave < r->chave) {
        r->esq = avr_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = avr_insere(r->dir, chave);
    } else {
        return r;
    }
    return rebalanceia(r);
}

NoA *avr_remove(NoA *r, int chave) {
    if (r == NULL) {
        return NULL; // não estava na árvore
    }
    if (chave < r->chave) {
        r->esq = avr_remove(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = avr_remove(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        NoA *filho = r->esq != NULL ? r->esq : r->dir; // 0 ou 1 filho
        free(r);
        return filho; // o filho (já AVL) ocupa o lugar; o pai confere
    } else {
        NoA *s = r->dir; // 2 filhos: copia o sucessor e remove ele
        while (s->esq != NULL) {
            s = s->esq;
        }
        r->chave = s->chave;
        r->dir = avr_remove(r->dir, s->chave);
    }
    return rebalanceia(r); // na volta, cada ancestral se confere
}

void avr_pre_ordem(const NoA *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        avr_pre_ordem(r->esq);
        avr_pre_ordem(r->dir);
    }
}

void avr_em_ordem(const NoA *r) {
    if (r != NULL) {
        avr_em_ordem(r->esq);
        printf(" %d", r->chave);
        avr_em_ordem(r->dir);
    }
}

NoA *avr_libera(NoA *r) {
    if (r != NULL) {
        avr_libera(r->esq);
        avr_libera(r->dir);
        free(r);
    }
    return NULL;
}
