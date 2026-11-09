// 0180 · Pigeonhole e chave composta
// Exercício E1076 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int preco; // em centavos
} Produto;

int compara(const void *a, const void *b) {
    const Produto *x = a;
    const Produto *y = b;
    if (x->preco != y->preco) {
        return x->preco < y->preco ? -1 : 1;
    }
    return strcmp(x->nome, y->nome);
}

int main(void) {
    Produto p[] = {
        {"sabao", 899},  {"arroz", 2590}, {"cafe", 1890}, {"acucar", 899},
        {"feijao", 899}, {"oleo", 790},   {"leite", 590},
    };
    int n = 7;
    qsort(p, (size_t)n, sizeof(Produto), compara);
    for (int i = 0; i < n; i++) {
        printf("%-7s R$ %2d.%02d\n", p[i].nome, p[i].preco / 100, p[i].preco % 100);
    }
    return 0;
}
