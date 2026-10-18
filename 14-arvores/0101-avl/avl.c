// avl.c · implementação do TAD árvore AVL
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static int rotacoes = 0;

int avl_altura(const No *r) {
    return r == NULL ? -1 : r->altura;
}

int avl_fator(const No *r) {
    return r == NULL ? 0 : avl_altura(r->esq) - avl_altura(r->dir);
}

int avl_rotacoes(void) {
    return rotacoes;
}

// recalcula a altura de r a partir dos filhos (que já estão certos)
static void atualiza(No *r) {
    int he = avl_altura(r->esq);
    int hd = avl_altura(r->dir);
    r->altura = 1 + (he > hd ? he : hd);
}

/* rotação à direita: o filho esquerdo sobe e r desce para a direita
 *
 *        r              e
 *       / \            / \
 *      e   C   ==>    A   r
 *     / \                / \
 *    A   B              B   C
 */
static No *rot_direita(No *r) {
    No *e = r->esq;
    r->esq = e->dir; // B muda de pai
    e->dir = r;
    atualiza(r); // r agora está embaixo: primeiro ele
    atualiza(e);
    rotacoes++;
    return e;
}

// o espelho da anterior
static No *rot_esquerda(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    rotacoes++;
    return d;
}

static No *rebalanceia(No *r) {
    atualiza(r);
    int fb = avl_fator(r);
    if (fb > 1) {                    // pesado à esquerda
        if (avl_fator(r->esq) < 0) { // filho pesado à direita: caso dupla
            r->esq = rot_esquerda(r->esq);
        }
        return rot_direita(r);
    }
    if (fb < -1) {                   // pesado à direita
        if (avl_fator(r->dir) > 0) { // filho pesado à esquerda: caso dupla
            r->dir = rot_direita(r->dir);
        }
        return rot_esquerda(r);
    }
    return r; // fator -1, 0 ou 1: tudo certo
}

No *avl_insere(No *r, int chave) {
    if (r == NULL) {
        No *n = malloc(sizeof(No));
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
        r->esq = avl_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = avl_insere(r->dir, chave);
    } else {
        return r;
    }
    return rebalanceia(r); // na volta da recursão, cada ancestral se confere
}

void avl_pre_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    avl_pre_ordem(r->esq);
    avl_pre_ordem(r->dir);
}

void avl_em_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    avl_em_ordem(r->esq);
    printf(" %d", r->chave);
    avl_em_ordem(r->dir);
}

No *avl_libera(No *r) {
    if (r != NULL) {
        avl_libera(r->esq);
        avl_libera(r->dir);
        free(r);
    }
    return NULL;
}
