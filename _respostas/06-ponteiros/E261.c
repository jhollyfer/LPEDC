// 0044 · Memória e endereços
// Exercício E261 · ★★☆

#include <stdio.h>

int main(void) {
    double precos[2][3] = {{6.0, 7.5, 8.0}, {9.0, 11.0, 12.5}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("precos[%d][%d] = %.2f em %p\n", i, j, precos[i][j], (void *)&precos[i][j]);
        }
    }
    printf("uma posição: %zu bytes\n", sizeof precos[0][0]);
    printf("uma linha: %zu bytes\n", sizeof precos[0]);
    printf("a matriz: %zu bytes\n", sizeof precos);
    return 0;
}
