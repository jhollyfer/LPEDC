// 0026 · Aleatórios
// Exercício E154 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 10; i++) {
        int dado = 1 + rand() % 6;
        printf("%d ", dado);
    }
    printf("\n");
    return 0;
}
