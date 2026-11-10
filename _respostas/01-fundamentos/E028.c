// 0005 · printf
// Exercício E028 · ★★☆

#include <stdio.h>

int main(void) {
    int quantidade = 3;
    double preco = 45.90;
    double total = quantidade * preco;

    printf("Pizzas: %d\n", quantidade);
    printf("Preço: R$ %.2f\n", preco);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
