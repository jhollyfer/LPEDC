// 0047 · Ponteiros e vetores
// Exercício E280 · ★★☆

#include <stdio.h>

int main(void) {
    int estoque[5] = {12, 8, 15, 4, 9};
    int *p = estoque;

    p += 1;
    p[2] = 20; // p[2] é estoque[3]

    for (int *q = estoque; q < estoque + 5; q++) {
        if (q > estoque) {
            printf(" ");
        }
        printf("%d", *q);
    }
    printf("\n");
    return 0;
}
