// 0022 · For
// Exercício E132 · ★★★
//
// Resposta: 4 linhas: (0, 20), (3, 18), (6, 16), (9, 14); depois
// "Fim: i = 12, j = 12". A versão com while vem logo depois e mostra o mesmo.

#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 0, j = 20; i < j; i += 3, j -= 2) {
        printf("i = %2d, j = %2d\n", i, j);
    }
    printf("Fim: i = %d, j = %d\n", i, j);

    // a mesma coisa com while
    i = 0;
    j = 20;
    while (i < j) {
        printf("i = %2d, j = %2d\n", i, j);
        i += 3;
        j -= 2;
    }
    printf("Fim: i = %d, j = %d\n", i, j);
    return 0;
}
