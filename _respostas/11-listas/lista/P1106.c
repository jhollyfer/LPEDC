// Lista · Módulo 11 · Listas
// Exercício P1106 · ★☆☆ · O metrô nos dois sentidos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estacao {
    char nome[24];
    struct estacao *ant, *prox;
} Estacao;

typedef struct {
    Estacao *inicio, *fim;
} Linha;

void insere_fim(Linha *l, const char *nome) {
    Estacao *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->ant = l->fim;
    novo->prox = NULL;
    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo;
    }
    l->fim = novo;
}

void ida(const Linha *l) {
    printf("Ida:  ");
    for (const Estacao *p = l->inicio; p != NULL; p = p->prox) {
        printf(p == l->inicio ? " %s" : " -> %s", p->nome);
    }
    printf("\n");
}

void volta(const Linha *l) {
    printf("Volta:");
    for (const Estacao *p = l->fim; p != NULL; p = p->ant) {
        printf(p == l->fim ? " %s" : " -> %s", p->nome);
    }
    printf("\n");
}

void libera(Linha *l) {
    Estacao *p = l->inicio;
    while (p != NULL) {
        Estacao *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    l->inicio = l->fim = NULL;
}

int main(void) {
    Linha vermelha = {NULL, NULL};
    insere_fim(&vermelha, "Sé");
    insere_fim(&vermelha, "Luz");
    insere_fim(&vermelha, "Tiradentes");
    insere_fim(&vermelha, "Armênia");
    ida(&vermelha);
    volta(&vermelha);
    libera(&vermelha);
    return 0;
}
