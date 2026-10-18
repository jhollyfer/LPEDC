// 0014 · Atribuição, ++ e --
// Exercício E080 · ★☆☆
//
// Resposta (teste de mesa):
//   instrução      x   y   z   w
//   int x = 5;     5
//   int y = x++;   6   5
//   int z = ++x;   7   5   7
//   int w = x--;   6   5   7   7
// Final: x = 6, y = 5, z = 7, w = 7.

#include <stdio.h>

int main(void) {
    int x = 5;
    int y = x++;
    int z = ++x;
    int w = x--;
    printf("x = %d, y = %d, z = %d, w = %d\n", x, y, z, w);
    return 0;
}
