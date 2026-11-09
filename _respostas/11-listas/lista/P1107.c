// Lista · Módulo 11 · Listas
// Exercício P1107 · ★☆☆ · A roda-gigante do parque

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int cabine;
    int pessoas;
    struct no *prox;
} No;

No *insere_fim(No *ultimo, int cabine, int pessoas) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->cabine = cabine;
    novo->pessoas = pessoas;
    if (ultimo == NULL) {
        novo->prox = novo; // sozinho, aponta para si
    } else {
        novo->prox = ultimo->prox; // o novo aponta para o primeiro
        ultimo->prox = novo;
    }
    return novo;
}

int total_pessoas(const No *ultimo) {
    if (ultimo == NULL) {
        return 0;
    }
    int total = 0;
    const No *p = ultimo->prox;
    do {
        total += p->pessoas;
        p = p->prox;
    } while (p != ultimo->prox);
    return total;
}

void mostra_a_partir(const No *ultimo, int cabine) {
    if (ultimo == NULL) {
        return;
    }
    const No *comeco = ultimo->prox;
    while (comeco->cabine != cabine && comeco != ultimo) {
        comeco = comeco->prox;
    }
    printf("A partir da %d:", cabine);
    const No *p = comeco;
    do {
        printf(" [%d:%d]", p->cabine, p->pessoas);
        p = p->prox;
    } while (p != comeco);
    printf("\n");
}

void libera(No *ultimo) {
    if (ultimo == NULL) {
        return;
    }
    No *p = ultimo->prox;
    ultimo->prox = NULL; // quebra o círculo
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {
    int pessoas[6] = {2, 4, 0, 3, 1, 4};
    No *roda = NULL;
    for (int i = 0; i < 6; i++) {
        roda = insere_fim(roda, i + 1, pessoas[i]);
    }
    printf("Total: %d pessoas\n", total_pessoas(roda));
    mostra_a_partir(roda, 4);
    libera(roda);
    return 0;
}
