// 0024 · Laços aninhados
// Exercício E141 · ★★☆

#include <stdio.h>

int main(void) {
    printf("  x |");
    for (int coluna = 1; coluna <= 9; coluna++) {
        printf("%4d", coluna);
    }
    printf("\n----+");
    for (int coluna = 1; coluna <= 9; coluna++) {
        printf("----");
    }
    printf("\n");

    for (int linha = 1; linha <= 9; linha++) {
        printf("%3d |", linha);
        for (int coluna = 1; coluna <= 9; coluna++) {
            printf("%4d", linha * coluna);
        }
        printf("\n");
    }
    return 0;
}
