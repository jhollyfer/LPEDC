// Lista · Módulo 03 · Laços
// Exercício P0312 · ★★☆ · Os dois ônibus no mesmo ponto

#include <stdio.h>

int main(void) {
    int a = 12, b = 18;

    int mmc = a;
    while (mmc % b != 0) {
        mmc += a;
    }
    printf("Saem juntos a cada %d minutos\n", mmc);

    for (int k = 1; k <= 3; k++) {
        int t = 6 * 60 + k * mmc;
        printf("%02d:%02d\n", t / 60, t % 60);
    }
    return 0;
}
