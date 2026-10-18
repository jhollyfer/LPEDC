// 0102 · Árvores
// Exercício E612 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4
#define MAX_PROF 10

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

// trilha[0..prof-1] já tem o caminho da raiz até o pai de n
int caminhos(const No *n, const char *trilha[], int prof) {
    trilha[prof] = n->nome;
    if (n->qtd == 0) {
        for (int i = 0; i <= prof; i++) {
            printf("%s%s", trilha[i], i < prof ? "/" : "\n");
        }
        return 1;
    }
    int total = 0;
    for (int i = 0; i < n->qtd; i++) {
        total += caminhos(n->filhos[i], trilha, prof + 1);
    }
    return total;
}

int main(void) {
    No *app = novo("app");
    No *lanches = adiciona(app, "lanches");
    No *bebidas = adiciona(app, "bebidas");
    adiciona(lanches, "x-salada");
    adiciona(lanches, "x-bacon");
    adiciona(bebidas, "suco");
    No *refri = adiciona(bebidas, "refri");
    adiciona(refri, "lata");
    adiciona(refri, "2 litros");

    const char *trilha[MAX_PROF];
    int total = caminhos(app, trilha, 0);
    printf("Total de caminhos: %d\n", total);

    libera(app);
    return 0;
}
