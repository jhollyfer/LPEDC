// 0004 · Constantes
// Exercício E021 · ★★☆

#include <stdio.h>

#define MENSALIDADE 89.90
#define DESCONTO 10.00

int main(void) {
    const int dia = 10;

    printf("Mensalidade: R$ %.2f\n", MENSALIDADE);
    printf("Desconto: R$ %.2f\n", DESCONTO);
    printf("Vencimento: dia %d\n", dia);
    return 0;
}
