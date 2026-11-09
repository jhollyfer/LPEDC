// Lista · Módulo 01 · Fundamentos de C
// Exercício P0107 · ★☆☆ · Os cocos da feira

#include <math.h>
#include <stdio.h>

int main(void) {
    double total = 3 * 7.99;

    printf("Total: R$ %.2f\n", total);
    printf("(int):  %d\n", (int)total);
    printf("round:  %.0f\n", round(total));
    printf("floor:  %.0f\n", floor(total));
    printf("ceil:   %.0f\n", ceil(total));
    return 0;
}
