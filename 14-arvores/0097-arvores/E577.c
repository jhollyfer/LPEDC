// 0097 · Árvores
// Exercício E577 · ★☆☆
//
// O site de uma loja organiza os produtos em categorias, e o main já monta
// esta árvore:
//
//   loja
//   ├── eletronicos
//   │   ├── celulares
//   │   └── tvs
//   │       ├── oled
//   │       └── led
//   ├── casa
//   │   └── cozinha
//   └── moda
//
// Complete a função ficha, que imprime uma linha por categoria, recuada 2
// espaços por nível, com a profundidade, o grau e a palavra "folha" quando o
// nó não tem filhos. Depois o main imprime a altura da árvore (a função
// altura já está pronta):
//
//   Saída esperada:
//   loja: prof 0, grau 3
//     eletronicos: prof 1, grau 2
//       celulares: prof 2, grau 0, folha
//       tvs: prof 2, grau 2
//         oled: prof 3, grau 0, folha
//         led: prof 3, grau 0, folha
//     casa: prof 1, grau 1
//       cozinha: prof 2, grau 0, folha
//     moda: prof 1, grau 0, folha
//   Altura: 3
//
// Dicas:
// 1. O grau de um nó é o próprio n->qtd. Folha é quem tem qtd == 0.
// 2. Imprima o nó e depois chame ficha para cada filho com prof + 1. O recuo
//    sai com printf("%*s", 2 * prof, "").
// 3. Resposta esperada: as 9 linhas acima e "Altura: 3".
//
// Escreva sua resposta abaixo (complete ficha):

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

void ficha(const No *n, int prof) {
    (void)n; // apague estas duas linhas quando escrever a função
    (void)prof;
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
