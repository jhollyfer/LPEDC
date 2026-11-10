// Lista · Módulo 01 · Fundamentos de C
// Exercício P0128 · ★★★ · De Manaus a Belém em linha reta
//
// A distância em linha reta entre dois pontos da Terra sai da fórmula de
// haversine. Com as latitudes e longitudes em radianos, faça
// a = sin²(Δlat/2) + cos(lat1)·cos(lat2)·sin²(Δlon/2) e
// d = 2 · R · asin(√a), com R = 6371 km. Manaus fica em (−3.1190, −60.0217) e
// Belém em (−1.4558, −48.4902), em graus. Escreva um programa, com
// #define PI 3.14159265358979, que mostre a distância arredondada para km:
//
//   Saída esperada:
//   Manaus: -3.1190, -60.0217
//   Belém: -1.4558, -48.4902
//   Distância: 1294 km
//
// Dicas:
// 1. Para converter graus em radianos: graus * PI / 180. sin, cos, asin e
//    sqrt estão no math.h.
// 2. sin² de x é sin(x) * sin(x), ou pow(sin(x), 2).
// 3. Mostre com %.0f. Resposta esperada: Distância: 1294 km.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
