// 0102 · Árvores
// Exercício E611 · ★★★
//
// Resposta: (1) "int maior = 0" faz cada folha devolver 1, e a árvore dá 3.
// Começando com -1, a folha devolve 0. (2) libera dava free(n) e depois lia
// n->qtd e n->filhos (uso depois de liberar). O free vai depois do laço.

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

int altura(const No *n) {
    int maior = -1; // folha: -1 + 1 = 0
    for (int i = 0; i < n->qtd; i++) {
        int h = altura(n->filhos[i]);
        if (h > maior) {
            maior = h;
        }
    }
    return maior + 1;
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
    free(n); // só depois de visitar os filhos
}

int main(void) {
    No *vovo = novo("vovo");
    No *mae = adiciona(vovo, "mae");
    adiciona(vovo, "tio");
    adiciona(mae, "voce");
    adiciona(mae, "irma");

    printf("Altura da família: %d\n", altura(vovo));
    libera(vovo);
    return 0;
}
