// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E223 · ★☆☆

#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

void simplificar(int a, int b) {
    int m = mdc(a, b);
    printf("mdc(%d, %d) = %d -> %d/%d = %d/%d\n", a, b, m, a, b, a / m, b / m);
}

int main(void) {
    simplificar(84, 36);
    simplificar(1000, 625);
    return 0;
}
