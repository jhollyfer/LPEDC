// Lista · Módulo 01 · Fundamentos de C
// Exercício P0126 · ★★★ · Previsão da maratona

#include <math.h>
#include <stdio.h>

int main(void) {
    double t1 = 50 * 60.0;  // 10 km em 50 min
    double d1 = 10.0, d2 = 42.195;

    int t2 = (int)round(t1 * pow(d2 / d1, 1.06));
    int pace = (int)(t2 / d2);

    printf("Previsão: %d s\n", t2);
    printf("Maratona em %d:%02d:%02d\n", t2 / 3600, t2 % 3600 / 60, t2 % 60);
    printf("Pace previsto: %d:%02d por km\n", pace / 60, pace % 60);
    return 0;
}
