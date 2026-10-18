// 0009 · Atribuição, ++ e --
// Exercício E050 · ★☆☆

#include <stdio.h>

int main(void) {
    int x = 5;
    int y = x++;   // entrega 5, depois x vira 6
    printf("y = x++ -> x = %d, y = %d\n", x, y);
    int z = ++x;   // x vira 7, depois entrega 7
    printf("z = ++x -> x = %d, z = %d\n", x, z);
    int w = x--;   // entrega 7, depois x vira 6
    printf("w = x-- -> x = %d, w = %d\n", x, w);
    return 0;
}
