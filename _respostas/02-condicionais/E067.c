// 0012 · Relacionais e a verdade em C
// Exercício E067 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double etanol, gasolina;
    printf("Etanol: ");
    scanf("%lf", &etanol);
    printf("Gasolina: ");
    scanf("%lf", &gasolina);

    bool compensa = etanol <= gasolina * 0.7;
    printf("Etanol compensa? %d\n", compensa);
    return 0;
}
