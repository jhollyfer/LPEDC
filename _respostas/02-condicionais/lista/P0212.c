// Lista · Módulo 02 · Decisões
// Exercício P0212 · ★★☆ · A integração do ônibus

#include <stdio.h>

int main(void) {
    int h1 = 7, m1 = 40;
    int h2 = 9, m2 = 25;
    const double PASSAGEM = 4.50;

    int intervalo = (h2 * 60 + m2) - (h1 * 60 + m1);
    printf("Intervalo: %d min\n", intervalo);

    if (intervalo <= 120) {
        printf("Integração: a segunda viagem sai por R$ %.2f\n", 0.0);
    } else {
        printf("Sem integração: a segunda viagem custa R$ %.2f\n", PASSAGEM);
    }
    return 0;
}
