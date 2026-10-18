// 0097 · Árvores
// Exercício E580 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    int mb; // arquivos soltos dentro desta pasta
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

No *novo(const char *nome, int mb) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->nome, nome);
    n->mb = mb;
    n->qtd = 0;
    return n;
}

No *adiciona(No *pai, const char *nome, int mb) {
    No *filho = novo(nome, mb);
    pai->filhos[pai->qtd++] = filho;
    return filho;
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
    free(n);
}

int tamanho(const No *n) {
    int total = n->mb;
    for (int i = 0; i < n->qtd; i++) {
        total += tamanho(n->filhos[i]);
    }
    return total;
}

// filhos primeiro, depois a pasta: cada total já chega somado
int du(const No *n) {
    int total = n->mb;
    for (int i = 0; i < n->qtd; i++) {
        total += du(n->filhos[i]);
    }
    printf("%d MB  %s\n", total, n->nome);
    return total;
}

// a pasta primeiro: precisa pedir o total antes de descer
void arvore(const No *n, int prof) {
    printf("%*s%s (%d MB)\n", 2 * prof, "", n->nome, tamanho(n));
    for (int i = 0; i < n->qtd; i++) {
        arvore(n->filhos[i], prof + 1);
    }
}

int main(void) {
    No *casa = novo("casa", 5);
    No *fotos = adiciona(casa, "fotos", 10);
    No *contas = adiciona(casa, "contas", 2);
    adiciona(fotos, "praia", 300);
    adiciona(fotos, "natal", 120);
    adiciona(contas, "agua", 5);
    adiciona(contas, "luz", 8);

    printf("-- du --\n");
    du(casa);
    printf("-- arvore --\n");
    arvore(casa, 0);
    libera(casa);
    return 0;
}
