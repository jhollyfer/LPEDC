// 0016 · else if, if aninhado e o else pendurado
// Exercício E095 · ★★★

#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Lados: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (a >= b + c || b >= a + c || c >= a + b) {
        printf("Não forma triângulo.\n");
    } else if (a == b && b == c) {
        printf("Triângulo equilátero.\n");
    } else if (a == b || b == c || a == c) {
        printf("Triângulo isósceles.\n");
    } else {
        printf("Triângulo escaleno.\n");
    }
    return 0;
}
