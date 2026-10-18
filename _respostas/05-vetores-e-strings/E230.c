// 0039 · Matrizes
// Exercício E230 · ★☆☆

#include <stdio.h>

int main(void) {
    int a[2][3] = {{1}, {4, 5}};
    int b[][2] = {{1, 2}, {3, 4}, {5}};
    int linhas_b = (int) (sizeof(b) / sizeof(b[0]));

    printf("a (2x3):\n");
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 3; c++) {
            printf(c == 0 ? "%d" : " %d", a[l][c]);
        }
        printf("\n");
    }

    printf("b (%d linhas):\n", linhas_b);
    for (int l = 0; l < linhas_b; l++) {
        printf("%d %d\n", b[l][0], b[l][1]);
    }

    printf("a: %zu bytes, uma linha: %zu bytes\n", sizeof(a), sizeof(a[0]));
    return 0;
}
