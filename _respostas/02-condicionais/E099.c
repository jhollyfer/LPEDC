// 0017 · Ternário: condição ? a : b
// Exercício E099 · ★★☆

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Dois números: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    printf("Distância: %d\n", a > b ? a - b : b - a);
    printf("Soma: %s\n", (a + b) % 2 ? "ímpar" : "par");
    printf("Menor: %d\n", a < b ? a : b);
    printf("%d por %d: %s\n", a, b,
           b == 0 ? "não dá para dividir por zero"
                  : a % b == 0 ? "divisível" : "não divisível");
    return 0;
}
