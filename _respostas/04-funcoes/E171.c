// 0029 · Parâmetros e passagem por valor
// Exercício E171 · ★★☆

#include <stdio.h>

int menor(int a, int b) {
    return a < b ? a : b;
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int a = 9;
    int b = 6;

    printf("Em ordem: %d e %d\n", menor(a, b), maior(a, b));
    return 0;
}
