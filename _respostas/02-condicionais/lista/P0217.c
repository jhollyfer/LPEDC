// Lista · Módulo 02 · Decisões
// Exercício P0217 · ★★☆ · A bandeira 2 do táxi

#include <stdio.h>

int main(void) {
    int dia = 3;      // 0 = domingo
    int hora = 21;
    double km = 8.5;

    int bandeira = (dia == 0 || hora >= 20 || hora < 6) ? 2 : 1;
    double por_km = bandeira == 2 ? 3.84 : 3.20;

    printf("Bandeira %d\n", bandeira);
    printf("Corrida de %.1f km: R$ %.2f\n", km, 5.50 + km * por_km);
    return 0;
}
