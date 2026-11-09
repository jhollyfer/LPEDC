// Lista · Módulo 08 · Tipos compostos
// Exercício P0821 · ★★★ · O catálogo ordenado por três chaves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { CELULAR, NOTEBOOK, FONE } Categoria;

typedef struct {
    char nome[24];
    Categoria cat;
    double preco;
    int estoque;
} Produto;

int compara(const void *pa, const void *pb) {
    const Produto *a = pa, *b = pb;
    if (a->cat != b->cat) {
        return (int) a->cat - (int) b->cat;           // 1º: categoria
    }
    if (a->preco != b->preco) {
        return (a->preco > b->preco) - (a->preco < b->preco); // 2º: preço
    }
    return strcmp(a->nome, b->nome);                  // 3º: nome
}

int main(void) {
    Produto v[9] = {
        {"Notebook Ultra 14", NOTEBOOK, 4299.00, 3},
        {"Fone Bluetooth X", FONE, 199.90, 25},
        {"Celular Mega 5G", CELULAR, 1899.00, 10},
        {"Fone com fio", FONE, 39.90, 60},
        {"Celular Lite", CELULAR, 999.00, 18},
        {"Notebook Basic", NOTEBOOK, 2499.00, 7},
        {"Celular Alfa", CELULAR, 1899.00, 4},
        {"Fone Gamer", FONE, 199.90, 12},
        {"Notebook Pro 16", NOTEBOOK, 8999.00, 1},
    };
    const char *nome_cat[3] = {"Celulares", "Notebooks", "Fones"};
    int n = 9;

    qsort(v, n, sizeof v[0], compara);
    double grupo = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i].cat != v[i - 1].cat) {
            printf("== %s ==\n", nome_cat[v[i].cat]);
        }
        printf("  %-18s R$ %8.2f  x%2d\n", v[i].nome, v[i].preco, v[i].estoque);
        grupo += v[i].preco * v[i].estoque;
        if (i == n - 1 || v[i + 1].cat != v[i].cat) {
            printf("  Estoque: R$ %.2f\n", grupo);
            grupo = 0;
        }
    }
    return 0;
}
