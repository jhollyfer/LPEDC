// 0024 · Laços aninhados
// Exercício E144 · ★★★

#include <stdio.h>

int main(void) {
    int formas = 0;

    for (int n50 = 0; n50 <= 2; n50++) {
        for (int n20 = 0; n20 <= 5; n20++) {
            for (int n10 = 0; n10 <= 10; n10++) {
                if (50 * n50 + 20 * n20 + 10 * n10 == 100) {
                    formas++;
                    printf("%2d) %d de 50 + %d de 20 + %2d de 10\n", formas, n50, n20, n10);
                }
            }
        }
    }
    printf("Formas: %d\n", formas);
    return 0;
}
