// 0181 · Juntando tudo
// Exercício E1085 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    char nome[16];
    int idade;
    struct Pessoa *ant, *prox;
} Pessoa;

typedef struct {
    Pessoa nil;
} Fila;

void insere_apos(Pessoa *y, const char *nome, int idade) {
    Pessoa *x = malloc(sizeof(Pessoa));
    if (x == NULL) {
        exit(1);
    }
    snprintf(x->nome, sizeof x->nome, "%s", nome);
    x->idade = idade;
    x->prox = y->prox;
    x->ant = y;
    y->prox->ant = x;
    y->prox = x;
}

void entra(Fila *f, const char *nome, int idade) {
    if (idade >= 60) {
        Pessoa *p = &f->nil; // anda até o último idoso (ou fica na sentinela)
        while (p->prox != &f->nil && p->prox->idade >= 60) {
            p = p->prox;
        }
        insere_apos(p, nome, idade);
    } else {
        insere_apos(f->nil.ant, nome, idade); // no fim
    }
}

void mostra(const Fila *f) {
    for (const Pessoa *x = f->nil.prox; x != &f->nil; x = x->prox) {
        printf("%s%s%s", x == f->nil.prox ? "" : " ", x->nome, x->idade >= 60 ? "*" : "");
    }
    printf("\n");
}

void libera(Fila *f) {
    Pessoa *x = f->nil.prox;
    while (x != &f->nil) {
        Pessoa *seguinte = x->prox;
        free(x);
        x = seguinte;
    }
}

int main(void) {
    Fila f;
    f.nil.prox = f.nil.ant = &f.nil;
    f.nil.idade = 0; // a sentinela nunca conta como idosa
    const char *nomes[] = {"Ana", "Beto", "Caio", "Dora", "Enzo", "Fabi"};
    int idades[] = {35, 70, 22, 65, 81, 40};
    for (int i = 0; i < 6; i++) {
        entra(&f, nomes[i], idades[i]);
        mostra(&f);
    }
    libera(&f);
    return 0;
}
