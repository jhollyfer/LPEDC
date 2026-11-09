// Lista · Módulo 01 · Fundamentos de C
// Exercício P0128 · ★★★ · De Manaus a Belém em linha reta

#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979
#define RAIO_TERRA 6371.0

int main(void) {
    double lat1 = -3.1190, lon1 = -60.0217;  // Manaus
    double lat2 = -1.4558, lon2 = -48.4902;  // Belém

    double f1 = lat1 * PI / 180, f2 = lat2 * PI / 180;
    double dlat = (lat2 - lat1) * PI / 180;
    double dlon = (lon2 - lon1) * PI / 180;

    double a = pow(sin(dlat / 2), 2) + cos(f1) * cos(f2) * pow(sin(dlon / 2), 2);
    double d = 2 * RAIO_TERRA * asin(sqrt(a));

    printf("Manaus: %.4f, %.4f\n", lat1, lon1);
    printf("Belém: %.4f, %.4f\n", lat2, lon2);
    printf("Distância: %.0f km\n", d);
    return 0;
}
