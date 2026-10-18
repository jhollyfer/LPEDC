// 0026 · Do-while
// Exercício E153 · ★★☆

#include <stdio.h>

int main(void) {
    double preco;
    double total = 0.0;
    int itens = 0;
    char resposta;

    do {
        printf("Preço: ");
        if (scanf("%lf", &preco) != 1) {
            return 1;
        }
        total = total + preco;
        itens++;
        printf("Mais algum item? (s/n) ");
        if (scanf(" %c", &resposta) != 1) {
            resposta = 'n';
        }
    } while (resposta == 's' || resposta == 'S');

    printf("Itens: %d\n", itens);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
