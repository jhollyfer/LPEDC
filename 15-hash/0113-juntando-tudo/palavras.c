// palavras.c · implementação do contador com encadeamento
#include "palavras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char palavra[TAM_PALAVRA];
    int vezes;
    struct No *prox;
} No;

struct Contador {
    int m;         // baldes
    int distintas; // nós na tabela
    int total;     // somas feitas
    No **baldes;
};

// polinômio de base 31 sobre os bytes: funciona com UTF-8 sem índice negativo
static unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h;
}

static No *procura(const Contador *c, const char *palavra, unsigned *balde) {
    *balde = espalha(palavra) % (unsigned)c->m;
    for (No *p = c->baldes[*balde]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, palavra) == 0) {
            return p;
        }
    }
    return NULL;
}

Contador *contador_cria(int m) {
    Contador *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    c->baldes = calloc((size_t)m, sizeof *c->baldes);
    if (c->baldes == NULL) {
        free(c);
        return NULL;
    }
    c->m = m;
    c->distintas = 0;
    c->total = 0;
    return c;
}

bool contador_soma(Contador *c, const char *palavra) {
    unsigned b;
    No *p = procura(c, palavra, &b);
    if (p == NULL) { // primeira vez: cria o nó no início da corrente
        p = malloc(sizeof *p);
        if (p == NULL) {
            return false;
        }
        snprintf(p->palavra, TAM_PALAVRA, "%s", palavra); // copia a palavra
        p->vezes = 0;
        p->prox = c->baldes[b];
        c->baldes[b] = p;
        c->distintas++;
    }
    p->vezes++;
    c->total++;
    return true;
}

int contador_vezes(const Contador *c, const char *palavra) {
    unsigned b;
    No *p = procura(c, palavra, &b);
    return p == NULL ? 0 : p->vezes;
}

int contador_total(const Contador *c) {
    return c->total;
}

int contador_distintas(const Contador *c) {
    return c->distintas;
}

Contagem *contador_lista(const Contador *c) {
    Contagem *v = malloc((size_t)(c->distintas > 0 ? c->distintas : 1) * sizeof *v);
    if (v == NULL) {
        return NULL;
    }
    int k = 0;
    for (int b = 0; b < c->m; b++) {
        for (No *p = c->baldes[b]; p != NULL; p = p->prox) {
            v[k].palavra = p->palavra;
            v[k].vezes = p->vezes;
            k++;
        }
    }
    return v;
}

void contador_libera(Contador *c) {
    for (int b = 0; b < c->m; b++) {
        No *p = c->baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(c->baldes);
    free(c);
}
