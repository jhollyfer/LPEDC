// Lista · Módulo 25 · Estruturas especiais
// Exercício P2529 · ★★★ · A agenda do consultório

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct No {
    int chave; // minutos desde 0h
    int andares;
    struct No *prox[MAX];
} No;

No cabeca;
unsigned semente = 11;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

// desce e guarda em antes[k] o último nó com chave < h em cada andar
No *desce(int h, No *antes[]) {
    No *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < h) x = x->prox[k];
        if (antes != NULL) antes[k] = x;
    }
    return x;
}

bool marca(int h) {
    No *antes[MAX];
    No *x = desce(h, antes);
    if (x->prox[0] != NULL && x->prox[0]->chave == h) return false;
    int andares = 1;
    while (andares < MAX && moeda() == 1) andares++;
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->chave = h;
    novo->andares = andares;
    for (int k = 0; k < MAX; k++) {
        novo->prox[k] = NULL;
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        }
    }
    return true;
}

bool desmarca(int h) {
    No *antes[MAX];
    No *x = desce(h, antes)->prox[0];
    if (x == NULL || x->chave != h) return false;
    for (int k = 0; k < x->andares; k++) antes[k]->prox[k] = x->prox[k];
    free(x);
    return true;
}

int proximo(int h) { // menor horário >= h, ou -1
    No *x = desce(h, NULL)->prox[0];
    return x == NULL ? -1 : x->chave;
}

int anterior(int h) { // maior horário < h, ou -1
    No *x = desce(h, NULL);
    return x == &cabeca ? -1 : x->chave;
}

void hora(int m) {
    if (m < 0) printf("nenhum");
    else printf("%02d:%02d", m / 60, m % 60);
}

int main(void) {
    int horarios[] = {9 * 60, 14 * 60 + 30, 8 * 60, 10 * 60 + 15, 16 * 60, 11 * 60, 13 * 60};
    for (int k = 0; k < 7; k++) marca(horarios[k]);
    printf("marca 10:15 de novo: %s\n", marca(10 * 60 + 15) ? "marcado" : "já ocupado");
    printf("desmarca 11:00: %s\n", desmarca(11 * 60) ? "ok" : "não havia");
    printf("desmarca 12:00: %s\n", desmarca(12 * 60) ? "ok" : "não havia");

    int perguntas[] = {7 * 60, 10 * 60 + 15, 10 * 60 + 16, 12 * 60, 17 * 60};
    for (int k = 0; k < 5; k++) {
        hora(perguntas[k]);
        printf(" -> anterior ");
        hora(anterior(perguntas[k]));
        printf(", próximo ");
        hora(proximo(perguntas[k]));
        printf("\n");
    }
    printf("Agenda:");
    for (No *x = cabeca.prox[0]; x != NULL; x = x->prox[0]) {
        printf(" ");
        hora(x->chave);
    }
    printf("\n");
    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
