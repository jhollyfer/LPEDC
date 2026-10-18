// 0014 · if
// Exercício E082 · ★★☆

#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Orçamentos: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    int maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    printf("Maior orçamento: R$ %d\n", maior);
    return 0;
}
