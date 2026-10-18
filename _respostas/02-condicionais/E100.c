// 0017 · Ternário: condição ? a : b
// Exercício E100 · ★★☆

#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Notas: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    int maior = a > b ? a : b;
    maior = c > maior ? c : maior;
    printf("Maior nota: %d\n", maior);
    return 0;
}
