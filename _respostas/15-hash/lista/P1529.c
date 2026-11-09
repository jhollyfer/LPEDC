// Lista · Módulo 15 · Tabelas hash
// Exercício P1529 · ★★★ · As três palavras mais usadas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 11

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

// devolve 1 se a palavra era nova
int conta(No *t[], const char *p) {
    int b = (int)(djb2(p) % M);
    for (No *q = t[b]; q != NULL; q = q->prox) {
        if (strcmp(q->palavra, p) == 0) {
            q->vezes++;
            return 0;
        }
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    snprintf(novo->palavra, sizeof novo->palavra, "%s", p);
    novo->vezes = 1;
    novo->prox = t[b];
    t[b] = novo;
    return 1;
}

// mais vezes primeiro; empate em ordem alfabética
int compara(const void *a, const void *b) {
    const No *x = *(const No *const *)a, *y = *(const No *const *)b;
    if (x->vezes != y->vezes) {
        return (y->vezes > x->vezes) - (y->vezes < x->vezes);
    }
    return strcmp(x->palavra, y->palavra);
}

int main(void) {
    const char *texto = "o sol nasce e o mar brilha e o vento sopra e o barco sai do cais e o sol se poe no mar";
    No *t[M] = {NULL};
    int distintas = 0;

    char palavra[16];
    int tam = 0;
    for (const char *s = texto;; s++) {
        if (*s == ' ' || *s == '\0') {
            if (tam > 0) {
                palavra[tam] = '\0';
                distintas += conta(t, palavra);
                tam = 0;
            }
            if (*s == '\0') {
                break;
            }
        } else if (tam < 15) {
            palavra[tam++] = *s;
        }
    }

    // vetor de ponteiros para os nós: ordena sem mexer na tabela
    No **v = malloc(distintas * sizeof(No *));
    if (v == NULL) {
        exit(1);
    }
    int k = 0;
    for (int b = 0; b < M; b++) {
        for (No *q = t[b]; q != NULL; q = q->prox) {
            v[k++] = q;
        }
    }
    qsort(v, distintas, sizeof v[0], compara);
    printf("%d palavras distintas\n", distintas);
    for (int i = 0; i < 3 && i < distintas; i++) {
        printf("%dº %s: %d\n", i + 1, v[i]->palavra, v[i]->vezes);
    }

    free(v);
    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
    return 0;
}
