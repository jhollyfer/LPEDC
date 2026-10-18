// 0097 · Árvores
// Exercício E579 · ★★☆

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

// prof é a profundidade do nó n, que a chamada de cima já sabe
int busca(const No *n, const char *nome, int prof) {
    if (strcmp(n->nome, nome) == 0) {
        return prof;
    }
    for (int i = 0; i < n->qtd; i++) {
        int achou = busca(n->filhos[i], nome, prof + 1);
        if (achou != -1) {
            return achou;
        }
    }
    return -1;
}

int profundidade_de(const No *raiz, const char *nome) {
    return busca(raiz, nome, 0);
}

int main(void) {
    No *casa = novo("casa");
    No *fotos = adiciona(casa, "fotos");
    No *contas = adiciona(casa, "contas");
    adiciona(casa, "musica");
    adiciona(fotos, "praia");
    adiciona(fotos, "natal");
    adiciona(contas, "agua");
    No *luz = adiciona(contas, "luz");
    adiciona(luz, "2025");

    const char *testes[] = {"luz", "casa", "2025", "videos"};
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", testes[i], profundidade_de(casa, testes[i]));
    }
    libera(casa);
    return 0;
}
