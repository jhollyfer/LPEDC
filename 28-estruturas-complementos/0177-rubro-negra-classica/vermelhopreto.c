// vermelhopreto.c · implementação da rubro-negra clássica (RB-INSERT do Cormen)
#include <stdio.h>
#include <stdlib.h>
#include "vermelhopreto.h"

ArvVP *vp_cria(void) {
    ArvVP *T = malloc(sizeof(ArvVP));
    if (T == NULL) {
        return NULL;
    }
    T->nil.chave = 0;
    T->nil.cor = PRETO; // propriedade 3: toda folha (nil) é preta
    T->nil.esq = T->nil.dir = T->nil.pai = &T->nil;
    T->raiz = &T->nil;
    T->rotacoes = 0;
    for (int i = 0; i < 4; i++) {
        T->casos[i] = 0;
    }
    return T;
}

static void gira_esquerda(ArvVP *T, NoVP *x) {
    NoVP *y = x->dir;
    x->dir = y->esq; // a subárvore esquerda de y passa para x
    if (y->esq != &T->nil) {
        y->esq->pai = x;
    }
    y->pai = x->pai; // y ocupa o lugar de x embaixo do pai
    if (x->pai == &T->nil) {
        T->raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
    T->rotacoes++;
}

static void gira_direita(ArvVP *T, NoVP *x) { // o espelho
    NoVP *y = x->esq;
    x->esq = y->dir;
    if (y->dir != &T->nil) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == &T->nil) {
        T->raiz = y;
    } else if (x == x->pai->dir) {
        x->pai->dir = y;
    } else {
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
    T->rotacoes++;
}

// RB-INSERT-FIXUP: enquanto o pai de z for vermelho, olha o tio
static void conserta(ArvVP *T, NoVP *z) {
    while (z->pai->cor == VERMELHO) {
        NoVP *avo = z->pai->pai;
        if (z->pai == avo->esq) {
            NoVP *tio = avo->dir;
            if (tio->cor == VERMELHO) { // caso 1: tio vermelho, recolore e sobe
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
                z = avo;
                T->casos[1]++;
            } else {
                if (z == z->pai->dir) { // caso 2: tio preto, z em "triângulo"
                    z = z->pai;
                    gira_esquerda(T, z);
                    T->casos[2]++;
                }
                z->pai->cor = PRETO; // caso 3: tio preto, z em "linha"
                z->pai->pai->cor = VERMELHO;
                gira_direita(T, z->pai->pai);
                T->casos[3]++;
            }
        } else { // o espelho: o pai é filho direito do avô
            NoVP *tio = avo->esq;
            if (tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
                z = avo;
                T->casos[1]++;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    gira_direita(T, z);
                    T->casos[2]++;
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                gira_esquerda(T, z->pai->pai);
                T->casos[3]++;
            }
        }
    }
    T->raiz->cor = PRETO; // propriedade 2: a raiz é preta
}

void vp_insere(ArvVP *T, int chave) {
    NoVP *y = &T->nil;
    NoVP *x = T->raiz;
    while (x != &T->nil) { // desce como na BST, lembrando o pai
        y = x;
        if (chave < x->chave) {
            x = x->esq;
        } else if (chave > x->chave) {
            x = x->dir;
        } else {
            return; // repetida
        }
    }
    NoVP *z = malloc(sizeof(NoVP));
    if (z == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    z->chave = chave;
    z->pai = y;
    if (y == &T->nil) {
        T->raiz = z;
    } else if (chave < y->chave) {
        y->esq = z;
    } else {
        y->dir = z;
    }
    z->esq = &T->nil;
    z->dir = &T->nil;
    z->cor = VERMELHO; // todo nó novo chega vermelho
    conserta(T, z);
}

NoVP *vp_busca(ArvVP *T, int chave) {
    NoVP *x = T->raiz;
    while (x != &T->nil && x->chave != chave) {
        x = chave < x->chave ? x->esq : x->dir;
    }
    return x;
}

static int altura(const ArvVP *T, const NoVP *x) {
    if (x == &T->nil) {
        return -1;
    }
    int he = altura(T, x->esq);
    int hd = altura(T, x->dir);
    return 1 + (he > hd ? he : hd);
}

int vp_altura(const ArvVP *T) {
    return altura(T, T->raiz);
}

int vp_altura_negra(const ArvVP *T) {
    int bh = 0;
    for (const NoVP *x = T->raiz; x != &T->nil; x = x->esq) {
        if (x->esq->cor == PRETO) { // conta os pretos abaixo da raiz, nil incluída
            bh++;
        }
    }
    return bh;
}

// devolve quantos pretos há de x até a folha nil (os dois inclusive),
// ou -1 se alguma propriedade falhar abaixo de x
static int confere(const ArvVP *T, const NoVP *x) {
    if (x == &T->nil) {
        return 1; // a folha nil é preta
    }
    if (x->cor == VERMELHO && (x->esq->cor == VERMELHO || x->dir->cor == VERMELHO)) {
        return -1; // propriedade 4: vermelho não tem filho vermelho
    }
    if ((x->esq != &T->nil && x->esq->chave >= x->chave) ||
        (x->dir != &T->nil && x->dir->chave <= x->chave)) {
        return -1; // a ordem da BST
    }
    int e = confere(T, x->esq);
    int d = confere(T, x->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1; // propriedade 5: mesma quantidade de pretos dos dois lados
    }
    return e + (x->cor == PRETO ? 1 : 0);
}

bool vp_confere(const ArvVP *T) {
    if (T->nil.cor != PRETO || T->raiz->cor != PRETO) {
        return false; // propriedades 2 e 3 (a 1, "todo nó é vermelho ou preto", vem do enum)
    }
    return confere(T, T->raiz) >= 0;
}

static void pre(const ArvVP *T, const NoVP *x) {
    if (x != &T->nil) {
        printf(" %d%s", x->chave, x->cor == VERMELHO ? "*" : "");
        pre(T, x->esq);
        pre(T, x->dir);
    }
}

void vp_pre_ordem(const ArvVP *T) {
    pre(T, T->raiz);
}

static void em(const ArvVP *T, const NoVP *x) {
    if (x != &T->nil) {
        em(T, x->esq);
        printf(" %d", x->chave);
        em(T, x->dir);
    }
}

void vp_em_ordem(const ArvVP *T) {
    em(T, T->raiz);
}

static void libera(ArvVP *T, NoVP *x) {
    if (x != &T->nil) {
        libera(T, x->esq);
        libera(T, x->dir);
        free(x);
    }
}

void vp_libera(ArvVP *T) {
    libera(T, T->raiz);
    free(T);
}
