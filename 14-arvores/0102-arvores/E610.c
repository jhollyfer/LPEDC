// 0102 · Árvores
// Exercício E610 · ★★☆
//
// Cada pasta guarda alguns arquivos (o campo mb, em megabytes). A função
// tamanho soma a pasta com tudo que está dentro dela e imprime uma linha
// para cada pasta, como o comando "du" do Linux.
//
// SEM RODAR, escreva a saída exata do programa. Atenção à ORDEM das linhas:
// em que momento cada printf acontece? Depois rode e confira.
//
// Dicas:
// 1. O printf vem DEPOIS do laço que visita os filhos. Uma pasta só aparece
//    quando todas as subpastas dela já apareceram.
// 2. fotos = 10 + 300 + 120 = 430; a raiz aparece por último.
// 3. Resposta esperada:
//    300 MB  praia
//    120 MB  natal
//    430 MB  fotos
//    5 MB  agua
//    8 MB  luz
//    15 MB  contas
//    450 MB  casa
//
// Escreva sua resposta abaixo (a saída, como comentário):

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
    printf("%d MB  %s\n", total, n->nome);
    return total;
}

int main(void) {
    No *casa = novo("casa", 5);
    No *fotos = adiciona(casa, "fotos", 10);
    No *contas = adiciona(casa, "contas", 2);
    adiciona(fotos, "praia", 300);
    adiciona(fotos, "natal", 120);
    adiciona(contas, "agua", 5);
    adiciona(contas, "luz", 8);

    tamanho(casa);
    libera(casa);
    return 0;
}
