// 0144 · Árvores gerais
// Exercício E864 · ★★★

#include <stdio.h>
#include "arvgen.h"

int main(void) {
    char linha[100], pai[20], nome[20];
    int valor;
    NoG *raiz = NULL;

    while (fgets(linha, sizeof linha, stdin) != NULL) {
        if (sscanf(linha, "%19s %19s %d", pai, nome, &valor) != 3) {
            continue;
        }
        if (raiz == NULL) {
            raiz = ag_cria(nome, valor); // a primeira linha é a raiz
            continue;
        }
        NoG *p = ag_busca(raiz, pai);
        if (p == NULL) {
            printf("pai %s não existe: linha ignorada\n", pai);
        } else {
            ag_adiciona(p, nome, valor);
        }
    }

    if (raiz == NULL) {
        printf("Árvore vazia\n");
        return 0;
    }
    ag_mostra(raiz);
    printf("Itens: %d | altura: %d\n", ag_conta(raiz), ag_altura(raiz));

    const NoG *maior = NULL;
    for (const NoG *f = raiz->filho; f != NULL; f = f->irmao) {
        if (maior == NULL || ag_total(f) > ag_total(maior)) {
            maior = f;
        }
    }
    if (maior != NULL) {
        printf("Maior gasto: %s (R$ %d)\n", maior->nome, ag_total(maior));
    }

    ag_libera(raiz);
    return 0;
}
