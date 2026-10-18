// 0031 · Aleatórios
// Exercício E181 · ★☆☆
//
// Resposta: a) 1 + rand() % 6; b) rand() % 10; c) 10 + rand() % 11;
// d) -5 + rand() % 11; e) 2 + 2 * (rand() % 10).

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    srand(1);

    printf("a) ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", 1 + rand() % 6);
    }
    printf("\nb) ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\nc) ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", 10 + rand() % 11);
    }
    printf("\nd) ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", -5 + rand() % 11);
    }
    printf("\ne) ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", 2 + 2 * (rand() % 10));
    }
    printf("\n");
    return 0;
}
