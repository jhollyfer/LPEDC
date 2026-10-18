// 0050 · Ponteiros
// Exercício E295 · ★☆☆

#include <stdio.h>

int main(void) {
    double temperatura = 22.5;
    double *pt = &temperatura;

    printf("Pelo ponteiro: %.1f\n", *pt);
    *pt += 1.5;
    printf("Pelo ponteiro: %.1f\n", *pt);
    printf("Pela variável: %.1f\n", temperatura);
    return 0;
}
