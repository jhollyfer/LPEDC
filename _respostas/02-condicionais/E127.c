// 0022 · Ternário: condição ? a : b
// Exercício E127 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double preco = idade >= 18 ? 40.0 : 20.0;
    printf("Ingresso: R$ %.2f\n", preco);
    return 0;
}
