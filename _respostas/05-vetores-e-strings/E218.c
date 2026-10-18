// 0037 · Vetores
// Exercício E218 · ★☆☆

#include <stdio.h>

int main(void) {
    int a[5] = {4, 2};
    int b[] = {7, 8, 9};

    for (int i = 0; i < 5; i++) {
        printf(i == 0 ? "a[%d]=%d" : " a[%d]=%d", i, a[i]);
    }
    printf("\n");

    printf("b tem %zu itens\n", sizeof(b) / sizeof(b[0]));

    printf("De 4 a 8:");
    for (int i = 4; i <= 8; i++) {
        printf(" %d", b[i % 3]);
    }
    printf("\n");

    b[0] = b[0] + b[1];
    printf("Novo b[0]: %d\n", b[0]);
    return 0;
}
