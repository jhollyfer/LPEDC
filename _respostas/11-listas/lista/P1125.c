// Lista · Módulo 11 · Listas
// Exercício P1125 · ★★★ · A lista dupla com três setas esquecidas

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant, *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Dupla;

No *cria_no(int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->ant = novo->prox = NULL;
    return novo;
}

void insere_inicio(Dupla *l, int valor) {
    No *novo = cria_no(valor);
    novo->prox = l->inicio;
    if (l->inicio == NULL) {
        l->fim = novo;
    } else {
        l->inicio->ant = novo; // o antigo primeiro olha para o novo
    }
    l->inicio = novo;
}

void insere_fim(Dupla *l, int valor) {
    No *novo = cria_no(valor);
    novo->ant = l->fim;
    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo;
    }
    l->fim = novo;
}

void remove_valor(Dupla *l, int valor) {
    No *p = l->inicio;
    while (p != NULL && p->valor != valor) {
        p = p->prox;
    }
    if (p == NULL) {
        return;
    }
    if (p->ant != NULL) {
        p->ant->prox = p->prox;
    } else {
        l->inicio = p->prox;
    }
    if (p->prox != NULL) {
        p->prox->ant = p->ant; // vale também quando p é o primeiro (fica NULL)
    } else {
        l->fim = p->ant; // p era o último
    }
    free(p);
}

void mostra(const Dupla *l) {
    printf("Ida:  ");
    for (const No *p = l->inicio; p != NULL; p = p->prox) {
        printf(" %d", p->valor);
    }
    printf("\nVolta:");
    for (const No *p = l->fim; p != NULL; p = p->ant) {
        printf(" %d", p->valor);
    }
    printf("\n");
}

void libera(Dupla *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    l->inicio = l->fim = NULL;
}

int main(void) {
    Dupla l = {NULL, NULL};
    insere_inicio(&l, 3);
    insere_inicio(&l, 2);
    insere_inicio(&l, 1);
    insere_fim(&l, 4);
    mostra(&l);
    remove_valor(&l, 4);
    remove_valor(&l, 1);
    printf("Depois de remover 4 e 1:\n");
    mostra(&l);
    libera(&l);
    return 0;
}
