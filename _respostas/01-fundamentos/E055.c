// 0010 · math.h
// Exercício E055 · ★☆☆

#include <stdio.h>
#include <math.h>

int main(void) {
    double largura = 121.8, altura = 68.5; // cm

    double diagonal = sqrt(pow(largura, 2) + pow(altura, 2));

    printf("Diagonal: %.2f cm\n", diagonal);
    printf("TV de %.0f polegadas\n", diagonal / 2.54);
    return 0;
}
