// Lista · Módulo 11 · Listas
// Exercício P1119 · ★★☆ · O ranking da corrida em lista dupla

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int tempo;
    struct no *ant, *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Ranking;

void insere_ordenado(Ranking *r, int tempo) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->tempo = tempo;
    No *p = r->inicio;
    while (p != NULL && p->tempo <= tempo) {
        p = p->prox;
    }
    // o novo entra antes de p (p == NULL: entra no fim)
    novo->prox = p;
    novo->ant = p != NULL ? p->ant : r->fim;
    if (novo->ant != NULL) {
        novo->ant->prox = novo;
    } else {
        r->inicio = novo;
    }
    if (p != NULL) {
        p->ant = novo;
    } else {
        r->fim = novo;
    }
}

void mostra(const Ranking *r) {
    for (const No *p = r->inicio; p != NULL; p = p->prox) {
        printf(p == r->inicio ? "%d" : " %d", p->tempo);
    }
    printf("\n");
}

void libera(Ranking *r) {
    No *p = r->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    r->inicio = r->fim = NULL;
}

int main(void) {
    int tempos[5] = {58, 61, 55, 70, 60};
    Ranking r = {NULL, NULL};
    for (int i = 0; i < 5; i++) {
        insere_ordenado(&r, tempos[i]);
        mostra(&r);
    }
    printf("De trás para frente:");
    for (const No *p = r.fim; p != NULL; p = p->ant) {
        printf(" %d", p->tempo);
    }
    printf("\n");
    libera(&r);
    return 0;
}
