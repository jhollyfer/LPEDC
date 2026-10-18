// 0060 · Typedef
// Exercício E355 · ★☆☆
//
// O programa abaixo funciona, mas repete "struct produto" em todo lugar.
// Refatore: crie o apelido Produto com typedef e troque todas as ocorrências.
// A saída não pode mudar.
//
//   Saída esperada:
//   Café: 3 x R$ 12.50 = R$ 37.50
//   Leite: 6 x R$ 4.99 = R$ 29.94
//   Total: R$ 67.44
//
// Dicas:
// 1. Dá para fazer typedef struct produto Produto; logo depois da struct.
// 2. Ou junte tudo: typedef struct { ... } Produto;
// 3. Resposta esperada: a mesma saída, sem nenhum "struct produto" no main
//    nem nas funções.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

struct produto {
    char nome[20];
    int quantidade;
    double preco;
};

double subtotal(struct produto p) {
    return p.quantidade * p.preco;
}

void mostrar(struct produto p) {
    printf("%s: %d x R$ %.2f = R$ %.2f\n", p.nome, p.quantidade, p.preco, subtotal(p));
}

int main(void) {
    struct produto cafe = {"Café", 3, 12.50};
    struct produto leite = {"Leite", 6, 4.99};

    mostrar(cafe);
    mostrar(leite);
    printf("Total: R$ %.2f\n", subtotal(cafe) + subtotal(leite));
    return 0;
}
