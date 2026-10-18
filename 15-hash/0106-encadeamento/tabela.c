// tabela.c · implementação do TAD tabela hash com encadeamento
#include "tabela.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CHAVE 32

typedef struct No {
    char chave[TAM_CHAVE]; // cópia da chave (não um ponteiro emprestado)
    int valor;
    struct No *prox;
} No;

struct Tabela {
    int m;       // número de baldes
    int n;       // número de itens
    No **baldes; // vetor de m cabeças de lista
};

// hash polinomial de base 31, sempre em unsigned
static unsigned hash(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h;
}

Tabela *tabela_cria(int m) {
    Tabela *t = malloc(sizeof *t);
    if (t == NULL) {
        return NULL;
    }
    t->baldes = calloc((size_t)m, sizeof *t->baldes); // todos começam NULL
    if (t->baldes == NULL) {
        free(t);
        return NULL;
    }
    t->m = m;
    t->n = 0;
    return t;
}

bool tabela_insere(Tabela *t, const char *chave, int valor) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
        if (strcmp(p->chave, chave) == 0) { // já existe: atualiza
            p->valor = valor;
            return true;
        }
    }
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    snprintf(novo->chave, TAM_CHAVE, "%s", chave);
    novo->valor = valor;
    novo->prox = t->baldes[i]; // entra no início da corrente: O(1)
    t->baldes[i] = novo;
    t->n++;
    return true;
}

bool tabela_busca(const Tabela *t, const char *chave, int *valor, int *comparacoes) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    int olhados = 0;
    for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
        olhados++;
        if (strcmp(p->chave, chave) == 0) {
            *valor = p->valor;
            if (comparacoes != NULL) {
                *comparacoes = olhados;
            }
            return true;
        }
    }
    if (comparacoes != NULL) {
        *comparacoes = olhados;
    }
    return false;
}

bool tabela_remove(Tabela *t, const char *chave) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    No *ant = NULL;
    for (No *p = t->baldes[i]; p != NULL; ant = p, p = p->prox) {
        if (strcmp(p->chave, chave) == 0) {
            if (ant == NULL) {
                t->baldes[i] = p->prox; // era o primeiro da corrente
            } else {
                ant->prox = p->prox;
            }
            free(p);
            t->n--;
            return true;
        }
    }
    return false;
}

int tabela_tamanho(const Tabela *t) {
    return t->n;
}

void tabela_mostra(const Tabela *t) {
    for (int i = 0; i < t->m; i++) {
        printf("[%d]", i);
        for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
            printf(" -> %s:%d", p->chave, p->valor);
        }
        printf("\n");
    }
}

void tabela_libera(Tabela *t) {
    for (int i = 0; i < t->m; i++) {
        No *p = t->baldes[i];
        while (p != NULL) {
            No *prox = p->prox; // guarda antes de liberar
            free(p);
            p = prox;
        }
    }
    free(t->baldes);
    free(t);
}
