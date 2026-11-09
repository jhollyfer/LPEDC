// Lista · Módulo 11 · Listas
// Exercício P1109 · ★☆☆ · A chamada em ordem alfabética

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[20];
    struct aluno *prox;
} Aluno;

Aluno *insere_ordenado(Aluno *inicio, const char *nome) {
    Aluno *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    if (inicio == NULL || strcmp(nome, inicio->nome) < 0) {
        novo->prox = inicio;
        return novo;
    }
    Aluno *p = inicio;
    while (p->prox != NULL && strcmp(p->prox->nome, nome) < 0) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return inicio;
}

void imprime(const Aluno *inicio) {
    for (const Aluno *p = inicio; p != NULL; p = p->prox) {
        printf(p == inicio ? "%s" : " %s", p->nome);
    }
    printf("\n");
}

void libera(Aluno *inicio) {
    while (inicio != NULL) {
        Aluno *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

int main(void) {
    const char *chegada[5] = {"Marcos", "Ana", "Teo", "Bia", "Lia"};
    Aluno *chamada = NULL;
    for (int i = 0; i < 5; i++) {
        chamada = insere_ordenado(chamada, chegada[i]);
        imprime(chamada);
    }
    libera(chamada);
    return 0;
}
