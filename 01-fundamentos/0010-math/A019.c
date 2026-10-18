// A019 · A escada no muro e o posto na estrada

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

int main(void) {
    // sin e cos trabalham em radianos: converta com graus * PI / 180
    double escada = 5.0;            // metros
    double graus = 60.0;            // ângulo da escada com o chão
    double radianos = graus * PI / 180;
    printf("Altura no muro: %.2f m\n", escada * sin(radianos));
    printf("Pé da escada a %.2f m do muro\n", escada * cos(radianos));

    // fmod: o resto de uma divisão entre reais (o % só aceita inteiros)
    double km = 31.0, entre_postos = 7.5;
    double desde_ultimo = fmod(km, entre_postos);   // 31 - 4 * 7.5 = 1.0
    printf("Último posto há %.1f km; próximo em %.1f km\n",
           desde_ultimo, entre_postos - desde_ultimo);

    // fabs: a distância entre dois valores, não importa a ordem da conta
    double tarde = 14.5, madrugada = -3.0;
    printf("Variação no dia: %.1f graus\n", fabs(madrugada - tarde));
    return 0;
}
// Saída:
// Altura no muro: 4.33 m
// Pé da escada a 2.50 m do muro
// Último posto há 1.0 km; próximo em 6.5 km
// Variação no dia: 17.5 graus
