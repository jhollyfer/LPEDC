// 0097 · Árvores
// Exercício E579 · ★★☆
//
// As pastas de um computador formam esta árvore:
//
//   casa
//   ├── fotos
//   │   ├── praia
//   │   └── natal
//   ├── contas
//   │   ├── agua
//   │   └── luz
//   │       └── 2025
//   └── musica
//
// Escreva profundidade_de(raiz, nome), que procura uma pasta pelo nome e
// devolve a profundidade dela (a raiz tem profundidade 0), ou -1 se a pasta
// não existir. Monte a árvore no main e teste luz, casa, 2025 e videos.
//
//   Saída esperada:
//   luz: 2
//   casa: 0
//   2025: 3
//   videos: -1
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

int main(void) {

    return 0;
}
