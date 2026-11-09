// Lista · Módulo 11 · Listas
// Exercício P1114 · ★★☆ · Os contatos que vêm para a frente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[16];
    struct contato *ant, *prox;
} Contato;

typedef struct {
    Contato *inicio, *fim;
} Agenda;

void insere_fim(Agenda *ag, const char *nome) {
    Contato *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    novo->ant = ag->fim;
    if (ag->fim != NULL) {
        ag->fim->prox = novo;
    } else {
        ag->inicio = novo;
    }
    ag->fim = novo;
}

int busca_move(Agenda *ag, const char *nome) {
    int comp = 0;
    Contato *p = ag->inicio;
    while (p != NULL) {
        comp++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        p = p->prox;
    }
    if (p == NULL || p == ag->inicio) {
        return comp;
    }
    // desliga p de onde está (p não é o primeiro, então p->ant existe)
    p->ant->prox = p->prox;
    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    } else {
        ag->fim = p->ant;
    }
    // e liga no início
    p->ant = NULL;
    p->prox = ag->inicio;
    ag->inicio->ant = p;
    ag->inicio = p;
    return comp;
}

void mostra(const Agenda *ag) {
    for (const Contato *p = ag->inicio; p != NULL; p = p->prox) {
        printf(p == ag->inicio ? "%s" : " %s", p->nome);
    }
    printf("\n");
}

void libera(Agenda *ag) {
    Contato *p = ag->inicio;
    while (p != NULL) {
        Contato *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    ag->inicio = ag->fim = NULL;
}

int main(void) {
    const char *nomes[5] = {"Ana", "Bia", "Caio", "Duda", "Edu"};
    const char *buscas[5] = {"Duda", "Duda", "Edu", "Duda", "Ana"};
    Agenda ag = {NULL, NULL};
    for (int i = 0; i < 5; i++) {
        insere_fim(&ag, nomes[i]);
    }
    int total = 0, sem_mover = 0;
    for (int b = 0; b < 5; b++) {
        int c = busca_move(&ag, buscas[b]);
        total += c;
        printf("%s: %d comparações | ", buscas[b], c);
        mostra(&ag);
        for (int i = 0; i < 5; i++) { // a posição na ordem original
            if (strcmp(nomes[i], buscas[b]) == 0) {
                sem_mover += i + 1;
            }
        }
    }
    printf("Total movendo: %d\n", total);
    printf("Total sem mover: %d\n", sem_mover);
    libera(&ag);
    return 0;
}
