// 0027 · For
// Exercício E158 · ★☆☆
//
// Resposta: a) 3 7 11 15 19; b) 50 44 38 32; c) nada (zero voltas);
// d) 1 3 9 27 81 (o passo pode ser qualquer conta, não só +1).

#include <stdio.h>

int main(void) {
    printf("a) ");
    for (int x = 3; x <= 20; x += 4) {
        printf("%d ", x);
    }
    printf("\nb) ");
    for (int x = 50; x > 30; x -= 6) {
        printf("%d ", x);
    }
    printf("\nc) ");
    for (int x = 1; x >= 10; x++) {
        printf("%d ", x);
    }
    printf("\nd) ");
    for (int x = 1; x < 100; x *= 3) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
