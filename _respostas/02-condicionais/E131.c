// 0022 · Ternário: condição ? a : b
// Exercício E131 · ★★★
//
// Resposta: o ?: tem precedência menor que o + e o >=. O C lê
// (subtotal + subtotal >= 199) ? 0.0 : 19.90; com 150, 300 >= 199 é verdade
// e o total vira 0.0. O ternário inteiro precisa de parênteses.

#include <stdio.h>

int main(void) {
    double subtotal;
    printf("Subtotal: ");
    if (scanf("%lf", &subtotal) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double total = subtotal + (subtotal >= 199 ? 0.0 : 19.90);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
