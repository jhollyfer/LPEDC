// 0031 · Aleatórios
// Exercício E185 · ★★★

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int pontos = 1000000;
    int dentro = 0;

    srand(42);
    for (int i = 0; i < pontos; i++) {
        double x = (double) rand() / RAND_MAX; // de 0.0 a 1.0
        double y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            dentro++;
        }
    }
    printf("Dentro do círculo: %d de %d\n", dentro, pontos);
    printf("pi ~ %.4f\n", 4.0 * dentro / pontos);
    return 0;
}
