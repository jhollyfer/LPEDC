// 0032 · Recursão
// Exercício E192 · ★★★

#include <stdio.h>

int multiplicar(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + multiplicar(a, b - 1);
    }
    return multiplicar(a, b + 1) - a; // b negativo: sobe até 0
}

int main(void) {
    printf("7 x 4 = %d\n", multiplicar(7, 4));
    printf("7 x -3 = %d\n", multiplicar(7, -3));
    printf("-5 x 6 = %d\n", multiplicar(-5, 6));
    printf("9 x 0 = %d\n", multiplicar(9, 0));
    return 0;
}
