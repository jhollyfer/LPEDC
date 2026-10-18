// 0024 · Laços aninhados
// Exercício E140 · ★☆☆

#include <stdio.h>

int main(void) {
    int vezes = 0;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i * j);
            vezes++;
        }
        printf("\n");
    }
    printf("printf de dentro: %d vezes\n", vezes);
    return 0;
}
