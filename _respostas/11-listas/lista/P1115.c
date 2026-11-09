// Lista · Módulo 11 · Listas
// Exercício P1115 · ★★☆ · Quem lava a louça (Josefo com nomes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[12];
    struct no *prox;
} No;

No *insere_fim(No *ultimo, const char *nome) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    if (ultimo == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    return novo;
}

No *elimina(No *ultimo, int k) {
    No *ant = ultimo;
    printf("Saem:");
    while (ant->prox != ant) {
        for (int i = 1; i < k; i++) {
            ant = ant->prox;
        }
        No *sai = ant->prox;
        printf(" %s", sai->nome);
        ant->prox = sai->prox;
        free(sai);
    }
    printf("\n");
    return ant;
}

int main(void) {
    const char *primos[6] = {"Ana", "Bia", "Caio", "Duda", "Edu", "Fê"};
    No *roda = NULL;
    for (int i = 0; i < 6; i++) {
        roda = insere_fim(roda, primos[i]);
    }
    No *sobrou = elimina(roda, 3);
    printf("Lava a louça: %s\n", sobrou->nome);
    free(sobrou);
    return 0;
}
