// Lista · Módulo 02 · Decisões
// Exercício P0207 · ★☆☆ · O radar da avenida

#include <stdio.h>

int main(void) {
    int velocidade;

    printf("Velocidade (km/h): ");
    scanf("%d", &velocidade);

    if (velocidade <= 60) {
        printf("Dentro do limite.\n");
    } else if (velocidade <= 72) {
        printf("Infração média: R$ 130.16\n");
    } else if (velocidade <= 90) {
        printf("Infração grave: R$ 195.23\n");
    } else {
        printf("Infração gravíssima: R$ 880.41\n");
    }
    return 0;
}
