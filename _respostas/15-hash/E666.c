// 0111 · Encadeamento
// Exercício E666 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int chave;
    struct No *prox;
} No;

typedef struct {
    int m;
    int n;
    No **baldes;
} Tabela;

// troca o vetor de baldes por um maior e muda cada nó de lugar,
// sem nenhum malloc de nó novo
bool cresce(Tabela *t) {
    int novo_m = 2 * t->m + 1;
    No **novos = calloc((size_t)novo_m, sizeof *novos);
    if (novos == NULL) {
        return false;
    }
    for (int b = 0; b < t->m; b++) {
        No *p = t->baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            int i = p->chave % novo_m; // o balde muda junto com o m
            p->prox = novos[i];
            novos[i] = p;
            p = prox;
        }
    }
    free(t->baldes);
    t->baldes = novos;
    t->m = novo_m;
    printf("cresceu: m = %d\n", novo_m);
    return true;
}

bool insere(Tabela *t, int chave) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    int i = chave % t->m;
    novo->chave = chave;
    novo->prox = t->baldes[i];
    t->baldes[i] = novo;
    t->n++;
    if (t->n > t->m) { // fator de carga passou de 1
        return cresce(t);
    }
    return true;
}

void mostra(const Tabela *t) {
    for (int b = 0; b < t->m; b++) {
        printf("[%d]", b);
        for (No *p = t->baldes[b]; p != NULL; p = p->prox) {
            printf(" %d", p->chave);
        }
        printf("\n");
    }
}

void libera(Tabela *t) {
    for (int b = 0; b < t->m; b++) {
        No *p = t->baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(t->baldes);
}

int main(void) {
    Tabela t = {2, 0, calloc(2, sizeof(No *))};
    if (t.baldes == NULL) {
        return 1;
    }
    int chaves[] = {14, 5, 23, 8, 19, 40, 12, 31, 21, 2};
    for (int i = 0; i < 10; i++) {
        if (!insere(&t, chaves[i])) {
            break;
        }
    }
    printf("n = %d, m = %d\n", t.n, t.m);
    mostra(&t);
    libera(&t);
    return 0;
}
