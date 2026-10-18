// 0059 · Struct
// Exercício E349 · ★☆☆

#include <stdio.h>

struct livro {
    char titulo[40];
    char autor[30];
    int ano;
    double preco;
};

int main(void) {
    struct livro l = {"Dom Casmurro", "Machado de Assis", 1899, 34.90};

    printf("Livro: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("Ano: %d\n", l.ano);
    printf("Preço: R$ %.2f\n", l.preco);
    printf("Na promoção: R$ %.2f\n", l.preco * 0.9);
    return 0;
}
