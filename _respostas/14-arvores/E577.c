// 0097 · Árvores
// Exercício E577 · ★☆☆

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
    int maior = -1;
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
    free(n);
}

// mostra a categoria e, embaixo dela, cada subcategoria um nível adiante
void ficha(const No *n, int prof) {
    printf("%*s%s: prof %d, grau %d", 2 * prof, "", n->nome, prof, n->qtd);
    if (n->qtd == 0) {
        printf(", folha");
    }
    printf("\n");
    for (int i = 0; i < n->qtd; i++) {
        ficha(n->filhos[i], prof + 1);
    }
}

int main(void) {
    No *loja = novo("loja");
    No *eletronicos = adiciona(loja, "eletronicos");
    No *casa = adiciona(loja, "casa");
    adiciona(loja, "moda");
    adiciona(eletronicos, "celulares");
    No *tvs = adiciona(eletronicos, "tvs");
    adiciona(tvs, "oled");
    adiciona(tvs, "led");
    adiciona(casa, "cozinha");

    ficha(loja, 0);
    printf("Altura: %d\n", altura(loja));
    libera(loja);
    return 0;
}
