// 0030 · Escopo e tempo de vida
// Exercício E177 · ★★☆

#include <stdio.h>

double preco_item(int i) {
    if (i == 1) {
        return 12.50;
    }
    if (i == 2) {
        return 8.00;
    }
    if (i == 3) {
        return 30.00;
    }
    return 4.75;
}

int main(void) {
    double total = 0;
    for (int i = 1; i <= 4; i++) {
        total += preco_item(i);
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
