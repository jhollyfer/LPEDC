// 0102 · Árvores
// Exercício E608 · ★☆☆
//
// Complete a função conta_nos, que devolve quantos nós a árvore tem (a raiz
// conta). O main monta o organograma de uma escola:
//
//   diretora
//   ├── coordenador
//   │   ├── prof. ana
//   │   └── prof. bruno
//   └── secretaria
//
//   Saída esperada:
//   Pessoas na escola: 5
//
// Dicas:
// 1. Pense recursivo: o nó vale 1, mais os nós de cada filho.
// 2. Folha não entra no laço e devolve só o 1 dela.
// 3. Resposta esperada: Pessoas na escola: 5
//
// Escreva sua resposta abaixo (complete conta_nos):

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
    (void)n; // apague esta linha quando escrever a função
    return 0;
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
