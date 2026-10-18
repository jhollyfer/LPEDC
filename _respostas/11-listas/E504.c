// 0084 · Lista dupla
// Exercício E504 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct letra {
    char c;
    struct letra *ant;
    struct letra *prox;
} Letra;

// cria a letra c logo depois de "pos" e devolve o nó novo
static Letra *insere_depois(Letra *pos, char c) {
    Letra *novo = malloc(sizeof(Letra));
    if (novo == NULL) exit(1);
    novo->c = c;
    novo->ant = pos;
    novo->prox = pos->prox;
    if (pos->prox != NULL) pos->prox->ant = novo;
    pos->prox = novo;
    return novo;
}

// tira o nó p (nunca a cabeça) e devolve o anterior
static Letra *apaga(Letra *p) {
    Letra *ant = p->ant;
    ant->prox = p->prox;
    if (p->prox != NULL) p->prox->ant = ant;
    free(p);
    return ant;
}

int main(void) {
    Letra cabeca = {'\0', NULL, NULL}; // letra de mentira no começo
    Letra *cursor = &cabeca;           // a letra à esquerda do cursor
    const char *teclas = "progamr#<<r>>a";

    for (int i = 0; teclas[i] != '\0'; i++) {
        char t = teclas[i];
        if (t == '<') {
            if (cursor != &cabeca) cursor = cursor->ant;
        } else if (t == '>') {
            if (cursor->prox != NULL) cursor = cursor->prox;
        } else if (t == '#') {
            if (cursor != &cabeca) cursor = apaga(cursor);
        } else {
            cursor = insere_depois(cursor, t);
        }
    }

    printf("texto: ");
    if (cursor == &cabeca) printf("|");
    for (Letra *p = cabeca.prox; p != NULL; p = p->prox) {
        printf("%c", p->c);
        if (p == cursor) printf("|");
    }
    printf("\n");

    Letra *p = cabeca.prox; // libera (a cabeça mora na pilha)
    while (p != NULL) {
        Letra *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    return 0;
}
