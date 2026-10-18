// 0022 · For
// Exercício E132 · ★★★

#include <stdio.h>

int main(void) {
    int i, j;
    int voltas = 0;

    for (i = 0, j = 20; i < j; i += 3, j -= 2) {
        printf("i = %2d, j = %2d\n", i, j);
        voltas++;
    }
    printf("Fim: i = %d, j = %d, voltas = %d\n", i, j, voltas);

    // a mesma coisa com while
    i = 0;
    j = 20;
    voltas = 0;
    while (i < j) {
        printf("i = %2d, j = %2d\n", i, j);
        voltas++;
        i += 3;
        j -= 2;
    }
    printf("Fim: i = %d, j = %d, voltas = %d\n", i, j, voltas);
    return 0;
}
