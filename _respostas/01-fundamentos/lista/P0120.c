// Lista · Módulo 01 · Fundamentos de C
// Exercício P0120 · ★★☆ · A média da ida e volta

#include <stdio.h>

int main(void) {
    double trecho = 120.0;
    double vel_ida = 60.0, vel_volta = 40.0;

    double t_ida = trecho / vel_ida;
    double t_volta = trecho / vel_volta;
    double t_total = t_ida + t_volta;

    printf("Ida: %.1f h\n", t_ida);
    printf("Volta: %.1f h\n", t_volta);
    printf("Total: %.0f km em %.1f h\n", 2 * trecho, t_total);
    printf("Velocidade média: %.1f km/h\n", 2 * trecho / t_total);
    return 0;
}
