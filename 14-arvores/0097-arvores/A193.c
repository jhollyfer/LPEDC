// A193 · Os mesmos nós, alturas diferentes

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

int conta_folhas(const No *n) {
    if (n->qtd == 0) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i < n->qtd; i++) {
        total += conta_folhas(n->filhos[i]);
    }
    return total;
}

int altura(const No *n) {
    int maior = -1;
    for (int i = 0; i < n->qtd; i++) {
        int h = altura(n->filhos[i]);
        if (h > maior) {
            maior = h;
        }
    }
    return maior + 1;
}

// o maior grau da árvore: compara o nó com o maior grau de cada filho
int maior_grau(const No *n) {
    int maior = n->qtd;
    for (int i = 0; i < n->qtd; i++) {
        int g = maior_grau(n->filhos[i]);
        if (g > maior) {
            maior = g;
        }
    }
    return maior;
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
    free(n);
}

void resumo(const char *titulo, const No *raiz) {
    printf("%-10s folhas %d, altura %d, maior grau %d\n", titulo,
           conta_folhas(raiz), altura(raiz), maior_grau(raiz));
}

int main(void) {
    // larga: o grupo da família, todo mundo direto embaixo do admin
    No *grupo = novo("admin");
    adiciona(grupo, "mae");
    adiciona(grupo, "pai");
    adiciona(grupo, "tia");
    adiciona(grupo, "primo");

    // funda: o sumário de um livro, cada item dentro do anterior
    No *livro = novo("livro");
    No *p = adiciona(livro, "cap 1");
    p = adiciona(p, "secao 1.1");
    p = adiciona(p, "item 1.1.1");
    adiciona(p, "nota");

    // caso de borda: um nó sozinho já é uma árvore (e é raiz e folha)
    No *sozinho = novo("rascunho");

    resumo("larga:", grupo);     // 5 nós
    resumo("funda:", livro);     // 5 nós
    resumo("sozinho:", sozinho); // 1 nó

    libera(grupo);
    libera(livro);
    libera(sozinho);
    return 0;
}
// Saída:
// larga:     folhas 4, altura 1, maior grau 4
// funda:     folhas 1, altura 4, maior grau 1
// sozinho:   folhas 1, altura 0, maior grau 0
