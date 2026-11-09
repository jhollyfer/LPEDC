// Lista · Módulo 02 · Decisões
// Exercício P0210 · ★☆☆ · O drone na área liberada

#include <stdio.h>

int main(void) {
    int x = 150, y = 130;

    if (x >= 0 && x <= 200 && y >= 0 && y <= 120) {
        printf("Drone em (%d, %d): dentro da área\n", x, y);
    } else {
        printf("Drone em (%d, %d): fora da área\n", x, y);
    }

    x = 200;
    y = 45;
    if (x >= 0 && x <= 200 && y >= 0 && y <= 120) {
        printf("Drone em (%d, %d): dentro da área\n", x, y);
    } else {
        printf("Drone em (%d, %d): fora da área\n", x, y);
    }
    return 0;
}
