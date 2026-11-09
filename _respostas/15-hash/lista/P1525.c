// Lista · Módulo 15 · Tabelas hash
// Exercício P1525 · ★★★ · Quem joga futebol e vôlei

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 7

typedef struct No {
    char nome[12];
    struct No *prox;
} No;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

bool contem(No *t[], const char *nome) {
    for (No *p = t[djb2(nome) % M]; p != NULL; p = p->prox) {
        if (strcmp(p->nome, nome) == 0) {
            return true;
        }
    }
    return false;
}

void adiciona(No *t[], const char *nome) {
    if (contem(t, nome)) {
        return;
    }
    int b = (int)(djb2(nome) % M);
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->prox = t[b];
    t[b] = novo;
}

void libera(No *t[]) {
    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
}

int main(void) {
    const char *futebol[] = {"Lia", "Rui", "Davi", "Bia", "Caio", "Rui", "Nina"};
    const char *volei[] = {"Bia", "Theo", "Lia", "Gil", "Nina", "Ana"};
    int nf = 7, nv = 6;
    No *tf[M] = {NULL}, *tv[M] = {NULL};

    for (int i = 0; i < nf; i++) {
        adiciona(tf, futebol[i]);
    }
    for (int i = 0; i < nv; i++) {
        adiciona(tv, volei[i]);
    }

    int nos_dois = 0, uniao = 0;
    No *ja[M] = {NULL}; // para não listar repetidos do futebol
    printf("os dois:");
    for (int i = 0; i < nf; i++) {
        if (contem(tv, futebol[i]) && !contem(ja, futebol[i])) {
            printf(" %s", futebol[i]);
            adiciona(ja, futebol[i]);
            nos_dois++;
        }
    }
    printf("\nsó futebol:");
    for (int i = 0; i < nf; i++) {
        if (!contem(tv, futebol[i]) && !contem(ja, futebol[i])) {
            printf(" %s", futebol[i]);
            adiciona(ja, futebol[i]);
        }
    }
    printf("\nsó vôlei:");
    for (int i = 0; i < nv; i++) {
        if (!contem(tf, volei[i])) {
            printf(" %s", volei[i]);
            uniao++;
        }
    }
    for (int b = 0; b < M; b++) {
        for (No *p = tf[b]; p != NULL; p = p->prox) {
            uniao++;
        }
    }
    printf("\nnos dois: %d, total de pessoas: %d\n", nos_dois, uniao);
    libera(tf);
    libera(tv);
    libera(ja);
    return 0;
}
