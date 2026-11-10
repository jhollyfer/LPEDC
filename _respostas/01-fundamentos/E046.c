// 0008 · Conversão e cast
// Exercício E046 · ★★☆

#include <stdio.h>

int main(void) {
    int gramas = 600;
    double preco_kg = 45.90;

    double preco = gramas / 1000.0 * preco_kg;

    printf("%d g: R$ %.2f\n", gramas, preco);
    return 0;
}
