// Lista · Módulo 11 · Listas
// Exercício P1104 · ★☆☆ · Quem desistiu da fila do restaurante

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[20];
    struct cliente *prox;
} Cliente;

Cliente *insere_fim(Cliente *inicio, const char *nome) {
    Cliente *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (inicio == NULL) {
        return novo;
    }
    Cliente *p = inicio;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return inicio;
}

void imprime(const char *rotulo, const Cliente *inicio) {
    printf("%s:", rotulo);
    for (const Cliente *p = inicio; p != NULL; p = p->prox) {
        printf(" %s", p->nome);
    }
    printf("\n");
}

void libera(Cliente *inicio) {
    while (inicio != NULL) {
        Cliente *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

Cliente *remove_nome(Cliente *inicio, const char *nome, bool *removeu) {
    Cliente *ant = NULL, *p = inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    *removeu = p != NULL;
    if (p == NULL) {
        return inicio;
    }
    if (ant == NULL) {
        inicio = p->prox; // era o primeiro
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return inicio;
}

int main(void) {
    const char *nomes[4] = {"Ana", "Bia", "Caio", "Duda"};
    Cliente *fila = NULL;
    for (int i = 0; i < 4; i++) {
        fila = insere_fim(fila, nomes[i]);
    }
    imprime("Fila", fila);

    const char *saem[3] = {"Bia", "Ana", "Zeca"};
    for (int i = 0; i < 3; i++) {
        bool removeu;
        fila = remove_nome(fila, saem[i], &removeu);
        char rotulo[40];
        snprintf(rotulo, sizeof rotulo, removeu ? "Sem %s" : "%s não estava", saem[i]);
        imprime(rotulo, fila);
    }
    libera(fila);
    return 0;
}
