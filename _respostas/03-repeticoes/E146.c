// 0025 · While
// Exercício E146 · ★☆☆

#include <stdio.h>

int main(void) {
    int multiplo = 7;

    while (multiplo < 50) {
        printf("%d ", multiplo);
        multiplo += 7;
    }
    printf("\n");
    return 0;
}
