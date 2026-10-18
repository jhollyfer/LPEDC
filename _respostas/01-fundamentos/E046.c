// 0008 · Conversão e cast
// Exercício E046 · ★★☆
//
// Resposta: gramas / 1000 é 600 / 1000 entre dois int: dá 0, e 0 * 45.90 é
// 0. Com 1000.0, a divisão vira real: 0.6 * 45.90 = 27.54.

#include <stdio.h>

int main(void) {
    int gramas = 600;
    double preco_kg = 45.90;

    double preco = gramas / 1000.0 * preco_kg;

    printf("%d g: R$ %.2f\n", gramas, preco);
    return 0;
}
