// 0047 · Ponteiros e vetores
// Exercício E280 · ★★☆
//
// Resposta: (1) com p em estoque[1], p[3] é estoque[4]; o certo é p[2]
// (índice relativo a p). (2) q <= estoque + 5 lê depois do fim; o certo é
// q < estoque + 5.

#include <stdio.h>

int main(void) {
    int estoque[5] = {12, 8, 15, 4, 9};
    int *p = estoque;

    p += 1;
    p[2] = 20;

    for (int *q = estoque; q < estoque + 5; q++) {
        printf("%d ", *q);
    }
    printf("\n");
    return 0;
}
