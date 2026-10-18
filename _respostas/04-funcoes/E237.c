// 0040 · Pré-processador: macros e #ifdef
// Exercício E237 · ★★☆
//
// Resposta: (1) "#define DESCONTO 0.10;" leva o ";" junto: o printf vira
// printf("...", preco * 0.10;) e o compilador reclama "expected ')' before ';'"
// numa linha que parece certa. (2) "#define PRECO_COMBO 25 + 5" faz
// 2.0 * PRECO_COMBO virar 2.0 * 25 + 5 = 55. Com parênteses, (25 + 5), dá 60.

#include <stdio.h>

#define DESCONTO 0.10
#define PRECO_COMBO (25 + 5)

int main(void) {
    double preco = 35.00;

    printf("Desconto: R$ %.2f\n", preco * DESCONTO);
    printf("Dois combos: R$ %.2f\n", 2.0 * PRECO_COMBO);
    return 0;
}
