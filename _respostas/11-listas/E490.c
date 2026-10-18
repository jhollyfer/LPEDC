// 0082 · Busca e remoção
// Exercício E490 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct lance {
    char nome[20];
    int valor;
    struct lance *prox;
} Lance;

Lance *lance_insere(Lance *inicio, const char *nome, int valor) {
    Lance *novo = malloc(sizeof(Lance));
    if (novo == NULL) exit(1);
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->valor = valor;
    novo->prox = inicio;
    return novo;
}

void lance_imprime(const Lance *inicio) {
    for (const Lance *p = inicio; p != NULL; p = p->prox) {
        printf("%s R$ %d -> ", p->nome, p->valor);
    }
    printf("NULL\n");
}

void lance_libera(Lance *inicio) {
    while (inicio != NULL) {
        Lance *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

bool remove_menor(Lance **inicio, Lance *saiu) {
    if (*inicio == NULL) return false;
    Lance *menor = *inicio;
    Lance *ant_menor = NULL;
    Lance *ant = *inicio;
    for (Lance *p = (*inicio)->prox; p != NULL; p = p->prox) {
        if (p->valor < menor->valor) {
            menor = p;
            ant_menor = ant;
        }
        ant = p;
    }
    *saiu = *menor; // copia a struct inteira (o prox vem junto, mas não importa)
    if (ant_menor == NULL) *inicio = menor->prox;
    else ant_menor->prox = menor->prox;
    free(menor);
    return true;
}

int main(void) {
    Lance *leilao = NULL;
    leilao = lance_insere(leilao, "Ana", 150);
    leilao = lance_insere(leilao, "Bruno", 90);
    leilao = lance_insere(leilao, "Carla", 210);
    leilao = lance_insere(leilao, "Davi", 175);
    lance_imprime(leilao);

    for (int rodada = 0; rodada < 2; rodada++) {
        Lance saiu;
        if (remove_menor(&leilao, &saiu)) {
            printf("saiu %s (R$ %d)\n", saiu.nome, saiu.valor);
            lance_imprime(leilao);
        }
    }

    lance_libera(leilao);
    return 0;
}
