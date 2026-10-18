// 0052 · Ponteiros e vetores
// Exercício E307 · ★☆☆

#include <stdio.h>

int main(void) {
    float notas[4] = {7.5f, 8.0f, 6.5f, 9.0f};
    float soma = 0;

    for (const float *p = notas; p < notas + 4; p++) {
        printf("%.1f ", *p);
        soma += *p;
    }
    printf("\nMédia: %.2f\n", soma / 4);
    return 0;
}
