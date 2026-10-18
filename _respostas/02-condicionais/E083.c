// 0014 · if
// Exercício E083 · ★★★
//
// Sem chaves, os printf de "Pedir mais pão." e "Desligar a vitrine." ficavam
// fora dos if e rodavam sempre. Com chaves, cada bloco é do seu if.

#include <stdio.h>

int main(void) {
    int estoque;
    printf("Pães no estoque: ");
    if (scanf("%d", &estoque) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (estoque < 10) {
        printf("Estoque baixo.\n");
        printf("Pedir mais pão.\n");
    }
    if (!estoque) {
        printf("Esgotado!\n");
        printf("Desligar a vitrine.\n");
    }
    if (estoque > 100) {
        printf("Excesso: %d pães acima do ideal.\n", estoque - 100);
    }
    printf("Estoque: %d\n", estoque);
    return 0;
}
