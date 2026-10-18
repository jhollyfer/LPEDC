// 0061 · Matriz dinâmica
// Exercício E362 · ★☆☆
//
// Resposta: a) 19; b) 39 = 5 * 8 - 1, a última das 40 posições; c) 5;
// d) (3, 2), porque 26 / 8 = 3 e 26 % 8 = 2.

#include <stdio.h>

int main(void) {
    int colunas = 8;
    printf("a) (2, 3) -> %d\n", 2 * colunas + 3);
    printf("b) (4, 7) -> %d\n", 4 * colunas + 7);
    printf("c) (0, 5) -> %d\n", 0 * colunas + 5);
    printf("d) 26 -> (%d, %d)\n", 26 / colunas, 26 % colunas);
    return 0;
}
// Saída:
// a) (2, 3) -> 19
// b) (4, 7) -> 39
// c) (0, 5) -> 5
// d) 26 -> (3, 2)
