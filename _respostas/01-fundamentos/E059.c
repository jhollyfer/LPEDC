// 0010 · printf
// Exercício E059 · ★★★

#include <stdio.h>

int main(void) {
    int r = 30;
    int g = 144;
    int b = 255;

    printf("#%02X%02X%02X\n", r, g, b);
    printf("rgb(%d, %d, %d)\n", r, g, b);

    // o teste com componentes pequenos: sem o 02, sairia #080F
    int r2 = 0;
    int g2 = 8;
    int b2 = 15;
    printf("#%02X%02X%02X\n", r2, g2, b2);
    return 0;
}
