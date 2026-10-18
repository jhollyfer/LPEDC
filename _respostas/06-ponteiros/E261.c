// 0044 · Memória e endereços
// Exercício E261 · ★★☆
//
// Resposta: os endereços sobem de 8 em 8 (um double tem 8 bytes) e
// precos[1][0] começa logo depois de precos[0][2]: a matriz é contígua.

#include <stdio.h>

int main(void) {
    double precos[2][3] = {{6.0, 7.5, 8.0}, {9.0, 11.0, 12.5}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("precos[%d][%d] = %.2f em %p\n", i, j, precos[i][j], (void *)&precos[i][j]);
        }
    }
    return 0;
}
