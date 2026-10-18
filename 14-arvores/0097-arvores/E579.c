// 0097 · Árvores
// Exercício E579 · ★★☆
//
// Escreva a função profundidade_de(raiz, nome), que procura uma pasta pelo
// nome e devolve a profundidade dela (a raiz tem profundidade 0). Se a pasta
// não existir, devolve -1. O main já monta a árvore das pastas do texto
// (casa, fotos, contas, musica, praia, natal, agua, luz, 2025) e testa quatro
// nomes:
//
//   Saída esperada:
//   luz: 2
//   casa: 0
//   2025: 3
//   videos: -1
//
// Dicas:
// 1. Use um parâmetro a mais: uma função auxiliar busca(n, nome, prof) que
//    já sabe a profundidade do nó em que está.
// 2. Se o nome do nó é o procurado (strcmp == 0), devolva prof. Senão, tente
//    cada filho com prof + 1 e devolva a primeira resposta diferente de -1.
// 3. Resposta esperada: luz: 2, casa: 0, 2025: 3, videos: -1.
//
// Escreva sua resposta abaixo (complete profundidade_de):

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

int profundidade_de(const No *raiz, const char *nome) {
    (void)raiz; // apague estas duas linhas quando escrever a função
    (void)nome;
    return -1;
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
