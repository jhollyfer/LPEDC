// 0039 · Matrizes
// Exercício E230 · ★☆☆
//
// Resposta:
//   1 0 5    a = {{1, 0, 0}, {4, 5, 0}}
//   3        b tem 3 linhas (3 chaves internas)
//   3 0      b = {{1, 2}, {3, 4}, {5, 0}}
//   24 12    a tem 6 int (24 bytes); uma linha tem 3 int (12 bytes)

#include <stdio.h>

int main(void) {
    int a[2][3] = {{1}, {4, 5}};
    int b[][2] = {{1, 2}, {3, 4}, {5}};

    printf("%d %d %d\n", a[0][0], a[0][2], a[1][1]);
    printf("%zu\n", sizeof(b) / sizeof(b[0]));
    printf("%d %d\n", b[1][0], b[2][1]);
    printf("%zu %zu\n", sizeof(a), sizeof(a[1]));
    return 0;
}
