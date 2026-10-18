// 0097 · Árvores
// Exercício E578 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->nome, nome);
    n->qtd = 0;
    return n;
}

No *adiciona(No *pai, const char *nome) {
    No *filho = novo(nome);
    pai->filhos[pai->qtd++] = filho;
    return filho;
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
    free(n);
}

int conta_nos(const No *n) {
    int total = 1; // o próprio nó
    for (int i = 0; i < n->qtd; i++) {
        total += conta_nos(n->filhos[i]);
    }
    return total;
}

int main(void) {
    No *diretora = novo("diretora");
    No *coord = adiciona(diretora, "coordenador");
    adiciona(coord, "prof. ana");
    adiciona(coord, "prof. bruno");
    adiciona(diretora, "secretaria");

    printf("Pessoas na escola: %d\n", conta_nos(diretora));
    libera(diretora);
    return 0;
}
