// Lista · Módulo 12 · Pilhas e filas
// Exercício P1226 · ★★★ · A triagem do pronto-socorro

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
    char nome[12];
    int cor; // 1 vermelho ... 5 azul
    struct paciente *prox;
} Paciente;

typedef struct {
    Paciente *inicio;
} Triagem;

const char *NOME_COR[5] = {"vermelho", "laranja", "amarelo", "verde", "azul"};

void chega(Triagem *t, const char *nome, int cor) {
    Paciente *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->cor = cor;
    if (t->inicio == NULL || cor < t->inicio->cor) {
        novo->prox = t->inicio;
        t->inicio = novo;
        return;
    }
    Paciente *p = t->inicio;
    while (p->prox != NULL && p->prox->cor <= cor) { // empate: depois dos que já estavam
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
}

bool atende(Triagem *t, char *nome, int *cor) {
    if (t->inicio == NULL) {
        return false;
    }
    Paciente *p = t->inicio;
    strcpy(nome, p->nome);
    *cor = p->cor;
    t->inicio = p->prox;
    free(p);
    return true;
}

void mostra(const Triagem *t) {
    printf("fila:");
    for (const Paciente *p = t->inicio; p != NULL; p = p->prox) {
        printf(" %s(%s)", p->nome, NOME_COR[p->cor - 1]);
    }
    printf("\n");
}

void atende_mostra(Triagem *t) {
    char nome[12];
    int cor;
    if (atende(t, nome, &cor)) {
        printf("atende %s (%s)\n", nome, NOME_COR[cor - 1]);
    }
}

int main(void) {
    Triagem t = {NULL};
    chega(&t, "Ana", 4);
    chega(&t, "Beto", 3);
    chega(&t, "Caio", 1);
    chega(&t, "Duda", 4);
    mostra(&t);
    atende_mostra(&t);
    atende_mostra(&t);
    chega(&t, "Edu", 2);
    chega(&t, "Fabi", 5);
    chega(&t, "Gil", 3);
    mostra(&t);
    while (t.inicio != NULL) {
        atende_mostra(&t);
    }
    return 0;
}
