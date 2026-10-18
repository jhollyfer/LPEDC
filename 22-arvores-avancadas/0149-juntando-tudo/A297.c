// A297 · Trie, hash e BST no mesmo dicionário

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corretor.h"

// dicionário sintético: as 2500 palavras de duas sílabas (ba, be, ..., zu)
#define N 2500
#define BALDES 2503 // primo, perto de N

long passos; // comparações de string (BST e hash) ou nós visitados (trie)

// ---- BST de strings ----
typedef struct NoS {
    char p[8];
    struct NoS *esq, *dir;
} NoS;

NoS *bst_poe(NoS *r, const char *p) {
    if (r == NULL) {
        NoS *n = malloc(sizeof(NoS));
        if (n == NULL) {
            exit(1);
        }
        strcpy(n->p, p);
        n->esq = n->dir = NULL;
        return n;
    }
    int c = strcmp(p, r->p);
    if (c < 0) {
        r->esq = bst_poe(r->esq, p);
    } else if (c > 0) {
        r->dir = bst_poe(r->dir, p);
    }
    return r;
}

int bst_tem(const NoS *r, const char *p) {
    while (r != NULL) {
        passos++;
        int c = strcmp(p, r->p);
        if (c == 0) {
            return 1;
        }
        r = c < 0 ? r->esq : r->dir;
    }
    return 0;
}

int bst_altura(const NoS *r) {
    if (r == NULL) {
        return -1;
    }
    int e = bst_altura(r->esq), d = bst_altura(r->dir);
    return 1 + (e > d ? e : d);
}

void bst_solta(NoS *r) {
    if (r != NULL) {
        bst_solta(r->esq);
        bst_solta(r->dir);
        free(r);
    }
}

// ---- tabela hash com encadeamento ----
typedef struct NoH {
    char p[8];
    struct NoH *prox;
} NoH;

unsigned espalha(const char *p) { // djb2
    unsigned h = 5381;
    for (; *p != '\0'; p++) {
        h = h * 33 + (unsigned char)*p;
    }
    return h % BALDES;
}

void hash_poe(NoH *t[], const char *p) {
    NoH *n = malloc(sizeof(NoH));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->p, p);
    unsigned b = espalha(p);
    n->prox = t[b];
    t[b] = n;
}

int hash_tem(NoH *t[], const char *p) {
    for (const NoH *n = t[espalha(p)]; n != NULL; n = n->prox) {
        passos++;
        if (strcmp(n->p, p) == 0) {
            return 1;
        }
    }
    return 0;
}

// ---- trie (do TAD): conta os nós visitados ----
int trie_tem(const NoC *d, const char *p) {
    for (; *p != '\0' && d != NULL; p++) {
        passos++;
        d = d->filho[*p - 'a'];
    }
    return d != NULL && d->fim;
}

int main(void) {
    const char *cons = "bcdfglmprz", *vog = "aeiou";
    static char pal[N][8];
    for (int i = 0; i < N; i++) { // sílaba 1 = i / 50, sílaba 2 = i % 50
        int s1 = i / 50, s2 = i % 50;
        snprintf(pal[i], 8, "%c%c%c%c", cons[s1 / 5], vog[s1 % 5], cons[s2 / 5], vog[s2 % 5]);
    }

    // embaralha a ordem de inserção (Fisher-Yates com um gerador fixo), senão
    // a BST receberia as palavras em ordem alfabética e viraria uma lista
    static int ordem[N];
    unsigned x = 2024;
    for (int i = 0; i < N; i++) {
        ordem[i] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        x = x * 1103515245u + 12345u;
        int j = (int)((x >> 8) % (unsigned)(i + 1));
        int t = ordem[i];
        ordem[i] = ordem[j];
        ordem[j] = t;
    }

    NoS *bst = NULL;
    static NoH *tabela[BALDES];
    NoC *trie = cor_cria();
    for (int i = 0; i < N; i++) {
        const char *p = pal[ordem[i]];
        bst = bst_poe(bst, p);
        hash_poe(tabela, p);
        cor_insere(trie, p);
    }

    // 2500 buscas que acham e 2500 que não acham (troca a última vogal por 'x')
    long pb = 0, ph = 0, pt = 0;
    for (int i = 0; i < N; i++) {
        char falsa[8];
        strcpy(falsa, pal[i]);
        falsa[3] = 'x';
        passos = 0; bst_tem(bst, pal[i]); bst_tem(bst, falsa); pb += passos;
        passos = 0; hash_tem(tabela, pal[i]); hash_tem(tabela, falsa); ph += passos;
        passos = 0; trie_tem(trie, pal[i]); trie_tem(trie, falsa); pt += passos;
    }
    int maior_balde = 0;
    for (int b = 0; b < BALDES; b++) {
        int k = 0;
        for (const NoH *n = tabela[b]; n != NULL; n = n->prox) {
            k++;
        }
        maior_balde = k > maior_balde ? k : maior_balde;
    }

    printf("%d palavras, %d buscas\n", N, 2 * N);
    printf("BST:  %4.1f comparações de string por busca | altura %d | %zu bytes\n",
           (double)pb / (2 * N), bst_altura(bst), N * sizeof(NoS));
    printf("hash: %4.1f comparações de string por busca | maior balde %d | %zu bytes\n",
           (double)ph / (2 * N), maior_balde, N * sizeof(NoH) + BALDES * sizeof(NoH *));
    printf("trie: %4.1f nós visitados por busca         | %d nós | %zu bytes\n",
           (double)pt / (2 * N), cor_nos(trie), cor_nos(trie) * sizeof(NoC));

    bst_solta(bst);
    for (int b = 0; b < BALDES; b++) {
        while (tabela[b] != NULL) {
            NoH *prox = tabela[b]->prox;
            free(tabela[b]);
            tabela[b] = prox;
        }
    }
    cor_libera(trie);
    return 0;
}
// Saída:
// 2500 palavras, 5000 buscas
// BST:  17.2 comparações de string por busca | altura 29 | 60000 bytes
// hash:  1.3 comparações de string por busca | maior balde 5 | 60024 bytes
// trie:  4.0 nós visitados por busca         | 3061 nós | 661176 bytes
