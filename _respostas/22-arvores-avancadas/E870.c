// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E870 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Convidado {
    char nome[20];
    bool vermelho;
    struct Convidado *esq, *dir;
} Convidado;

bool vermelho(const Convidado *c) {
    return c != NULL && c->vermelho;
}

Convidado *gira_esq(Convidado *h) {
    Convidado *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Convidado *gira_dir(Convidado *h) {
    Convidado *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Convidado *insere(Convidado *h, const char *nome) {
    if (h == NULL) {
        Convidado *c = malloc(sizeof(Convidado));
        if (c == NULL) {
            exit(1);
        }
        snprintf(c->nome, sizeof c->nome, "%s", nome);
        c->vermelho = true;
        c->esq = c->dir = NULL;
        return c;
    }
    int cmp = strcmp(nome, h->nome);
    if (cmp < 0) {
        h->esq = insere(h->esq, nome);
    } else if (cmp > 0) {
        h->dir = insere(h->dir, nome);
    }
    if (vermelho(h->dir) && !vermelho(h->esq)) {
        h = gira_esq(h);
    }
    if (vermelho(h->esq) && vermelho(h->esq->esq)) {
        h = gira_dir(h);
    }
    if (vermelho(h->esq) && vermelho(h->dir)) {
        h->vermelho = true;
        h->esq->vermelho = false;
        h->dir->vermelho = false;
    }
    return h;
}

bool busca(const Convidado *c, const char *nome) {
    while (c != NULL) {
        int cmp = strcmp(nome, c->nome);
        if (cmp == 0) {
            return true;
        }
        c = cmp < 0 ? c->esq : c->dir;
    }
    return false;
}

void em_ordem(const Convidado *c) {
    if (c != NULL) {
        em_ordem(c->esq);
        printf(" %s", c->nome);
        em_ordem(c->dir);
    }
}

void pre(const Convidado *c) {
    if (c != NULL) {
        printf(" %s%s", c->nome, c->vermelho ? "*" : "");
        pre(c->esq);
        pre(c->dir);
    }
}

int altura(const Convidado *c) {
    if (c == NULL) {
        return -1;
    }
    int e = altura(c->esq), d = altura(c->dir);
    return 1 + (e > d ? e : d);
}

int altura_preta(const Convidado *c) {
    int n = 0;
    for (; c != NULL; c = c->esq) {
        n += !c->vermelho;
    }
    return n;
}

void libera(Convidado *c) {
    if (c != NULL) {
        libera(c->esq);
        libera(c->dir);
        free(c);
    }
}

int main(void) {
    const char *lista[] = {"Marcos", "Ana", "Teresa", "Bruno", "Lia",
                           "Zeca", "Carla", "Otavio", "Duda", "Ana"};
    Convidado *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, lista[i]);
        raiz->vermelho = false;
    }
    printf("Em ordem:");
    em_ordem(raiz);
    printf("\nPré-ordem:");
    pre(raiz);
    printf("\nAltura %d, altura preta %d\n", altura(raiz), altura_preta(raiz));
    printf("Lia: %s | Rafa: %s\n", busca(raiz, "Lia") ? "na lista" : "fora",
           busca(raiz, "Rafa") ? "na lista" : "fora");
    libera(raiz);
    return 0;
}
