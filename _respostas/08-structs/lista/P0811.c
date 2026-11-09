// Lista · Módulo 08 · Tipos compostos
// Exercício P0811 · ★★☆ · O cardápio em duas ordens

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[24];
    double preco;
    int calorias;
} Item;

int por_nome(const void *pa, const void *pb) {
    const Item *a = pa, *b = pb;
    return strcmp(a->nome, b->nome);
}

int por_preco(const void *pa, const void *pb) {
    const Item *a = pa, *b = pb;
    if (a->preco != b->preco) {
        return (a->preco > b->preco) - (a->preco < b->preco);
    }
    return a->calorias - b->calorias;
}

void mostrar(const char *titulo, const Item *v, int n) {
    printf("%s\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("  R$ %5.2f %4d kcal  %s\n", v[i].preco, v[i].calorias, v[i].nome);
    }
}

int main(void) {
    Item cardapio[6] = {{"X-Caboquinho", 22.90, 780}, {"Tapioca", 12.00, 420},
                        {"Pastel de carne", 9.50, 510}, {"Açaí 500 ml", 18.00, 640},
                        {"Suco de cupuaçu", 8.00, 190}, {"Misto quente", 9.50, 380}};

    qsort(cardapio, 6, sizeof cardapio[0], por_nome);
    mostrar("Por nome:", cardapio, 6);
    qsort(cardapio, 6, sizeof cardapio[0], por_preco);
    mostrar("Por preço:", cardapio, 6);
    return 0;
}
