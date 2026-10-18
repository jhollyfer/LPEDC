// 0022 · For
// Exercício E128 · ★☆☆

#include <stdio.h>

int main(void) {
    int voltas;

    printf("a) ");
    voltas = 0;
    for (int x = 3; x <= 20; x += 4) {
        printf("%d ", x);
        voltas++;
    }
    printf("(%d voltas)\n", voltas);

    printf("b) ");
    voltas = 0;
    for (int x = 50; x > 30; x -= 6) {
        printf("%d ", x);
        voltas++;
    }
    printf("(%d voltas)\n", voltas);

    printf("c) ");
    voltas = 0;
    for (int x = 1; x >= 10; x++) {
        printf("%d ", x);
        voltas++;
    }
    printf("(%d voltas)\n", voltas);

    printf("d) ");
    voltas = 0;
    for (int x = 1; x < 100; x *= 3) {
        printf("%d ", x);
        voltas++;
    }
    printf("(%d voltas)\n", voltas);
    return 0;
}
