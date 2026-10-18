// 0012 · Relacionais e a verdade em C
// Exercício E072 · ★★★

#include <stdio.h>

int main(void) {
    double total;
    printf("Total: R$ ");
    scanf("%lf", &total);

    int desconto = 5 * (total >= 100) + 5 * (total >= 300);
    double a_pagar = total * (100 - desconto) / 100;

    printf("Total: R$ %.2f\n", total);
    printf("Desconto: %d%%\n", desconto);
    printf("A pagar: R$ %.2f\n", a_pagar);
    return 0;
}
