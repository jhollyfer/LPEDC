// 0012 · Relacionais e a verdade em C
// Exercício E068 · ★☆☆
//
// Resposta: 1 1 0 1 0 1
// (4 > -2 sim; 4 == 4 sim; -2 >= 0 não; 2.5 < 3 sim; 4 != 4 não;
// 'b' (98) > 'a' (97) sim.)

#include <stdio.h>

int main(void) {
    int i = 4, j = -2;
    double x = 2.5;
    printf("%d ", i > j);
    printf("%d ", i == 4);
    printf("%d ", j >= 0);
    printf("%d ", x < 3);
    printf("%d ", i != 2 * 2);
    printf("%d\n", 'b' > 'a');
    return 0;
}
