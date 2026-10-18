// 0022 · Ternário: condição ? a : b
// Exercício E131 · ★★★
//
// O total da compra deveria ser o subtotal mais o frete (R$ 19.90 abaixo de
// R$ 199, grátis a partir disso). Com subtotal 150, o programa mostra
// "Total: R$ 0.00"! Compila sem nenhum aviso. Explique o que o C entende
// nessa linha e conserte.
//
// Dicas:
// 1. Quem é feito primeiro: o +, o >= ou o ?: ?
// 2. Monte os parênteses que o C coloca sozinho.
// 3. Resposta esperada: o C lê (subtotal + subtotal >= 199) ? 0.0 : 19.90,
//    e 300 >= 199 dá 0.0. O certo é
//    subtotal + (subtotal >= 199 ? 0.0 : 19.90). Consertado: 150 → 169.90;
//    250 → 250.00.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    double subtotal;
    printf("Subtotal: ");
    if (scanf("%lf", &subtotal) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double total = subtotal + subtotal >= 199 ? 0.0 : 19.90;
    printf("Total: R$ %.2f\n", total);
    return 0;
}
