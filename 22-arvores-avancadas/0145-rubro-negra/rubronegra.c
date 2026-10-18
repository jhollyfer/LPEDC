// rubronegra.c · implementação do TAD árvore rubro-negra esquerdista (LLRB)
#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

static int rotacoes = 0;
static int inversoes = 0;

static bool eh_vermelho(const NoRN *n) {
    return n != NULL && n->vermelho; // NULL conta como preto
}

static NoRN *novo_no(int chave) {
    NoRN *n = malloc(sizeof(NoRN));
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    n->chave = chave;
    n->vermelho = true; // todo nó novo chega vermelho
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// o filho direito (vermelho) sobe; o link vermelho passa para a esquerda
static NoRN *gira_esquerda(NoRN *h) {
    NoRN *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho; // x herda a cor do link que chegava em h
    h->vermelho = true;
    rotacoes++;
    return x;
}

// o filho esquerdo (vermelho) sobe; espelho da anterior
static NoRN *gira_direita(NoRN *h) {
    NoRN *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    rotacoes++;
    return x;
}

// dois filhos vermelhos: eles ficam pretos e o vermelho sobe para h
static void inverte_cores(NoRN *h) {
    h->vermelho = true;
    h->esq->vermelho = false;
    h->dir->vermelho = false;
    inversoes++;
}

static NoRN *insere(NoRN *h, int chave) {
    if (h == NULL) {
        return novo_no(chave);
    }
    if (chave < h->chave) {
        h->esq = insere(h->esq, chave);
    } else if (chave > h->chave) {
        h->dir = insere(h->dir, chave);
    }
    // na volta, os três consertos, nesta ordem
    if (eh_vermelho(h->dir) && !eh_vermelho(h->esq)) {
        h = gira_esquerda(h);      // 1. vermelho à direita
    }
    if (eh_vermelho(h->esq) && eh_vermelho(h->esq->esq)) {
        h = gira_direita(h);       // 2. dois vermelhos seguidos
    }
    if (eh_vermelho(h->esq) && eh_vermelho(h->dir)) {
        inverte_cores(h);          // 3. dois filhos vermelhos
    }
    return h;
}

NoRN *rn_insere(NoRN *raiz, int chave) {
    raiz = insere(raiz, chave);
    raiz->vermelho = false; // a raiz é sempre preta
    return raiz;
}

bool rn_busca(const NoRN *r, int chave) {
    while (r != NULL && r->chave != chave) {
        r = chave < r->chave ? r->esq : r->dir;
    }
    return r != NULL;
}

int rn_altura(const NoRN *r) {
    if (r == NULL) {
        return -1;
    }
    int he = rn_altura(r->esq);
    int hd = rn_altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

int rn_altura_preta(const NoRN *r) {
    int pretos = 0;
    for (; r != NULL; r = r->esq) { // todo caminho tem o mesmo número: basta um
        if (!r->vermelho) {
            pretos++;
        }
    }
    return pretos;
}

void rn_pre_ordem(const NoRN *r) {
    if (r != NULL) {
        printf(" %d%s", r->chave, r->vermelho ? "*" : "");
        rn_pre_ordem(r->esq);
        rn_pre_ordem(r->dir);
    }
}

void rn_em_ordem(const NoRN *r) {
    if (r != NULL) {
        rn_em_ordem(r->esq);
        printf(" %d", r->chave);
        rn_em_ordem(r->dir);
    }
}

int rn_rotacoes(void) {
    return rotacoes;
}

int rn_inversoes(void) {
    return inversoes;
}

NoRN *rn_libera(NoRN *r) {
    if (r != NULL) {
        rn_libera(r->esq);
        rn_libera(r->dir);
        free(r);
    }
    return NULL;
}
