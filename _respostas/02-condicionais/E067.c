// 0012 · Relacionais e a verdade em C
// Exercício E067 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double etanol, gasolina;
    scanf("%lf", &etanol);
    scanf("%lf", &gasolina);

    bool compensa = etanol <= gasolina * 0.7;
    printf("Etanol compensa? %d\n", compensa);
    return 0;
}
