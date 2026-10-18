// 0042 · Vetores
// Exercício E248 · ★☆☆
//
// Resposta:
//   2 0   a[1] é 2; a[3] não foi informado, então vale 0
//   3     b tem 3 itens (12 bytes / 4 bytes)
//   8     i % 3 = 1, e b[1] = 8
//   9     a[4] = 0 (não informado) + b[2] = 9
//   15    b[0] = 7 + 8

#include <stdio.h>

int main(void) {
    int a[5] = {4, 2};
    int b[] = {7, 8, 9};
    int i = 4;

    printf("%d %d\n", a[1], a[3]);
    printf("%zu\n", sizeof(b) / sizeof(b[0]));
    printf("%d\n", b[i % 3]);
    printf("%d\n", a[i] + b[2]);
    b[0] = b[0] + b[1];
    printf("%d\n", b[0]);
    return 0;
}
