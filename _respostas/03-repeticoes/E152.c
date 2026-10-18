// 0026 · Aleatórios
// Exercício E152 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int caras = 0;

    srand((unsigned) time(NULL));
    for (int i = 0; i < 20; i++) {
        if (rand() % 2 == 0) {
            printf("C ");
            caras++;
        } else {
            printf("K ");
        }
    }
    printf("\nCaras: %d | Coroas: %d\n", caras, 20 - caras);
    return 0;
}
