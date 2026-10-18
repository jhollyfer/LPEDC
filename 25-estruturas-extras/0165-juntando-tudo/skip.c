// skip.c · implementação do TAD skip list
#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

Skip *skip_cria(unsigned semente) {
    Skip *s = malloc(sizeof(Skip));
    if (s == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    s->cabeca.chave = 0; // não é usada
    s->cabeca.andares = SKIP_MAX;
    for (int k = 0; k < SKIP_MAX; k++) {
        s->cabeca.prox[k] = NULL;
    }
    s->andares = 0;
    s->n = 0;
    s->semente = semente;
    return s;
}

// a moeda: um gerador próprio (congruencial linear), para o sorteio dar o
// mesmo resultado em qualquer máquina; devolve 0 ou 1
static int moeda(Skip *s) {
    s->semente = s->semente * 1103515245u + 12345u;
    return (s->semente >> 16) & 1;
}

bool skip_insere_andares(Skip *s, int chave, int andares) {
    if (andares < 1) {
        andares = 1;
    }
    if (andares > SKIP_MAX) {
        andares = SKIP_MAX;
    }
    // desce como na busca, guardando o último nó visitado em cada andar:
    // é depois dele que o novo nó entra naquele andar
    NoSkip *antes[SKIP_MAX];
    NoSkip *x = &s->cabeca;
    for (int k = SKIP_MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    if (x->prox[0] != NULL && x->prox[0]->chave == chave) {
        return false; // já existe
    }
    NoSkip *novo = malloc(sizeof(NoSkip));
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->chave = chave;
    novo->andares = andares;
    for (int k = 0; k < SKIP_MAX; k++) {
        if (k < andares) { // liga o novo nó em cada andar dele
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        } else {
            novo->prox[k] = NULL;
        }
    }
    if (andares > s->andares) {
        s->andares = andares;
    }
    s->n++;
    return true;
}

bool skip_insere(Skip *s, int chave) {
    int andares = 1;
    while (andares < SKIP_MAX && moeda(s) == 1) { // cara: sobe mais um andar
        andares++;
    }
    return skip_insere_andares(s, chave, andares);
}

bool skip_busca(const Skip *s, int chave, int *passos) {
    int olhados = 0;
    const NoSkip *x = &s->cabeca;
    for (int k = s->andares - 1; k >= 0; k--) { // do andar mais alto ao 0
        while (x->prox[k] != NULL) {
            olhados++;
            if (x->prox[k]->chave >= chave) {
                break; // o próximo já passou (ou é a chave): desce
            }
            x = x->prox[k]; // o próximo ainda é menor: avança
        }
    }
    if (passos != NULL) {
        *passos = olhados;
    }
    x = x->prox[0]; // no andar 0, o próximo é a chave ou ela não existe
    return x != NULL && x->chave == chave;
}

bool skip_remove(Skip *s, int chave) {
    NoSkip *antes[SKIP_MAX];
    NoSkip *x = &s->cabeca;
    for (int k = SKIP_MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    x = x->prox[0];
    if (x == NULL || x->chave != chave) {
        return false;
    }
    for (int k = 0; k < x->andares; k++) { // desliga o nó em TODOS os andares dele
        antes[k]->prox[k] = x->prox[k];
    }
    free(x);
    while (s->andares > 0 && s->cabeca.prox[s->andares - 1] == NULL) {
        s->andares--; // o andar de cima ficou vazio
    }
    s->n--;
    return true;
}

void skip_mostra(const Skip *s) {
    for (int k = s->andares - 1; k >= 0; k--) {
        printf("andar %d:", k);
        // anda no andar 0 para cada chave ficar sempre na mesma coluna; os
        // brancos só são impressos antes de uma chave (nada sobra no fim)
        int brancos = 0;
        for (const NoSkip *x = s->cabeca.prox[0]; x != NULL; x = x->prox[0]) {
            if (x->andares > k) {
                printf("%*s%4d", brancos, "", x->chave);
                brancos = 0;
            } else {
                brancos += 4;
            }
        }
        printf("\n");
    }
}

void skip_libera(Skip *s) {
    NoSkip *x = s->cabeca.prox[0]; // o andar 0 tem todo mundo
    while (x != NULL) {
        NoSkip *prox = x->prox[0];
        free(x);
        x = prox;
    }
    free(s);
}
