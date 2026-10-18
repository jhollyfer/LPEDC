// 0081 · Juntando tudo
// Exercício E484 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct participante {
    char nome[20];
    int pontos;
    struct participante *prox;
} Participante;

static bool vem_antes(const Participante *a, const Participante *b) {
    if (a->pontos != b->pontos) return a->pontos > b->pontos;
    return strcmp(a->nome, b->nome) < 0;
}

static Participante *insere(Participante *inicio, const char *nome, int pontos) {
    Participante *novo = malloc(sizeof(Participante));
    if (novo == NULL) exit(1);
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->pontos = pontos;
    Participante *ant = NULL;
    Participante *p = inicio;
    while (p != NULL && vem_antes(p, novo)) {
        ant = p;
        p = p->prox;
    }
    novo->prox = p;
    if (ant == NULL) return novo;
    ant->prox = novo;
    return inicio;
}

static bool remove_nome(Participante **inicio, const char *nome) {
    Participante *ant = NULL;
    Participante *p = *inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false;
    if (ant == NULL) *inicio = p->prox;
    else ant->prox = p->prox;
    free(p);
    return true;
}

static void imprime(const Participante *inicio) {
    int pos = 1;
    for (const Participante *p = inicio; p != NULL; p = p->prox) {
        printf("%d. %s %d\n", pos++, p->nome, p->pontos);
    }
}

int main(void) {
    Participante *bolao = NULL;
    bolao = insere(bolao, "Ana", 12);
    bolao = insere(bolao, "Beto", 15);
    bolao = insere(bolao, "Cris", 12);
    bolao = insere(bolao, "Duda", 9);
    bolao = insere(bolao, "Edu", 15);
    imprime(bolao);

    if (remove_nome(&bolao, "Cris")) printf("Cris saiu do bolão\n");
    imprime(bolao);

    while (bolao != NULL) {
        Participante *seguinte = bolao->prox;
        free(bolao);
        bolao = seguinte;
    }
    return 0;
}
