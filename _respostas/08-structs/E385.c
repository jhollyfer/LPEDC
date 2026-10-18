// 0065 · Typedef
// Exercício E385 · ★☆☆

#include <stdio.h>

typedef struct {
    char nome[20];
    int quantidade;
    double preco;
} Produto;

double subtotal(Produto p) {
    return p.quantidade * p.preco;
}

void mostrar(Produto p) {
    printf("%s: %d x R$ %.2f = R$ %.2f\n", p.nome, p.quantidade, p.preco, subtotal(p));
}

int main(void) {
    Produto cafe = {"Café", 3, 12.50};
    Produto leite = {"Leite", 6, 4.99};

    mostrar(cafe);
    mostrar(leite);
    printf("Total: R$ %.2f\n", subtotal(cafe) + subtotal(leite));
    return 0;
}
