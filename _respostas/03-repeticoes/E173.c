// 0029 · Laços aninhados
// Exercício E173 · ★★★

#include <stdio.h>

int main(void) {
    int altura;

    printf("Altura: ");
    if (scanf("%d", &altura) != 1 || altura < 1 || altura > 20) {
        printf("Altura de 1 a 20, por favor.\n");
        return 1;
    }

    for (int linha = 1; linha <= altura; linha++) {
        for (int esp = 1; esp <= altura - linha; esp++) {
            printf(" ");
        }
        for (int ast = 1; ast <= 2 * linha - 1; ast++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
