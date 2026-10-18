// 0128 · N-rainhas
// Exercício E763 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ataca(int l1, int c1, int l2, int c2) {
    return l1 == l2 || c1 == c2 || abs(l1 - l2) == abs(c1 - c2);
}

int main(void) {
    int pares[6][4] = {
        {0, 0, 3, 3}, {1, 2, 3, 1}, {2, 5, 2, 0},
        {4, 1, 1, 4}, {0, 3, 5, 3}, {6, 2, 3, 0},
    };
    for (int i = 0; i < 6; i++) {
        int *p = pares[i];
        printf("(%d, %d) e (%d, %d): %s\n", p[0], p[1], p[2], p[3],
               ataca(p[0], p[1], p[2], p[3]) ? "ataca" : "não ataca");
    }
    return 0;
}
