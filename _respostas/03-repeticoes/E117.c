// 0020 · While
// Exercício E117 · ★★☆

#include <stdio.h>

int main(void) {
    int litros = 1000;
    int consumo = 180;
    int dias = 0;

    while (litros >= consumo) {
        litros = litros - consumo;
        dias++;
    }
    printf("Dá para %d dias. Sobram %d litros.\n", dias, litros);
    return 0;
}
